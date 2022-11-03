#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "ADC.h"
#include "UART.h"


int main(){
  init();
  int analgue_reading;
unsigned char buffer[4];
  while(1)
  {
    LDR();
    LIGHT();
    analgue_reading=Adc_ReadChannel(3);
    itoa(analgue_reading,buffer,10);
    Uart_SendString(buffer);
    Uart_SendString("\n");


  }
}

void init(){
    LDR();
    LIGHT();
    Uart_Init();
}

void LDR(void){
  float INTENSITY;
  Dio_SetPinDirection('D',4,1);//sets a pin direction
  Dio_SetPinDirection('C',2,0);

  Adc_Init();

  INTENSITY = Adc_ReadChannel(2);// reads the adc channel

  

  if(INTENSITY>500){
    

    
    Dio_SetPortDirection('D',4,1);
    //PORTB=0b00000100;
  }
    else
    Dio_SetPortDirection('D',4,0);
    
 
}

void LIGHT(void){
float volt;
  Dio_SetPinDirection('D',3,1);
 
  Dio_SetPinDirection('C',3,0);

  Adc_Init();

  volt = Adc_ReadChannel(3);

  
  if(volt>550){
    

    
    Dio_SetPortDirection('D',3,1);
   
   
  
    

  }
    else
    Dio_SetPortDirection('D',3,0);

    
 
}

  


