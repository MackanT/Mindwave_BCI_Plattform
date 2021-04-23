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
//long int counter = 0;
//int Data[512] = {0};
//int peakDetected = 0;
//long peakTime = 0;
//int peakP, peakM;
//int j = 0, n = 0;

// checksum variables
char generatedChecksum = 0;
char checksum = 0; 
unsigned char payloadLength = 0;
char payloadData[256] = {0};
char eegBands[8] = {0};
char poorQuality = 0;
char attention = 0;
char meditation = 0;

int time_delay = 5;
int time_stop = 3;
int data_counter = 0;
int avg_med = 0;
int avg_att = 0;

unsigned int ByteRead;

unsigned char readByte(){
    while (true) {
        if (EUSART_DataReady){
            return EUSART_Read();
        }
    }
}

void print_int(int comp){
    if (comp < 35){
        EUSART_Write(comp + 35);
        EUSART_Write(65);
    } else if (comp < 126){
        EUSART_Write(comp);
        EUSART_Write(66);
    } else if (comp < 217){
        EUSART_Write(comp - 91);
        EUSART_Write(67);
    } else {
        EUSART_Write(comp - 182);
        EUSART_Write(68);
    }
}

void outputFile(){
    print_int(poorQuality);
    EUSART_Write(',');
    print_int(meditation);
    EUSART_Write(',');
    print_int(attention);
    EUSART_Write(',');
    print_int(eegBands[0]);
    EUSART_Write(',');
    print_int(eegBands[1]);
    EUSART_Write(',');
    print_int(eegBands[2]);
    EUSART_Write(',');
    print_int(eegBands[3]);
    EUSART_Write(',');
    print_int(eegBands[4]);
    EUSART_Write(',');
    print_int(eegBands[5]);
    EUSART_Write(',');
    print_int(eegBands[6]);
    EUSART_Write(',');
    print_int(eegBands[7]);
    EUSART_Write(',');
    EUSART_Write(0x0d);
    EUSART_Write(0x0a);
}

void bootUpVisualizer(){
    G1_Toggle();
    __delay_ms(100);
    G2_Toggle();
    __delay_ms(100);
    G3_Toggle();
    __delay_ms(100);
    G1_Toggle();
    __delay_ms(100);
    G4_Toggle();
    __delay_ms(100);
    G2_Toggle();
    __delay_ms(100);
    G5_Toggle();
    __delay_ms(100);
    G3_Toggle();
    __delay_ms(100);
    G6_Toggle();
    __delay_ms(100);
    G4_Toggle();
    __delay_ms(100);
    G7_Toggle();
    __delay_ms(100);
    G5_Toggle();
    __delay_ms(100);
    G8_Toggle();
    __delay_ms(100);
    G6_Toggle();
    __delay_ms(100);
    G9_Toggle();
    __delay_ms(100);
    G7_Toggle();
    __delay_ms(200);
    G8_Toggle();
    __delay_ms(200);
    G9_Toggle();
    
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

void move_system() {
    
    EUSART_Write('M');
    EUSART_Write(':');
    print_int(avg_med);
    EUSART_Write(',');
    EUSART_Write('A');
    EUSART_Write(':');
    print_int(avg_att);
    EUSART_Write(0x0d);
    EUSART_Write(0x0a);
    
    if (avg_med > avg_att && avg_med > 75) {
        forwards();
    } else if (attention > 65) {
        turn_right();    
    } else {
        stop();
    }
}

//void __interrupt() timer_0(void){
//    if(INTCONbits.TMR0IF == 1){
//        TMR0_ISR();
//        counter++;
//    }
//}

//uint32t readDelta()

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
//    TMR0_Initialize();
    
    bootUpVisualizer();
    
    EUSART_Write('S');
    EUSART_Write('T');
    EUSART_Write('A');
    EUSART_Write('R');
    EUSART_Write('T');
    EUSART_Write('I');
    EUSART_Write('N');
    EUSART_Write('G');
    EUSART_Write(0x0d);
    EUSART_Write(0x0a);
    
    while (1)
    {
//        if(j >= 512) j = 0;
//        long Hilf = 0;
        if (readByte() == 0xaa){
            if (readByte() == 0xaa){

                int payloadLength = readByte();
                if (payloadLength > 169) continue;

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
                    for(int i = 0; i < 8; i++) eegBands[i] = 0;

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
                                i += 3;
//                                        if (payloadData[++i] == 0x02){
//                                        Hilf =  ((long)payloadData[++i] & 0x0F) << 8 | (long)payloadData[++i];
//                                        Data[j] = (int)Hilf;
//                                        peakP += Data[(512 + j - 71) % 512];
//                                        peakP -= Data[(512 + j - 50 - 71) % 512];
//                                        if((peakP > 200) && (Data[(512 + j - 70) % 512] < 0) && (peakP < 700)){
//                                            if (counter - peakTime > 100){
//                                                peakM = 0;
//                                                for(int k = 1; k <= 70; k++){
//                                                    peakM +=  (int)(Data[(512 + j  + k - 70) % 512]);
//                                                }
//                                                if(peakM < -200 && peakM > -700){
//                                                    if ((counter - peakTime) < 600)n++; else n = 1;
//                                                    peakTime=counter;
//                                                    peakDetected = 1;
//                                                }
//                                                      
//                                            }
//                                        }
//
//                                    }   
                              break;
                          case 0x83:
                              i++;
                              for (int k = 0; k < 8; k++) {
                                  eegBands[k] = ((uint32_t)payloadData[++i] << 16) | ((uint32_t)payloadData[++i] << 8) | (uint32_t)payloadData[++i];
                              }
                              break;
                            default:
                              break;
                            } // switch
                    } // for loop
//                        j++;
 
                    if (poorQuality == 200 && payloadLength == 4) {
                        1;
                    } else if (poorQuality == 200)  { 
                        EUSART_Write('F');
                        EUSART_Write(0x0d);
                        EUSART_Write(0x0a);
                    } else {
                        outputFile(); 
                        data_counter += 1;
                        avg_med += meditation;
                        avg_att += attention;
                        
                        data_counter %= time_delay;
                        
                        if (data_counter == 0) {                            
                            avg_med /= time_delay;
                            avg_att /= time_delay;
                            move_system();
                        } else if (data_counter == time_stop){
                            stop();
                        }

//                            if((counter-peakTime)>700 && peakDetected == 1){
//                                if(n==1){
//                                    EUSART_Write('B');
//                                    EUSART_Write('B');
//                                    EUSART_Write('B');
//                                    EUSART_Write(0x0d);
//                                    EUSART_Write(0x0a);
//                                }
//                                if(n==2){
//                                    1;
//                                }
//                                if(n==3){
//                                    1;
//                                }
//                                peakDetected=0;
//                            }
                    }
//                        } else {
//                            EUSART_Write('C');
//                            EUSART_Write('-');
//                            EUSART_Write('E');
//                            EUSART_Write('R');
//                            EUSART_Write('R');
//                            EUSART_Write('O');
//                            EUSART_Write('R');
//                            EUSART_Write(0x0d);
//                            EUSART_Write(0x0a);
                }
                   
            }
        }
    }   
}
/**
 End of File
*/