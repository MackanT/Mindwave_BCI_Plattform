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

// checksum variables
char generatedChecksum = 0;
char checksum = 0; 
unsigned char payloadLength = 0;
char payloadData[64] = {0};
char poorQuality = 0;
char attention = 0;
char meditation = 0;

unsigned int ByteRead;

// system variables
long lastReceivedPacket = 0;
bool bigPacket = false;

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
    RIGHT_B_SetHigh();
    RIGHT_F_SetLow();
    LEFT_B_SetHigh();
    LEFT_F_SetLow();
}

void backwards(){
    RIGHT_B_SetLow();
    RIGHT_F_SetHigh();
    LEFT_B_SetLow();
    LEFT_F_SetHigh();
}

void turn_right(){
    RIGHT_B_SetLow();
    RIGHT_F_SetHigh();
    LEFT_B_SetHigh();
    LEFT_F_SetLow();
}

void turn_left(){
    RIGHT_B_SetHigh();
    RIGHT_F_SetLow();
    LEFT_B_SetLow();
    LEFT_F_SetHigh();
}

void stop(){
    RIGHT_B_SetLow();
    RIGHT_F_SetLow();
    LEFT_B_SetLow();
    LEFT_F_SetLow();
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        
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
  
                    for(int i = 0; i < payloadLength; i++) {    // Parse the payload
                      switch (payloadData[i]) {
                      case 2:
                        i++;            
                        poorQuality = payloadData[i];
                        bigPacket = true;            
                        break;
                      case 4:
                        i++;
                        attention = payloadData[i];                        
                        break;
                      case 5:
                        i++;
                        meditation = payloadData[i];
                        break;
                      case 0x80:
                        i = i + 3;
                        break;
                      case 0x83:
                        i = i + 25;      
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
                            turn_right();
                            LED_SetHigh();
                        } else {
                            stop();
                            LED_SetLow();
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