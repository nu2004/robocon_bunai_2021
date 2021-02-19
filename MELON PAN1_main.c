#define _XTAL_FREQ 64000000  //64MHz

//MELON PAN 1を動作させるためにそもそも必要
#include"CONFIG.h"
#include"MELONPAN1_lib_ver1.20.h"
#include"pindef.h"
#include"user_function.h"
//DSとの通信
#include"ds_dual_wood.h"
//CSVでデータ整理
#include"CSV_lib.h"

unsigned int csv_data;
char data[10];

void interrupt wood_isr(void){
    if(INT_Serial1_FLAG){
    //  ここにEUSART1の割り込み処理を書く
        read_ds_dual_byte();
    }
    if(INT_TIMER0_FLAG){//タイマー0割り込み(約20ms)
        INT_TIMER0_FLAG=0;
		//  ここにタイマー0の割り込み処理を書く
        TIMER0_16bit_set_count(25536);
        //DSとの通信に必要
        DS_time_out++;
        DS_communication_error_time++;
    }
    if(INT_TIMER1_FLAG){//タイマー1割り込み(約10ms)
        INT_TIMER1_FLAG=0;
		//  ここにタイマー1の割り込み処理を書く
        TIMER1_set_count(25536);
        //CSV_timer_task();
    }
    /*
    if(INT_TIMER2_FLAG){//タイマー2割り込み(約10ms)
        INT_TIMER2_FLAG=0;
        //  ここにタイマー2の割り込み処理を書く(PRを使用しているのでsetしなくていい)
    }*/
}

void main(){
    //default
    pin_init();
    //setup();
    
    //user
    spi_init();
    read_ds_dual_init();
    //タイマー1初期設定
	TIMER1_setup(T1357_SOURCE_FOSC4 | T1357_PRESCALER_4);
	TIMER1_set_count(25536);
    enable_interrupts(INT_TIMER1);
    
    //タイマー2初期設定
    //TIMER2_setup(T2468_SOURCE_FOSC4 | T2468_PRESCALER_128 | T2468_POSTSCALER_10,124);
    //TIMER2_set_count(0);
    //enable_interrupts(INT_TIMER2);
    
    while(1){
        //default
        //loop();
        
        //user
       
        
        read_ds_dual_de_gozaru();
    }
}

void GOOD_de_gozaru(){				//受信成功時
	//FLAG_LRは右が1、左が0
	//FLAG_UDは下が1、上が0
	RED_LED=1;
    GREEN_LED=1;
    
    if(DS3_connect){
        output_LED5(DS_battery);
    }
    
    if(DS_MARU_PUSH){
        BLUE_LED=~BLUE_LED;
        //CSV_begin(1000);
    }
    if(DS_BATU_PUSH){
        WHITE_LED=~WHITE_LED;
        //CSV_end();
    }
    //csv_data++;
}

void BAD_de_gozaru(){				//受信失敗時
    GREEN_LED=0;
	RED_LED=1;
    //テスト変更
}

void always_de_gozaru(){			//いつでも実行(GOOD、BADにくらべ多く実行)
    //CSV_transmit_task_signedint_4data(csv_data,csv_data*2,csv_data*(-1),csv_data*(-2));
    //test
    
}

