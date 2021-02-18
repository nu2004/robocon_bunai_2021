/* 
 * File:   MELONPAN1_lib_ver1.20.h
 * Author: wood
 *
 * Created on 2018/08/14, 21:46
 */

#ifndef MELONPAN1_LIB_VER1_20_H
#define	MELONPAN1_LIB_VER1_20_H

#include<xc.h>
#include <pic18f67k40.h>

//////////////////////////////AD変換
#define ANA0    0
#define ANA1    1
#define ANA2    2
#define ANA3    3
#define ANA4    4
#define ANA5    5
#define ANA6    6
#define ANA7    7
#define ANB0    8
#define ANB1    9
#define ANB2    10
#define ANB3    11
#define ANB4    12
#define ANB5    13
#define ANB6    14
#define ANB7    15
#define AND0    24
#define AND1    25
#define AND2    26
#define AND3    27
#define AND4    28
#define AND5    29
#define AND6    30
#define AND7    31
#define ANE0    32
#define ANE1    33
#define ANE2    34
#define ANE3    35
#define ANE4    36
#define ANE5    37
#define ANE6    38
#define ANE7    39
#define ANF0    40
#define ANF1    41
#define ANF2    42
#define ANF3    43
#define ANF4    44
#define ANF5    45
#define ANF6    46
#define ANF7    47
#define ANG0    48
#define ANG1    49
#define ANG2    50
#define ANG3    51
#define ANG4    52
#define ANG6    54
#define ANG7    55


//////////////////////////////SPI(MASTER ONLY)
#define SPI_MODE0               0x4000
#define SPI_MODE1               0x0000
#define SPI_MODE2               0x4010
#define SPI_MODE3               0x0010

#define SPI_CLK_DIV4            0x00
#define SPI_CLK_DIV16           0x01
#define SPI_CLK_DIV64           0x02
#define SPI_CLK_T2              0x03

#define SPI_SAMPLE_AT_MIDDLE    0x0000
#define SPI_SAMPLE_AT_END       0x8000



//////////////////////////////I2C(MASTER ONLY)
//I2C_begin()
#define I2C_400kbps 0
#define I2C_100kbps 1
//I2C_read()   return->I2C_write(),I2C_beginTransmission()
#define I2C_ACK     0
#define I2C_NOT_ACK 1
//I2C_beginTransmission()
#define I2C_WRITE   0
#define I2C_READ    1
//I2C_endTransmission()
#define I2C_RESTART 0
#define I2C_STOP    1



//////////////////////////////EUART(Asynchronous  8bit only)
//EUSART 16bitボーレート Hi-speed
//ボーレート	SPxBRGH	SPxBRGL	Error[%]
//115200	0x00	0x8A	-0.080
//57600		0x01	0x15	-0.080
//19200		0x03	0x40	0.040
//9600		0x06	0x82	-0.020
//2400		0x1A	0x0A	-0.005
//1200		0x34	0x14	0.003	
//300		0xD0	0x54	0.001
#define SERIAL_INVERT       0x10
#define SERIAL_NON_INVERT   0x00



//////////////////////////////TIMER0
#define T0_16BIT            0x10
#define T0_8BIT             0x00

#define T0_POSTSCALER_16    0x0F
#define T0_POSTSCALER_15    0x0E
#define T0_POSTSCALER_14    0x0D
#define T0_POSTSCALER_13    0x0C
#define T0_POSTSCALER_12    0x0B
#define T0_POSTSCALER_11    0x0A
#define T0_POSTSCALER_10    0x09
#define T0_POSTSCALER_9     0x08
#define T0_POSTSCALER_8     0x07
#define T0_POSTSCALER_7     0x06
#define T0_POSTSCALER_6     0x05
#define T0_POSTSCALER_5     0x04
#define T0_POSTSCALER_4     0x03
#define T0_POSTSCALER_3     0x02
#define T0_POSTSCALER_2     0x01
#define T0_POSTSCALER_1     0x00

#define T0_SOURCE_SOSC          0xA000
#define T0_SOURCE_LFINTOSC      0x8000
#define T0_SOURCE_HFINTOSC      0x6000
#define T0_SOURCE_FOSC4         0x4000
#define T0_SOURCE_T0CKI_INVERT  0x2000
#define T0_SOURCE_T0CKI         0x0000

#define T0_SYNC                 0x0000
#define T0_NOT_SYNC             0x1000

#define T0_PRESCALER_32768      0x0F00
#define T0_PRESCALER_16384      0x0E00
#define T0_PRESCALER_8192       0x0D00
#define T0_PRESCALER_4096       0x0C00
#define T0_PRESCALER_2048       0x0B00
#define T0_PRESCALER_1024       0x0A00
#define T0_PRESCALER_512        0x0900
#define T0_PRESCALER_256        0x0800
#define T0_PRESCALER_128        0x0700
#define T0_PRESCALER_64         0x0600
#define T0_PRESCALER_32         0x0500
#define T0_PRESCALER_16         0x0400
#define T0_PRESCALER_8          0x0300
#define T0_PRESCALER_4          0x0200
#define T0_PRESCALER_2          0x0100
#define T0_PRESCALER_1          0x0000



//////////////////////////////TIMER1/3/5/7(GATE CONTROL FUNCTION NOT SUPPORTED)
#define T1357_PRESCALER_8   0x30
#define T1357_PRESCALER_4   0x20
#define T1357_PRESCALER_2   0x10
#define T1357_PRESCALER_1   0x00

#define T1357_SYNC          0x00
#define T1357_NOT_SYNC      0x04

#define T1357_SOURCE_CLKREF     0x0700
#define T1357_SOURCE_SOSC       0x0600
#define T1357_SOURCE_MFINTOSC   0x0500
#define T1357_SOURCE_LFINTOSC   0x0400
#define T1357_SOURCE_HFINTOSC   0x0300
#define T1357_SOURCE_FOSC       0x0200
#define T1357_SOURCE_FOSC4      0x0100
#define T1357_SOURCE_CKIPPS     0x0000



//////////////////////////////TIMER2/4/6/8(HARDWARE LIMIT CONTROL FUNCTION NOT SUPPORTED)
#define T2468_PRESCALER_128     0x70
#define T2468_PRESCALER_64      0x60
#define T2468_PRESCALER_32      0x50
#define T2468_PRESCALER_16      0x40
#define T2468_PRESCALER_8       0x30
#define T2468_PRESCALER_4       0x20
#define T2468_PRESCALER_2       0x10
#define T2468_PRESCALER_1       0x00

#define T2468_POSTSCALER_16     0x0f
#define T2468_POSTSCALER_15     0x0e
#define T2468_POSTSCALER_14     0x0d
#define T2468_POSTSCALER_13     0x0c
#define T2468_POSTSCALER_12     0x0b
#define T2468_POSTSCALER_11     0x0a
#define T2468_POSTSCALER_10     0x09
#define T2468_POSTSCALER_9      0x08
#define T2468_POSTSCALER_8      0x07
#define T2468_POSTSCALER_7      0x06
#define T2468_POSTSCALER_6      0x05
#define T2468_POSTSCALER_5      0x04
#define T2468_POSTSCALER_4      0x03
#define T2468_POSTSCALER_3      0x02
#define T2468_POSTSCALER_2      0x01
#define T2468_POSTSCALER_1      0x00

#define T2468_SOURCE_ZCDOUT     0x0800
#define T2468_SOURCE_CLKREF     0x0700
#define T2468_SOURCE_SOSC       0x0600
#define T2468_SOURCE_MFINTOSC   0x0500
#define T2468_SOURCE_LFINTOSC   0x0400
#define T2468_SOURCE_HFINTOSC   0x0300
#define T2468_SOURCE_FOSC       0x0200
#define T2468_SOURCE_FOSC4      0x0100
#define T2468_SOURCE_INPPS      0x0000



//////////////////////////////interrupts
#define INT_GLOBAL      0
#define INT_TIMER0      1
#define INT_TIMER1      2
#define INT_TIMER2      3
#define INT_TIMER3      4
#define INT_TIMER4      5
#define INT_TIMER5      6
#define INT_TIMER6      7
#define INT_TIMER7      8
#define INT_TIMER8      9
#define INT_Serial1     10
#define INT_Serial2     11
#define INT_Serial3     12
#define INT_Serial4     13
#define INT_Serial5     14

#define INT_TIMER0_FLAG     PIR0bits.TMR0IF
#define INT_TIMER1_FLAG     PIR5bits.TMR1IF
#define INT_TIMER2_FLAG     PIR5bits.TMR2IF
#define INT_TIMER3_FLAG     PIR5bits.TMR3IF
#define INT_TIMER4_FLAG     PIR5bits.TMR4IF
#define INT_TIMER5_FLAG     PIR5bits.TMR5IF
#define INT_TIMER6_FLAG     PIR5bits.TMR6IF
#define INT_TIMER7_FLAG     PIR5bits.TMR7IF
#define INT_TIMER8_FLAG     PIR5bits.TMR8IF
#define INT_Serial1_FLAG    PIR3bits.RC1IF
#define INT_Serial2_FLAG    PIR3bits.RC2IF
#define INT_Serial3_FLAG    PIR4bits.RC3IF
#define INT_Serial4_FLAG    PIR4bits.RC4IF
#define INT_Serial5_FLAG    PIR4bits.RC5IF



void analogSetup();
unsigned int analogRead(char channel);

void SPI_begin(unsigned int data);
void SPI_end();
char SPI_transfer(char send_data);

void I2C_begin(char data);
void I2C_start_condition();
void I2C_restart_condition();
void I2C_stop_condition();
char I2C_write(char data);
char I2C_read(char data);
//上の関数を用いたよく使う通信
char I2C_beginTransmission(char address,char status);
void I2C_endTransmission(char data);

void Serial1_begin(unsigned int speed,char data);
void Serial1_end();
char Serial1_read();
void Serial1_write(char send_data);
void Serial1_print(char str[]);

void Serial2_begin(unsigned int speed,char data);
void Serial2_end();
char Serial2_read();
void Serial2_write(char send_data);
void Serial2_print(char str[]);

void Serial3_begin(unsigned int speed,char data);
void Serial3_end();
char Serial3_read();
void Serial3_write(char send_data);
void Serial3_print(char str[]);

void Serial4_begin(unsigned int speed,char data);
void Serial4_end();
char Serial4_read();
void Serial4_write(char send_data);
void Serial4_print(char str[]);

void Serial5_begin(unsigned int speed,char data);
void Serial5_end();
char Serial5_read();
void Serial5_write(char send_data);
void Serial5_print(char str[]);

void TIMER0_setup(unsigned int data);
void TIMER0_8bit_set_count(char data);
char TIMER0_8bit_get_count(void);
void TIMER0_16bit_set_count(unsigned int data);
unsigned int TIMER0_16bit_get_count(void);

void TIMER1_setup(unsigned int data);
void TIMER1_off(void);
void TIMER1_set_count(unsigned int data);
unsigned int TIMER1_get_count(void);

void TIMER3_setup(unsigned int data);
void TIMER3_off(void);
void TIMER3_set_count(unsigned int data);
unsigned int TIMER3_get_count(void);

void TIMER5_setup(unsigned int data);
void TIMER5_off(void);
void TIMER5_set_count(unsigned int data);
unsigned int TIMER5_get_count(void);

void TIMER7_setup(unsigned int data);
void TIMER7_off(void);
void TIMER7_set_count(unsigned int data);
unsigned int TIMER7_get_count(void);

void TIMER2_setup(unsigned int data,char PR_num);
void TIMER2_off(void);
void TIMER2_set_count(char data);
char TIMER2_get_count(void);

void TIMER4_setup(unsigned int data,char PR_num);
void TIMER4_off(void);
void TIMER4_set_count(char data);
char TIMER4_get_count(void);

void TIMER6_setup(unsigned int data,char PR_num);
void TIMER6_off(void);
void TIMER6_set_count(char data);
char TIMER6_get_count(void);

void TIMER8_setup(unsigned int data,char PR_num);
void TIMER8_off(void);
void TIMER8_set_count(char data);
char TIMER8_get_count(void);

void enable_interrupts(char data);
void disable_interrupts(char data);

void char_to_ASCII(char ascii_buf[],char kaigyou_enable,char num);
void unsignedint_to_ASCII(char ascii_buf[],char kaigyou_enable,unsigned int num);
void signedint_to_ASCII(char ascii_buf[],char kaigyou_enable,signed int num);
void float_to_ASCII(char ascii_buf[],char kaigyou_enable,float num);//format-00000.00

signed int abs_int(signed int data);

char bit_clear(char number,char bit_place);
char bit_test(char number,char bit_place);
int bit_test_int(int number,char bit_place);
char ten_bit_test(char data,char keta);
char ten_bit_test_unsignedint(unsigned int data,char keta);

void analogSetup(){
    ADCON1 = 0x00;
    ADCON2 = 0x00;
    ADCON3 = 0x00;
    ADCLK = 0x1F;// FOSC/64>TAD1.0us
    ADREF = 0x00;//Reference VDD-VSS
    ADPRE = 0;//そして、考えるのをやめた。
    ADACQ = 0;//16f88みたいに手動delayでいいや。(´・ω・)
    
    ADCON0 = 0x84;// ADGO stop; ADFM right; ADON enabled; ADCONT disabled; ADCS FOSC/ADCLK; 
}

unsigned int analogRead(char channel){
    ADPCH=channel;
    __delay_us(50);
    ADCON0bits.ADGO=1;
    while(ADCON0bits.ADGO);
    return ((ADRESH << 8) + ADRESL) & 0x03FF;
}

void SPI_begin(unsigned int data){
    SSP1STAT=((char)(data>>8)) | 0x00;
    SSP1CON1=((char)(data & 0x00ff)) | 0x20;
}

void SPI_end(){
    SSP1CON1bits.SSPEN=0;
}

char SPI_transfer(char send_data){
    // Clear the Write Collision flag, to allow writing
    SSP1CON1bits.WCOL = 0;
    SSP1BUF = send_data;
    while(!SSP1STATbits.BF);
    return (SSP1BUF);
}

void I2C_begin(char data){
    if(data==I2C_100kbps){
        SSP2CON1=0x28;
        SSP2CON3 = 0x00;
        SSP2ADD=159;
        SSP2STAT=0x80;
    }else if(data==I2C_400kbps){
        SSP2CON1=0x28;
        SSP2CON3 = 0x00;
        SSP2ADD=39;
        SSP2STAT=0;
    }
}

void I2C_start_condition(){
    SSP2CON2bits.SEN=1;
    while(SSP2CON2bits.SEN);
}

void I2C_restart_condition(){
    SSP2CON2bits.RSEN=1;
    while(SSP2CON2bits.RSEN);
}

void I2C_stop_condition(){
    SSP2CON2bits.PEN=1;
    while(SSP2CON2bits.PEN);
}

char I2C_write(char data){
    PIR3bits.SSP2IF=0;
    SSP2BUF=data;
    while(!PIR3bits.SSP2IF);
    return SSP2CON2bits.ACKSTAT;
}

char I2C_read(char data){
    SSP2CON2bits.RCEN=1;
    while(!SSP2STATbits.BF);
    SSP2CON2bits.ACKDT=data;
    SSP2CON2bits.ACKEN=1;
    while(SSP2CON2bits.ACKEN);
    return SSP2BUF;
}

char I2C_beginTransmission(char address,char status){
    I2C_start_condition();
    return I2C_write((address<<1) | status);
}

void I2C_endTransmission(char data){
    if(data==I2C_STOP){
        I2C_stop_condition();
    }else if(data==I2C_RESTART){
        I2C_restart_condition();
    }
}

void Serial1_begin(unsigned int speed,char data){
    if(speed==115200){
        SP1BRGH=0x00;
        SP1BRGL=0x8A;
    }else if(speed==57600){
        SP1BRGH=0x01;
        SP1BRGL=0x15;
    }else if(speed==19200){
        SP1BRGH=0x03;
        SP1BRGL=0x40;
    }else if(speed==9600){
        SP1BRGH=0x06;
        SP1BRGL=0x82;
    }else if(speed==2400){
        SP1BRGH=0x1A;
        SP1BRGL=0x0A;
    }else if(speed==1200){
        SP1BRGH=0x34;
        SP1BRGL=0x14;
    }
    
    TX1STA=0x24;
    RC1STA=0x90;
    BAUD1CON=0x08 | data;
    
}

void Serial1_end(){
    TX1STA=0;
    RC1STA=0;
}

char Serial1_read(){
    while(!PIR3bits.RC1IF);
    return RC1REG;
}

void Serial1_write(char send_data){
    while(!TX1STAbits.TRMT);
    TX1REG=send_data;
}

void Serial1_print(char str[]){
    char i=0;
    for(i=0;str[i]!='\0';i++){
        Serial1_write(str[i]);
        __delay_us(10);
    }
}

void Serial2_begin(unsigned int speed,char data){
    if(speed==115200){
        SP2BRGH=0x00;
        SP2BRGL=0x8A;
    }else if(speed==57600){
        SP2BRGH=0x01;
        SP2BRGL=0x15;
    }else if(speed==19200){
        SP2BRGH=0x03;
        SP2BRGL=0x40;
    }else if(speed==9600){
        SP2BRGH=0x06;
        SP2BRGL=0x82;
    }else if(speed==2400){
        SP2BRGH=0x1A;
        SP2BRGL=0x0A;
    }else if(speed==1200){
        SP2BRGH=0x34;
        SP2BRGL=0x14;
    }
    
    TX2STA=0x24;
    RC2STA=0x90;
    BAUD2CON=0x08 | data;
    
}

void Serial2_end(){
    TX2STA=0;
    RC2STA=0;
}

char Serial2_read(){
    while(!PIR3bits.RC2IF);
    return RC2REG;
}

void Serial2_write(char send_data){
    while(!TX2STAbits.TRMT);
    TX2REG=send_data;
}

void Serial2_print(char str[]){
    char i=0;
    for(i=0;str[i]!='\0';i++){
        Serial2_write(str[i]);
        __delay_us(10);
    }
}

void Serial3_begin(unsigned int speed,char data){
    if(speed==115200){
        SP3BRGH=0x00;
        SP3BRGL=0x8A;
    }else if(speed==57600){
        SP3BRGH=0x01;
        SP3BRGL=0x15;
    }else if(speed==19200){
        SP3BRGH=0x03;
        SP3BRGL=0x40;
    }else if(speed==9600){
        SP3BRGH=0x06;
        SP3BRGL=0x82;
    }else if(speed==2400){
        SP3BRGH=0x1A;
        SP3BRGL=0x0A;
    }else if(speed==1200){
        SP3BRGH=0x34;
        SP3BRGL=0x14;
    }
    
    TX3STA=0x24;
    RC3STA=0x90;
    BAUD3CON=0x08 | data;
    
}

void Serial3_end(){
    TX3STA=0;
    RC3STA=0;
}

char Serial3_read(){
    while(!PIR4bits.RC3IF);
    return RC3REG;
}

void Serial3_write(char send_data){
    while(!TX3STAbits.TRMT);
    TX3REG=send_data;
}

void Serial3_print(char str[]){
    char i=0;
    for(i=0;str[i]!='\0';i++){
        Serial3_write(str[i]);
        __delay_us(10);
    }
}

void Serial4_begin(unsigned int speed,char data){
    if(speed==115200){
        SP4BRGH=0x00;
        SP4BRGL=0x8A;
    }else if(speed==57600){
        SP4BRGH=0x01;
        SP4BRGL=0x15;
    }else if(speed==19200){
        SP4BRGH=0x03;
        SP4BRGL=0x40;
    }else if(speed==9600){
        SP4BRGH=0x06;
        SP4BRGL=0x82;
    }else if(speed==2400){
        SP4BRGH=0x1A;
        SP4BRGL=0x0A;
    }else if(speed==1200){
        SP4BRGH=0x34;
        SP4BRGL=0x14;
    }
    
    TX4STA=0x24;
    RC4STA=0x90;
    BAUD4CON=0x08 | data;
    
}

void Serial4_end(){
    TX4STA=0;
    RC4STA=0;
}

char Serial4_read(){
    while(!PIR4bits.RC4IF);
    return RC4REG;
}

void Serial4_write(char send_data){
    while(!TX4STAbits.TRMT);
    TX4REG=send_data;
}

void Serial4_print(char str[]){
    char i=0;
    for(i=0;str[i]!='\0';i++){
        Serial4_write(str[i]);
        __delay_us(10);
    }
}

void Serial5_begin(unsigned int speed,char data){
    if(speed==115200){
        SP5BRGH=0x00;
        SP5BRGL=0x8A;
    }else if(speed==57600){
        SP5BRGH=0x01;
        SP5BRGL=0x15;
    }else if(speed==19200){
        SP5BRGH=0x03;
        SP5BRGL=0x40;
    }else if(speed==9600){
        SP5BRGH=0x06;
        SP5BRGL=0x82;
    }else if(speed==2400){
        SP5BRGH=0x1A;
        SP5BRGL=0x0A;
    }else if(speed==1200){
        SP5BRGH=0x34;
        SP5BRGL=0x14;
    }
    
    TX5STA=0x24;
    RC5STA=0x90;
    BAUD5CON=0x08 | data;
    
}

void Serial5_end(){
    TX5STA=0;
    RC5STA=0;
}

char Serial5_read(){
    while(!PIR4bits.RC5IF);
    return RC5REG;
}

void Serial5_write(char send_data){
    while(!TX5STAbits.TRMT);
    TX5REG=send_data;
}

void Serial5_print(char str[]){
    char i=0;
    for(i=0;str[i]!='\0';i++){
        Serial5_write(str[i]);
        __delay_us(10);
    }
}

void TIMER0_setup(unsigned int data){
    T0CON1=(char)((data>>8) & 0xff);
    T0CON0=((char)(data & 0xff)) | 0x80;
}

void TIMER0_8bit_set_count(char data){
    TMR0L=data;
}

char TIMER0_8bit_get_count(void){
    return TMR0L;
}

void TIMER0_16bit_set_count(unsigned int data){
    TMR0H=(char)(data>>8);
    TMR0L=(char)(data);
}

unsigned int TIMER0_16bit_get_count(void){
    char tmr0_data;
    unsigned int tmr0_data_int;
    tmr0_data=TMR0L;
    tmr0_data_int=(unsigned int)TMR0H;
    tmr0_data_int=(tmr0_data_int<<8)+(unsigned int)tmr0_data;
    return tmr0_data_int;
}

void TIMER1_setup(unsigned int data){
    T1GCON=0;
    TMR1CLK=(char)((data>>8) & 0xff);
    T1CON=((char)(data & 0xff)) | 0x03;
}

void TIMER1_off(void){
    T1CONbits.ON=0;
}

void TIMER1_set_count(unsigned int data){
    TMR1H=(char)(data>>8);
    TMR1L=(char)(data);
}

unsigned int TIMER1_get_count(void){
    char tmr1_data;
    unsigned int tmr1_data_int;
    tmr1_data=TMR1L;
    tmr1_data_int=(unsigned int)TMR1H;
    tmr1_data_int=(tmr1_data_int<<8)+(unsigned int)tmr1_data;
    return tmr1_data_int;
}

void TIMER3_setup(unsigned int data){
    T3GCON=0;
    TMR3CLK=(char)((data>>8) & 0xff);
    T3CON=((char)(data & 0xff)) | 0x03;
}

void TIMER3_off(void){
    T3CONbits.ON=0;
}

void TIMER3_set_count(unsigned int data){
    TMR3H=(char)(data>>8);
    TMR3L=(char)(data);
}

unsigned int TIMER3_get_count(void){
    char tmr3_data;
    unsigned int tmr3_data_int;
    tmr3_data=TMR3L;
    tmr3_data_int=(unsigned int)TMR3H;
    tmr3_data_int=(tmr3_data_int<<8)+(unsigned int)tmr3_data;
    return tmr3_data_int;
}

void TIMER5_setup(unsigned int data){
    T5GCON=0;
    TMR5CLK=(char)((data>>8) & 0xff);
    T5CON=((char)(data & 0xff)) | 0x03;
}

void TIMER5_off(void){
    T5CONbits.ON=0;
}

void TIMER5_set_count(unsigned int data){
    TMR5H=(char)(data>>8);
    TMR5L=(char)(data);
}

unsigned int TIMER5_get_count(void){
    char tmr5_data;
    unsigned int tmr5_data_int;
    tmr5_data=TMR5L;
    tmr5_data_int=(unsigned int)TMR5H;
    tmr5_data_int=(tmr5_data_int<<8)+(unsigned int)tmr5_data;
    return tmr5_data_int;
}

void TIMER7_setup(unsigned int data){
    T7GCON=0;
    TMR7CLK=(char)((data>>8) & 0xff);
    T7CON=((char)(data & 0xff)) | 0x03;
}

void TIMER7_off(void){
    T7CONbits.ON=0;
}

void TIMER7_set_count(unsigned int data){
    TMR7H=(char)(data>>8);
    TMR7L=(char)(data);
}

unsigned int TIMER7_get_count(void){
    char tmr7_data;
    unsigned int tmr7_data_int;
    tmr7_data=TMR7L;
    tmr7_data_int=(unsigned int)TMR7H;
    tmr7_data_int=(tmr7_data_int<<8)+(unsigned int)tmr7_data;
    return tmr7_data_int;
}

void TIMER2_setup(unsigned int data,char PR_num){
    T2RST=0;
    T2HLT=0;
    T2PR=PR_num;
    T2CLKCON=(char)((data>>8) & 0xff);
    T2CON=((char)(data & 0xff)) | 0x80;
}

void TIMER2_off(void){
    T2CONbits.ON=0;
}

void TIMER2_set_count(char data){
    TMR2=data;
}

char TIMER2_get_count(void){
    return TMR2;
}

void TIMER4_setup(unsigned int data,char PR_num){
    T4RST=0;
    T4HLT=0;
    T4PR=PR_num;
    T4CLKCON=(char)((data>>8) & 0xff);
    T4CON=((char)(data & 0xff)) | 0x80;
}

void TIMER4_off(void){
    T4CONbits.ON=0;
}

void TIMER4_set_count(char data){
    TMR4=data;
}

char TIMER4_get_count(void){
    return TMR4;
}

void TIMER6_setup(unsigned int data,char PR_num){
    T6RST=0;
    T6HLT=0;
    T6PR=PR_num;
    T6CLKCON=(char)((data>>8) & 0xff);
    T6CON=((char)(data & 0xff)) | 0x80;
}

void TIMER6_off(void){
    T6CONbits.ON=0;
}

void TIMER6_set_count(char data){
    TMR6=data;
}

char TIMER6_get_count(void){
    return TMR6;
}

void TIMER8_setup(unsigned int data,char PR_num){
    T8RST=0;
    T8HLT=0;
    T8PR=PR_num;
    T8CLKCON=(char)((data>>8) & 0xff);
    T8CON=((char)(data & 0xff)) | 0x80;
}

void TIMER8_off(void){
    T8CONbits.ON=0;
}

void TIMER8_set_count(char data){
    TMR8=data;
}

char TIMER8_get_count(void){
    return TMR8;
}

void enable_interrupts(char data){
    switch(data){
        case INT_GLOBAL:
            INTCONbits.GIE=1;
            break;
        case INT_TIMER0:
            INTCONbits.PEIE=1;
            PIR0bits.TMR0IF=0;
            PIE0bits.TMR0IE=1;
            break;
        case INT_TIMER1:
            INTCONbits.PEIE=1;
            PIR5bits.TMR1IF=0;
            PIE5bits.TMR1IE=1;
            break;
        case INT_TIMER3:
            INTCONbits.PEIE=1;
            PIR5bits.TMR3IF=0;
            PIE5bits.TMR3IE=1;
            break;
        case INT_TIMER5:
            INTCONbits.PEIE=1;
            PIR5bits.TMR5IF=0;
            PIE5bits.TMR5IE=1;
            break;
        case INT_TIMER7:
            INTCONbits.PEIE=1;
            PIR5bits.TMR7IF=0;
            PIE5bits.TMR7IE=1;
            break;
        case INT_TIMER2:
            INTCONbits.PEIE=1;
            PIR5bits.TMR2IF=0;
            PIE5bits.TMR2IE=1;
            break;
        case INT_TIMER4:
            INTCONbits.PEIE=1;
            PIR5bits.TMR4IF=0;
            PIE5bits.TMR4IE=1;
            break;
        case INT_TIMER6:
            INTCONbits.PEIE=1;
            PIR5bits.TMR6IF=0;
            PIE5bits.TMR6IE=1;
            break;
        case INT_TIMER8:
            INTCONbits.PEIE=1;
            PIR5bits.TMR8IF=0;
            PIE5bits.TMR8IE=1;
            break;
        case INT_Serial1:
            INTCONbits.PEIE=1;
            PIE3bits.RC1IE=1;
            break;
        case INT_Serial2:
            INTCONbits.PEIE=1;
            PIE3bits.RC2IE=1;
            break;
        case INT_Serial3:
            INTCONbits.PEIE=1;
            PIE4bits.RC3IE=1;
            break;
        case INT_Serial4:
            INTCONbits.PEIE=1;
            PIE4bits.RC4IE=1;
            break;
        case INT_Serial5:
            INTCONbits.PEIE=1;
            PIE4bits.RC5IE=1;
            break;
    }
}

void disable_interrupts(char data){
    switch(data){
        case INT_GLOBAL:
            INTCONbits.GIE=0;
            break;
        case INT_TIMER0:
            PIE0bits.TMR0IE=0;
            break;
        case INT_TIMER1:
            PIE5bits.TMR1IE=0;
            break;
        case INT_TIMER3:
            PIE5bits.TMR3IE=0;
            break;
        case INT_TIMER5:
            PIE5bits.TMR5IE=0;
            break;
        case INT_TIMER7:
            PIE5bits.TMR7IE=0;
            break;
        case INT_TIMER2:
            PIE5bits.TMR2IE=0;
            break;
        case INT_TIMER4:
            PIE5bits.TMR4IE=0;
            break;
        case INT_TIMER6:
            PIE5bits.TMR6IE=0;
            break;
        case INT_TIMER8:
            PIE5bits.TMR8IE=0;
            break;
        case INT_Serial1:
            PIE3bits.RC1IE=0;
            break;
        case INT_Serial2:
            PIE3bits.RC2IE=0;
            break;
        case INT_Serial3:
            PIE4bits.RC3IE=0;
            break;
        case INT_Serial4:
            PIE4bits.RC4IE=0;
            break;
        case INT_Serial5:
            PIE4bits.RC5IE=0;
            break;
    }
}

void char_to_ASCII(char ascii_buf[],char kaigyou_enable,char num){
    char i;
    for(i=0;i<3;i++){
        ascii_buf[i]=ten_bit_test(num,2-i)+48;
    }
    if(kaigyou_enable){
        ascii_buf[3]='\n';
        ascii_buf[4]=0;
    }else{
        ascii_buf[3]=0;
    }
}

void unsignedint_to_ASCII(char ascii_buf[],char kaigyou_enable,unsigned int num){
    char i;
    for(i=0;i<5;i++){
        ascii_buf[i]=ten_bit_test_unsignedint(num,4-i)+48;
    }
    if(kaigyou_enable){
        ascii_buf[5]='\n';
        ascii_buf[6]=0;
    }else{
        ascii_buf[5]=0;
    }
    
}

void signedint_to_ASCII(char ascii_buf[],char kaigyou_enable,signed int num){
    if(num<0){
        ascii_buf[0]='-';
    }else{
        ascii_buf[0]=' ';
    }
    unsignedint_to_ASCII(&ascii_buf[1],kaigyou_enable,(unsigned int)abs_int(num));
}

void float_to_ASCII(char ascii_buf[],char kaigyou_enable,float num){//format-00000.00
    char ascii_num=0;
    char i;
    if(num>=100000.0 || num<=(-100000.0)){//範囲外
        return;
    }
    
    if(num<0){//マイナスの処理
        ascii_buf[0]='-';
        num=(-num);
    }else{
        ascii_buf[0]=' ';
    }
    
    ascii_num=0;
    while(num>=10000.0){
		num=num-10000.0;
		ascii_num++;
	}
    ascii_buf[1]=ascii_num+48;
    ascii_num=0;
    while(num>=1000.0){
		num=num-1000.0;
		ascii_num++;
	}
    ascii_buf[2]=ascii_num+48;
    ascii_num=0;
    while(num>=100.0){
		num=num-100.0;
		ascii_num++;
	}
    ascii_buf[3]=ascii_num+48;
    ascii_num=0;
    while(num>=10.0){
		num=num-10.0;
		ascii_num++;
	}
    ascii_buf[4]=ascii_num+48;
    ascii_num=0;
    while(num>=1.0){
		num=num-1.0;
		ascii_num++;
	}
    ascii_buf[5]=ascii_num+48;
    ascii_buf[6]='.';
    ascii_num=0;
    while(num>=0.1){
		num=num-0.1;
		ascii_num++;
	}
    ascii_buf[7]=ascii_num+48;
    ascii_num=0;
    while(num>=0.01){
		num=num-0.01;
		ascii_num++;
	}
    ascii_buf[8]=ascii_num+48;
    if(kaigyou_enable){
        ascii_buf[9]='\n';
        ascii_buf[10]=0;
    }else{
        ascii_buf[9]=0;
    }
}

char ten_bit_test(char data,char keta){
	char bit_data[3]={0,0,0};
	while(data>=100){
		data=data-100;
		bit_data[2]++;
	}
	while(data>=10){
		data=data-10;
		bit_data[1]++;
	}
	while(data>=1){
		data--;
		bit_data[0]++;
	}
	return bit_data[keta];
}

char ten_bit_test_unsignedint(unsigned int data,char keta){
	char bit_data[5]={0,0,0,0,0};
    while(data>=10000){
		data=data-10000;
		bit_data[4]++;
	}
    while(data>=1000){
		data=data-1000;
		bit_data[3]++;
	}
	while(data>=100){
		data=data-100;
		bit_data[2]++;
	}
	while(data>=10){
		data=data-10;
		bit_data[1]++;
	}
	while(data>=1){
		data--;
		bit_data[0]++;
	}
	return bit_data[keta];
}

signed int abs_int(signed int data){
    if(data<0){
        return -data;
    }
    return data;
}

char bit_clear(char number,char bit_place){
    if(bit_test(number,bit_place)){
        number-=(1<<bit_place);
    }
    return number;
}

char bit_test(char number,char bit_place){
    char i;
    i=number & (0b00000001<<bit_place);
    if(i>0){
        return 1;
    }
    return 0;
}

int bit_test_int(int number,char bit_place){
    int i;
    i=number & (0b00000001<<bit_place);
    if(i>0){
        return 1;
    }
    return 0;
}

#endif	/* MELONPAN1_LIB_VER1_20_H */