#ifndef DS_DUAL_WOOD_H
#define	DS_DUAL_WOOD_H

#define DS_SELECT			bit_test(DS_data[6],0)
#define DS_L3				bit_test(DS_data[6],1)
#define DS_R3				bit_test(DS_data[6],2)
#define DS_START			bit_test(DS_data[6],3)
#define DS_UP				bit_test(DS_data[6],4)
#define DS_RIGHT			bit_test(DS_data[6],5)
#define DS_DOWN             bit_test(DS_data[6],6)
#define DS_LEFT             bit_test(DS_data[6],7)
#define DS_L2				bit_test(DS_data[7],0)
#define DS_R2				bit_test(DS_data[7],1)
#define DS_L1				bit_test(DS_data[7],2)
#define DS_R1				bit_test(DS_data[7],3)
#define DS_SANKAKU			bit_test(DS_data[7],4)
#define DS_MARU             bit_test(DS_data[7],5)
#define DS_BATU             bit_test(DS_data[7],6)
#define DS_SHIKAKU			bit_test(DS_data[7],7)

#define DS_SELECT_PUSH		bit_test(push_DS_data[0],0)
#define DS_L3_PUSH			bit_test(push_DS_data[0],1)
#define DS_R3_PUSH			bit_test(push_DS_data[0],2)
#define DS_START_PUSH		bit_test(push_DS_data[0],3)
#define DS_UP_PUSH			bit_test(push_DS_data[0],4)
#define DS_RIGHT_PUSH		bit_test(push_DS_data[0],5)
#define DS_DOWN_PUSH		bit_test(push_DS_data[0],6)
#define DS_LEFT_PUSH		bit_test(push_DS_data[0],7)
#define DS_L2_PUSH			bit_test(push_DS_data[1],0)
#define DS_R2_PUSH			bit_test(push_DS_data[1],1)
#define DS_L1_PUSH			bit_test(push_DS_data[1],2)
#define DS_R1_PUSH			bit_test(push_DS_data[1],3)
#define DS_SANKAKU_PUSH     bit_test(push_DS_data[1],4)
#define DS_MARU_PUSH		bit_test(push_DS_data[1],5)
#define DS_BATU_PUSH		bit_test(push_DS_data[1],6)
#define DS_SHIKAKU_PUSH     bit_test(push_DS_data[1],7)

#define DS_battery          DS_data[3]
#define DS_L2_ANALOG        DS_data[4]
#define DS_R2_ANALOG        DS_data[5]
#define DS_RIGHT_LR         DS_data[8]
#define DS_RIGHT_UD         DS_data[9]
#define DS_LEFT_LR          DS_data[10]
#define DS_LEFT_UD          DS_data[11]

#define DS2_connect         DS_data[1]==0xcb
#define DS3_connect         DS_data[1]==0x00

//FLAG_LRは右が1、左が0
//FLAG_UDは下が1、上が0
#define DS_RIGHT_LR_FLAG    DS_data[8]>>7
#define DS_RIGHT_UD_FLAG    DS_data[9]>>7
#define DS_LEFT_LR_FLAG     DS_data[10]>>7
#define DS_LEFT_UD_FLAG     DS_data[11]>>7  

#define DS_data_ookisa         13

char DS_uart_number=0;
char DS_read_stop=0;
char DS_time_out=100;
char sinyounai_DS_data[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
char DS_data[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
char push_DS_data[2]={0,0};
char before_DS_data[2]={255,255};

//通信切換え
int DS_communication_error_time=0;

//プロトタイプ宣言
void read_ds_dual_init();
void read_ds_dual_byte();
void read_ds_dual_de_gozaru();
void GOOD_de_gozaru();
void BAD_de_gozaru();
void always_de_gozaru();

//VALUEは0から7
char DS_RIGHT_LR_VALUE();
char DS_RIGHT_UD_VALUE();
char DS_LEFT_LR_VALUE();
char DS_LEFT_UD_VALUE();

//VALUEは-127から127 右、上が正
signed int DS_RIGHT_LR_signed_VALUE();
signed int DS_RIGHT_UD_signed_VALUE();
signed int DS_LEFT_LR_signed_VALUE();
signed int DS_LEFT_UD_signed_VALUE();
//スティックの中心からの距離
unsigned int DS_RIGHT_DISTANCE_VALUE();
unsigned int DS_LEFT_DISTANCE_VALUE();

//便利な関数
unsigned int approx_distance(signed int dx,signed int dy);

void read_ds_dual_init(){
	//タイマー0初期設定
	TIMER0_setup(T0_16BIT | T0_SOURCE_FOSC4 | T0_PRESCALER_8);
	TIMER0_16bit_set_count(25536);
    
    //通信切換え初期設定
    //CHANGE_COMMUNICATION_PIN=0;
    
    //UART通信初期設定
    Serial1_begin(57600,SERIAL_NON_INVERT);//57600 -0.08%
    TX1STAbits.TXEN=0;
	//割り込み許可
	enable_interrupts(INT_Serial1);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(INT_GLOBAL);
}

void read_ds_dual_byte(){
    if(DS_read_stop==0){
        sinyounai_DS_data[DS_uart_number]=Serial1_read();
        if(DS_uart_number==1 && sinyounai_DS_data[DS_uart_number]==0x0D){	//2バイト目が1バイト目のデータだった時
            DS_uart_number=1;
        }else if((DS_uart_number==0 && sinyounai_DS_data[0]!=0x0D)||(DS_uart_number==1 && sinyounai_DS_data[1]!=0x00 && sinyounai_DS_data[1]!=0xCB)){//識別子でない
            DS_uart_number=0;
        }else{																		//普通に受信
            DS_uart_number++;
            if(DS_uart_number>(DS_data_ookisa-1)){
                DS_read_stop=1;
            }
        }
    }else{
        Serial1_read();
    }
}

void read_ds_dual_de_gozaru(){
	static char read_number;
	static char mode=0;
	static char check_sum;
    static char first_communication=1;
	if(DS_read_stop){
		DS_time_out=0;
		switch(mode){											//先頭識別子
			case 0:
				DS_data[0]=sinyounai_DS_data[0];
				read_number=1;
				check_sum=0x0d;
				mode=1;
				break;
			case 1:												//ふつうに受信
				DS_data[read_number]=sinyounai_DS_data[read_number];
				check_sum+=DS_data[read_number];
				read_number++;
				if(read_number>DS_data_ookisa-2){
					mode=2;
				}
				break;
			case 2:												//チェックサム
				DS_data[read_number]=sinyounai_DS_data[read_number];
				DS_uart_number=0;
				DS_read_stop=0;
				mode=0;
				if(DS_data[read_number]==check_sum){				//チェックサムOK
					push_DS_data[0]=~before_DS_data[0] & DS_data[6];
					push_DS_data[1]=~before_DS_data[1] & DS_data[7];
					before_DS_data[0]=DS_data[6];
					before_DS_data[1]=DS_data[7];
                    DS_communication_error_time=0;
                    first_communication=0;
					GOOD_de_gozaru();
				}else{											//チェックサムERROR
					BAD_de_gozaru();
				}
				break;
		}
	}
	if(DS_time_out>10){
        BAD_de_gozaru();
	}
    /*
    if((DS_communication_error_time>(FIRST_CHANGE_COMMUNICATION_TIME*50)) && first_communication){
        CHANGE_COMMUNICATION_PIN=~CHANGE_COMMUNICATION_PIN;
        DS_communication_error_time=0;
    }else if(DS_communication_error_time>(CHANGE_COMMUNICATION_TIME*50) && first_communication==0){
        CHANGE_COMMUNICATION_PIN=~CHANGE_COMMUNICATION_PIN;
        DS_communication_error_time=0;
    }*/
	always_de_gozaru();
}

char DS_RIGHT_LR_VALUE(){
	char ds2_AL;
	ds2_AL=DS_RIGHT_LR>>4;
	if(ds2_AL>8){
		return (ds2_AL-8);
	}else if(ds2_AL<7){
		return (7-ds2_AL);
	}else{
		return 0;
	}
}

char DS_RIGHT_UD_VALUE(){
	char ds2_AL;
	ds2_AL=DS_RIGHT_UD>>4;
	if(ds2_AL>8){
		return (ds2_AL-8);
	}else if(ds2_AL<7){
		return (7-ds2_AL);
	}else{
		return 0;
	}
}

char DS_LEFT_LR_VALUE(){
	char ds2_AL;
	ds2_AL=DS_LEFT_LR>>4;
	if(ds2_AL>8){
		return (ds2_AL-8);
	}else if(ds2_AL<7){
		return (7-ds2_AL);
	}else{
		return 0;
	}
}

char DS_LEFT_UD_VALUE(){
	char ds2_AL;
	ds2_AL=DS_LEFT_UD>>4;
	if(ds2_AL>8){
		return (ds2_AL-8);
	}else if(ds2_AL<7){
		return (7-ds2_AL);
	}else{
		return 0;
	}
}

signed int DS_RIGHT_LR_signed_VALUE(){
    if(DS_RIGHT_LR==127 || DS_RIGHT_LR==128){
        return 0;
    }else if(DS_RIGHT_LR>128){
        return (signed int)DS_RIGHT_LR-128;
    }else if(DS_RIGHT_LR<127){
        return (signed int)DS_RIGHT_LR-127;
    }
}

signed int DS_RIGHT_UD_signed_VALUE(){
    if(DS_RIGHT_UD==127 || DS_RIGHT_UD==128){
        return 0;
    }else if(DS_RIGHT_UD>128){
        return 128-(signed int)DS_RIGHT_UD;
    }else if(DS_RIGHT_UD<127){
        return 127-(signed int)DS_RIGHT_UD;
    }
}

signed int DS_LEFT_LR_signed_VALUE(){
    if(DS_LEFT_LR==127 || DS_LEFT_LR==128){
        return 0;
    }else if(DS_LEFT_LR>128){
        return (signed int)DS_LEFT_LR-128;
    }else if(DS_LEFT_LR<127){
        return (signed int)DS_LEFT_LR-127;
    }
}

signed int DS_LEFT_UD_signed_VALUE(){
    if(DS_LEFT_UD==127 || DS_LEFT_UD==128){
        return 0;
    }else if(DS_LEFT_UD>128){
        return 128-(signed int)DS_LEFT_UD;
    }else if(DS_LEFT_UD<127){
        return 127-(signed int)DS_LEFT_UD;
    }
}

unsigned int approx_distance(signed int dx,signed int dy){
    unsigned int min, max;
    if ( dx < 0 ) dx = -dx;
    if ( dy < 0 ) dy = -dy;
    if ( dx < dy ){
        min = dx;
        max = dy;
    }else{
        min = dy;
        max = dx;
    }
    // coefficients equivalent to ( 123/128 * max ) and ( 51/128 * min )
    return ((( max << 8 ) + ( max << 3 ) - ( max << 4 ) - ( max << 1 ) +
            ( min << 7 ) - ( min << 5 ) + ( min << 3 ) - ( min << 1 )) >> 8 );
}

unsigned int DS_RIGHT_DISTANCE_VALUE(){
    return approx_distance(DS_RIGHT_LR_signed_VALUE(),DS_RIGHT_UD_signed_VALUE());
}

unsigned int DS_LEFT_DISTANCE_VALUE(){
    return approx_distance(DS_LEFT_LR_signed_VALUE(),DS_LEFT_UD_signed_VALUE());
}

#endif	/* DS_DUAL_WOOD_H */