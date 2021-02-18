#ifndef PINDEF_H
#define	PINDEF_H

//通信切換えの定義
#define CHANGE_COMMUNICATION_PIN        LATAbits.LA5
#define CHANGE_COMMUNICATION_TIME       2
#define FIRST_CHANGE_COMMUNICATION_TIME 30  

//モータドライバのモードの定義
#define	MOTOR_FREE	0
#define	MOTOR_BRAKE	1
#define	MOTOR_FORWARD	2
#define	MOTOR_REVERSE	3

#define s_driver_delay  10

#define LED1    LATDbits.LATD0
#define LED2    LATHbits.LATH2
#define LED3    LATHbits.LATH3
#define LED4    LATDbits.LATD1
#define LED5    LATDbits.LATD2

#define RED_LED     LED1
#define GREEN_LED   LED2
#define BLUE_LED    LED3
#define PURPLE_LED  LED4
#define WHITE_LED   LED5

#define LED5_A  LATEbits.LATE3
#define LED5_B  LATEbits.LATE4
#define LED5_C  LATEbits.LATE5
#define LED5_D  LATEbits.LATE6
#define LED5_E  LATEbits.LATE7

//SPIの定義
#define SPI_OUT		LATCbits.LATC0
#define SPI_IN		PORTCbits.RC1
#define SPI_CLK		LATCbits.LATC6
#define SPI_SEL_1	LATAbits.LATA3
#define SPI_SEL_2	LATAbits.LATA2
#define SPI_SEL_3	LATAbits.LATA1
#define SPI_SEL_4	LATAbits.LATA0
#define SPI_SEL_5	LATHbits.LATH1
#define SPI_SEL_6	LATHbits.LATH0
#define SPI_SEL_7	LATAbits.LATA5
#define SPI_SEL_8   LATAbits.LATA4
#define SPI_SEL_9   LATGbits.LATG6
#define SPI_SEL_10	LATGbits.LATG1
#define SPI_SEL_11	LATGbits.LATG0
#define SPI_SEL_12	LATEbits.LATE0
#define SPI_SEL_13	LATEbits.LATE1
#define SPI_SEL_14	LATEbits.LATE2

void pin_init();
void output_LED5(char num);
void spi_init();

char make_s_driver_ver1_send_data(char mode,char pwm_value);
char make_s_driver_signed(signed int data);
char s_driver1_set_value(char value);
char s_driver2_set_value(char value);
char s_driver3_set_value(char value);
char s_driver4_set_value(char value);
char s_driver5_set_value(char value);
char s_driver6_set_value(char value);
char s_driver7_set_value(char value);
char s_driver8_set_value(char value);
char s_driver9_set_value(char value);
char s_driver10_set_value(char value);
char s_driver11_set_value(char value);
char s_driver12_set_value(char value);
char s_driver13_set_value(char value);
char s_driver14_set_value(char value);

void pin_init(){
    //LATx registers(出力)
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x50;//EUSART1,2
    LATE = 0x00;
    LATF = 0x00;
    LATG = 0x00;
    LATH = 0x00;
    
    //TRISx registers(入出力設定)
    TRISA = 0b11000000;
    TRISB = 0b11111111;
    TRISC = 0b10111110;
    TRISD = 0b10101000;
    TRISE = 0b00000000;
    TRISF = 0b11111111;
    TRISG = 0b10111100;
    TRISH = 0b11110000;
    /*default 
    TRISA = 0b11000000;
    TRISB = 0b11111111;
    TRISC = 0b10111110;
    TRISD = 0b10101000;
    TRISE = 0b00000000;
    TRISF = 0b11111111;
    TRISG = 0b10111100;
    TRISH = 0b11110000;
    */
    //ANSELx registers(アナログピンの設定)
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;
    ANSELF = 0x00;
    ANSELG = 0x00;

    //WPUx registers(プルアップ設定)
    WPUA = 0x00;
    WPUB = 0x00;
    WPUC = 0x00;
    WPUD = 0x00;
    WPUE = 0x00;
    WPUF = 0x00;
    WPUG = 0x00;
    WPUH = 0x00;

    //ODx registers(オープンドレイン出力設定)
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;
    ODCONE = 0x00;
    ODCONF = 0x00;
    ODCONG = 0x00;
    ODCONH = 0x00;

	//PPS(モジュールのピンを配置)
    RC0PPS = 0x1A;   //RC0->MSSP1:SDO1;    
    SSP1DATPPSbits.SSP1DATPPS = 0x11;   //RC1->MSSP1:SDI1;    
    SSP1CLKPPSbits.SSP1CLKPPS = 0x16;   //RC6->MSSP1:SCK1;    
    RC6PPS = 0x19;   //RC6->MSSP1:SCK1; 
    
    RB0PPS = 0x1C;   //RB0->MSSP2:SDA2; 
    RB1PPS = 0x1B;   //RB1->MSSP2:SCL2;    
    SSP2DATPPSbits.SSP2DATPPS = 0x08;   //RB0->MSSP2:SDA2;    
    SSP2CLKPPSbits.SSP2CLKPPS = 0x09;   //RB1->MSSP2:SCL2;   
    
    RX1PPSbits.RX1PPS = 0x1B;   //RD3->EUSART1:RX1;   
    RD4PPS = 0x0C;   //RD4->EUSART1:TX1;    
    
    RX2PPSbits.RX2PPS = 0x1D;   //RD5->EUSART2:RX2;      
    RD6PPS = 0x0E;   //RD6->EUSART2:TX2;    
}

void output_LED5(char num){
    switch(num){
        case 0:
            LED5_A=0;
            LED5_B=0;
            LED5_C=0;
            LED5_D=0;
            LED5_E=0;
            break;
        case 1:
            LED5_A=0;
            LED5_B=0;
            LED5_C=0;
            LED5_D=0;
            LED5_E=1;
            break;
        case 2:
            LED5_A=0;
            LED5_B=0;
            LED5_C=0;
            LED5_D=1;
            LED5_E=1;
            break;
        case 3:
            LED5_A=0;
            LED5_B=0;
            LED5_C=1;
            LED5_D=1;
            LED5_E=1;
            break;
        case 4:
            LED5_A=0;
            LED5_B=1;
            LED5_C=1;
            LED5_D=1;
            LED5_E=1;
            break;
        case 5:
            LED5_A=1;
            LED5_B=1;
            LED5_C=1;
            LED5_D=1;
            LED5_E=1;
            break;
        default:
            LED5_A=0;
            LED5_B=0;
            LED5_C=0;
            LED5_D=0;
            LED5_E=0;
            break;
    }
}

void spi_init(){
    SPI_begin(SPI_MODE1 | SPI_CLK_DIV16);
    SPI_SEL_1=1;
    SPI_SEL_2=1;
    SPI_SEL_3=1;
    SPI_SEL_4=1;
    SPI_SEL_5=1;
    SPI_SEL_6=1;
    SPI_SEL_7=1;
    SPI_SEL_8=1;
    SPI_SEL_9=1;
    SPI_SEL_10=1;
    SPI_SEL_11=1;
    SPI_SEL_12=1;
    SPI_SEL_13=1;
    SPI_SEL_14=1;
}

char make_s_driver_ver1_send_data(char mode,char pwm_value){//SPIモータドライバVer1用のデータを作成する関数
	pwm_value = pwm_value >> 1;//シフト演算
	if(!pwm_value){
		pwm_value = 1;
	}
	switch(mode){
		case MOTOR_FREE:
			return 0b00000000;
			break;
		case MOTOR_BRAKE:
			return 0b10000000;
			break;
		case MOTOR_FORWARD:
			return 0b10000000 + pwm_value;
			break;
		case MOTOR_REVERSE:
			return 0b00000000 + pwm_value;
			break;
	}
	return 0b10000000;
}

char make_s_driver_signed(signed int data){
    if(data>1){
        return 0b10000000+(((char)abs_int(data))>>1);
    }else if(data<(-1)){
        return 0b00000000+(((char)abs_int(data))>>1);
    }else{
        return 0b10000000;
    }
}

char s_driver1_set_value(char value){
	char temp;
	SPI_SEL_1=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_1=1;
	return temp;
}

char s_driver2_set_value(char value){
	char temp;
	SPI_SEL_2=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_2=1;
	return temp;
}

char s_driver3_set_value(char value){
	char temp;
	SPI_SEL_3=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_3=1;
	return temp;
}

char s_driver4_set_value(char value){
	char temp;
	SPI_SEL_4=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_4=1;
	return temp;
}

char s_driver5_set_value(char value){
	char temp;
	SPI_SEL_5=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_5=1;
	return temp;
}

char s_driver6_set_value(char value){
	char temp;
	SPI_SEL_6=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_6=1;
	return temp;
}

char s_driver7_set_value(char value){
	char temp;
	SPI_SEL_7=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_7=1;
	return temp;
}

char s_driver8_set_value(char value){
	char temp;
	SPI_SEL_8=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_8=1;
	return temp;
}

char s_driver9_set_value(char value){
	char temp;
	SPI_SEL_9=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_9=1;
	return temp;
}

char s_driver10_set_value(char value){
	char temp;
	SPI_SEL_10=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_10=1;
	return temp;
}

char s_driver11_set_value(char value){
	char temp;
	SPI_SEL_11=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_11=1;
	return temp;
}

char s_driver12_set_value(char value){
	char temp;
	SPI_SEL_12=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_12=1;
	return temp;
}

char s_driver13_set_value(char value){
	char temp;
	SPI_SEL_13=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_13=1;
	return temp;
}

char s_driver14_set_value(char value){
	char temp;
	SPI_SEL_14=0;
	__delay_us(s_driver_delay);
	temp = SPI_transfer(value);
	__delay_us(s_driver_delay);
	SPI_SEL_14=1;
	return temp;
}
#endif	/* PINDEF_H */