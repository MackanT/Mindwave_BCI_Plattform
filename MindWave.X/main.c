/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1779
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

// Background Timer / Blinking
long int counter = 0;
int Data[512] = {0};
int peakDetected = 0;
long peakTime = 0;
int peakP, peakM;
int j = 0, n = 0;

// checksum variables
char generatedChecksum = 0;
char checksum = 0; 
unsigned char payloadLength = 0;
char payloadData[64] = {0};
char eegBands[8] = {0};
char poorQuality = 0;
char attention = 0;
char meditation = 0;

unsigned int ByteRead;

// system variables
long lastReceivedPacket = 0;

unsigned char readByte(){
    while (true) {
        if (EUSART_DataReady){
            return EUSART_Read();
        }
    }
}

void printDebug(){
    EUSART_Write('Q');
    EUSART_Write(':');
    EUSART_Write(' ');
    EUSART_Write(poorQuality);
    EUSART_Write(0x0d);
    EUSART_Write(0x0a);
    EUSART_Write('A');
    EUSART_Write(':');
    EUSART_Write(' ');
    EUSART_Write(meditation);
    EUSART_Write(0x0d);
    EUSART_Write(0x0a);
}

void forwards(){
    M_RB_SetHigh();
    M_RF_SetLow();
    M_LB_SetHigh();
    M_LF_SetLow();
}

void backwards(){
    M_RB_SetLow();
    M_RF_SetHigh();
    M_LB_SetLow();
    M_LF_SetHigh();
}

void turn_right(){
    M_RB_SetLow();
    M_RF_SetHigh();
    M_LB_SetHigh();
    M_LF_SetLow();
}

void turn_left(){
    M_RB_SetHigh();
    M_RF_SetLow();
    M_LB_SetLow();
    M_LF_SetHigh();
}

void stop(){
    M_RB_SetLow();
    M_RF_SetLow();
    M_LB_SetLow();
    M_LF_SetLow();
}

void __interrupt() timer_0(void){
    if(INTCONbits.TMR0IF == 1){
        TMR0_ISR();
        counter++;
    }
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_Initialize();

    while (1)
    {
        long Hilf = 0;
        if (readByte() == 0xaa){
            if (readByte() == 0xaa){
                
                int payloadLength = readByte();
                if (payloadLength > 169){
                    return;
                } 
                
                generatedChecksum = 0;
                for(int i = 0; i < payloadLength; i++) {  
                    payloadData[i] = readByte();            //Read payload into memory
                    generatedChecksum += payloadData[i];
                } 
                
                checksum = readByte();                      //Read checksum byte from stream      
                generatedChecksum = 255 - generatedChecksum;
                
                if(checksum == generatedChecksum) {    
  
                    poorQuality = 200;
                    attention = 0;
                    meditation = 0;
                    
                    // Clear old EEG-data -> 
                    for(uint8_t i = 0; i < 8; i++) {
                        eegBands[i] = 0;
                    }
  
                    for(int i = 0; i < payloadLength; i++) {    // Parse the payload
                      switch (payloadData[i]) {
                      case 2:         
                        poorQuality = payloadData[++i];        
                        break;
                      case 4:
                        attention = payloadData[++i];                        
                        break;
                      case 5:
                        meditation = payloadData[++i];
                        break;
                      case 0x80:
                        if (readByte()==2){
                              Hilf =  ((long)readByte() * 256 + (long)readByte());
                              if (Hilf > 32767) Hilf -= (long)(65535);
                              Data[j] = (int)Hilf;
                              peakP += Data[(512 + j - 71) % 512];
                              peakP -= Data[(512 + j - 50 - 71) % 512];
                              if((peakP > 3000) && (Data[(512 + j - 70) % 512] < 0) && (peakP < 13000)){
                                  if (counter - peakTime > 100){
                                      peakM=0;
                                      for(int k = 1; k <= 70; k++){
                                          peakM +=  (int)(Data[(512 + j  + k - 70) % 512]);
                                      }
                                      if(peakM < -3000 && peakM > -11000){
                                          if ((counter - peakTime) < 600)n++; else n = 1;
                                          peakTime=counter;
                                          peakDetected = 1;
                                      }
                                            
                                  }
                              }
                              
                          }                        
                        break;
                      case 0x83:
                        // Used to collect individual values for the different wavetypes
                        i++;
                        for (int j = 0; j < 8; j++) {
                            eegBands[j] = ((uint32_t)payloadData[++i] << 16) | ((uint32_t)payloadData[++i] << 8) | (uint32_t)payloadData[++i];
                        }
                        break;
                      default:
                        break;
                      } // switch
                    } // for loop
                       
                    if (poorQuality == 200) {
                        1;
                        //EUSART_Write('F');
                        //EUSART_Write(0x0d);
                        //EUSART_Write(0x0a);
                    } else { 
                        //printDebug();  
                        if (meditation > 60){
                            turn_left();
                        } else {
                            stop();
                        }
                        
                        if((counter-peakTime)>700 && peakDetected == 1){
                            if(n==1){
                                G5_Toggle();
                            }
                            if(n==2){
                                G10_Toggle();
                            }
                            if(n==3){
                                G1_Toggle();
                            }
                            peakDetected=0;
                        }
                    }
  
                }    
            }
        }
    }   
}
/**
 End of File
*/