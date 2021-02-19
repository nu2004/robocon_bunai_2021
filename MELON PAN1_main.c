#define _XTAL_FREQ 64000000  //64MHz

//MELON PAN 1�𓮍삳���邽�߂ɂ��������K�v
#include"CONFIG.h"
#include"MELONPAN1_lib_ver1.20.h"
#include"pindef.h"
#include"user_function.h"
//DS�Ƃ̒ʐM
#include"ds_dual_wood.h"
//CSV�Ńf�[�^����
#include"CSV_lib.h"

unsigned int csv_data;
char data[10];

void interrupt wood_isr(void){
    if(INT_Serial1_FLAG){
    //  ������EUSART1�̊��荞�ݏ���������
        read_ds_dual_byte();
    }
    if(INT_TIMER0_FLAG){//�^�C�}�[0���荞��(��20ms)
        INT_TIMER0_FLAG=0;
		//  �����Ƀ^�C�}�[0�̊��荞�ݏ���������
        TIMER0_16bit_set_count(25536);
        //DS�Ƃ̒ʐM�ɕK�v
        DS_time_out++;
        DS_communication_error_time++;
    }
    if(INT_TIMER1_FLAG){//�^�C�}�[1���荞��(��10ms)
        INT_TIMER1_FLAG=0;
		//  �����Ƀ^�C�}�[1�̊��荞�ݏ���������
        TIMER1_set_count(25536);
        //CSV_timer_task();
    }
    /*
    if(INT_TIMER2_FLAG){//�^�C�}�[2���荞��(��10ms)
        INT_TIMER2_FLAG=0;
        //  �����Ƀ^�C�}�[2�̊��荞�ݏ���������(PR���g�p���Ă���̂�set���Ȃ��Ă���)
    }*/
}

void main(){
    //default
    pin_init();
    //setup();
    
    //user
    spi_init();
    read_ds_dual_init();
    //�^�C�}�[1�����ݒ�
	TIMER1_setup(T1357_SOURCE_FOSC4 | T1357_PRESCALER_4);
	TIMER1_set_count(25536);
    enable_interrupts(INT_TIMER1);
    
    //�^�C�}�[2�����ݒ�
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

void GOOD_de_gozaru(){				//��M������
	//FLAG_LR�͉E��1�A����0
	//FLAG_UD�͉���1�A�オ0
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

void BAD_de_gozaru(){				//��M���s��
    GREEN_LED=0;
	RED_LED=1;
    //�e�X�g�ύX
}

void always_de_gozaru(){			//���ł����s(GOOD�ABAD�ɂ���ב������s)
    //CSV_transmit_task_signedint_4data(csv_data,csv_data*2,csv_data*(-1),csv_data*(-2));
    //test
    
}

