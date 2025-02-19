#include "mbed.h"
#include "arm_book_lib.h"
#define BLINKING_RATE     150ms
int checkforemergency(int alarm);
//initialisepins();
DigitalIn b1(BUTTON1);
DigitalIn d2(D2);
DigitalIn d3(D3);
DigitalIn d4(D4);
DigitalIn d5(D5);
DigitalIn d6(D6);
DigitalIn d7(D7);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


int main()
{

    b1.mode(PullDown);
    d2.mode(PullDown);
    d3.mode(PullDown);
    d4.mode(PullDown);
    d5.mode(PullDown);
    d6.mode(PullDown);
    d7.mode(PullDown);

    led1 = OFF;
    led2 = OFF;
    led3 = OFF;
    int alarm = 0;
    while (true) {

       if (d2==1||d3==1){
            alarm = 1;
             }
             if(alarm==1){
            led2 = ON;
        }
             alarm = checkforemergency(alarm);
            
    }
}
int checkforemergency(int alarm){
    int emergency = 0;
      if(d2==1 && d3==1){
            emergency = 1;
           while(emergency==1){
            led2 = ON, led3 = OFF;
            ThisThread::sleep_for(BLINKING_RATE);
            led2 = OFF, led3 = ON;
            ThisThread::sleep_for(BLINKING_RATE);

            for (int i=0; i<5; i++){
                while (b1==0) {
                    //a= d4;
                // b= d5;
                // c= d6;
                // d= d7;
                    // moving pointer to the next character.    
                    if(d4 == 1 && d5 == 0 && d6 == 0 && d7 == 1){
                        emergency = 0;
                        alarm = 0;
                        led1 = ON;
                    }else{
                        led1 = !led1;
                    ThisThread::sleep_for(BLINKING_RATE);
                    led1 = OFF;
                    }
                }
                    
            } 
        }
    }
return alarm;
}