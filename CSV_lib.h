#ifndef CSV_LIB_H
#define	CSV_LIB_H

/*
CSVの割り込みは、10-1000msにしてください(10ms間隔)
CSV_timer_task()は10ms間隔で呼び出してください。
 
サンプルプログラム
if(PIR5bits.TMR1IF){//タイマー1割り込み(約10ms)
        PIR5bits.TMR1IF=0;
		//  ここにタイマー0の割り込み処理を書く
        TIMER1_set_count(25536);
        CSV_timer_task();
    }
main文
    CSV_begin(100);//100msごとに送信
    CSV_end();//終了
処理多いところ
    CSV_transmit_task_unsignedint_1data(csv_data);
*/

unsigned int CSV_lib_cycle_time;
unsigned int CSV_lib_now_time;
unsigned int CSV_lib_transmit_flag;
char CSV_lib_enable=0;

void CSV_begin(unsigned int csv_cycle);
void CSV_end();
void CSV_timer_task();
void CSV_transmit_task_unsignedint_1data(unsigned int data1);
void CSV_transmit_task_unsignedint_2data(unsigned int data1,unsigned int data2);
void CSV_transmit_task_unsignedint_3data(unsigned int data1,unsigned int data2,unsigned int data3);
void CSV_transmit_task_unsignedint_4data(unsigned int data1,unsigned int data2,unsigned int data3,unsigned int data4);
void CSV_transmit_task_signedint_1data(signed int data1);
void CSV_transmit_task_signedint_2data(signed int data1,signed int data2);
void CSV_transmit_task_signedint_3data(signed int data1,signed int data2,signed int data3);
void CSV_transmit_task_signedint_4data(signed int data1,signed int data2,signed int data3,signed int data4);

void CSV_begin(unsigned int csv_cycle){
    CSV_lib_cycle_time=csv_cycle;
    CSV_lib_now_time=0;
    CSV_lib_transmit_flag=0;
    
    //Serial2初期設定
    Serial2_begin(57600,SERIAL_NON_INVERT);//57600 -0.08%
    
    CSV_lib_enable=1;
}

void CSV_end(){
    CSV_lib_enable=0;
}

void CSV_timer_task(){
    static unsigned int CSV_lib_count;
    if(CSV_lib_enable){
        CSV_lib_count+=10;
        if(CSV_lib_count>=CSV_lib_cycle_time){
            CSV_lib_count=0;
            CSV_lib_transmit_flag=1;
        }  
    }  
}

void CSV_transmit_task_unsignedint_1data(unsigned int data1){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}

void CSV_transmit_task_unsignedint_2data(unsigned int data1,unsigned int data2){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data2);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}

void CSV_transmit_task_unsignedint_3data(unsigned int data1,unsigned int data2,unsigned int data3){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data2);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data3);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}


void CSV_transmit_task_unsignedint_4data(unsigned int data1,unsigned int data2,unsigned int data3,unsigned int data4){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data2);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data3);
        Serial2_print(csv_buf);
        Serial2_write(',');
        unsignedint_to_ASCII(csv_buf,0,data4);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}

void CSV_transmit_task_signedint_1data(signed int data1){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        signedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}

void CSV_transmit_task_signedint_2data(signed int data1,signed int data2){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data2);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}

void CSV_transmit_task_signedint_3data(signed int data1,signed int data2,signed int data3){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data2);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data3);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}


void CSV_transmit_task_signedint_4data(signed int data1,signed int data2,signed int data3,signed int data4){
    char csv_buf[10];
    if(CSV_lib_transmit_flag){
        CSV_lib_transmit_flag=0;
        CSV_lib_now_time+=CSV_lib_cycle_time;
        unsignedint_to_ASCII(csv_buf,0,CSV_lib_now_time);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data1);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data2);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data3);
        Serial2_print(csv_buf);
        Serial2_write(',');
        signedint_to_ASCII(csv_buf,0,data4);
        Serial2_print(csv_buf);
        Serial2_write('\n');
    }
}

#endif	/* CSV_LIB_H */