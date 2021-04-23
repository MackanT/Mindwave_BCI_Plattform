/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1779
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set KEY_AT aliases
#define KEY_AT_TRIS                 TRISBbits.TRISB5
#define KEY_AT_LAT                  LATBbits.LATB5
#define KEY_AT_PORT                 PORTBbits.RB5
#define KEY_AT_WPU                  WPUBbits.WPUB5
#define KEY_AT_OD                   ODCONBbits.ODB5
#define KEY_AT_ANS                  ANSELBbits.ANSB5
#define KEY_AT_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define KEY_AT_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define KEY_AT_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define KEY_AT_GetValue()           PORTBbits.RB5
#define KEY_AT_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define KEY_AT_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define KEY_AT_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define KEY_AT_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define KEY_AT_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define KEY_AT_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define KEY_AT_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define KEY_AT_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)

// get/set G9 aliases
#define G9_TRIS                 TRISCbits.TRISC2
#define G9_LAT                  LATCbits.LATC2
#define G9_PORT                 PORTCbits.RC2
#define G9_WPU                  WPUCbits.WPUC2
#define G9_OD                   ODCONCbits.ODC2
#define G9_ANS                  ANSELCbits.ANSC2
#define G9_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define G9_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define G9_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define G9_GetValue()           PORTCbits.RC2
#define G9_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define G9_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define G9_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define G9_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define G9_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define G9_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define G9_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define G9_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set G8 aliases
#define G8_TRIS                 TRISCbits.TRISC3
#define G8_LAT                  LATCbits.LATC3
#define G8_PORT                 PORTCbits.RC3
#define G8_WPU                  WPUCbits.WPUC3
#define G8_OD                   ODCONCbits.ODC3
#define G8_ANS                  ANSELCbits.ANSC3
#define G8_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define G8_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define G8_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define G8_GetValue()           PORTCbits.RC3
#define G8_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define G8_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define G8_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define G8_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define G8_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define G8_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define G8_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define G8_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set G3 aliases
#define G3_TRIS                 TRISCbits.TRISC4
#define G3_LAT                  LATCbits.LATC4
#define G3_PORT                 PORTCbits.RC4
#define G3_WPU                  WPUCbits.WPUC4
#define G3_OD                   ODCONCbits.ODC4
#define G3_ANS                  ANSELCbits.ANSC4
#define G3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define G3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define G3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define G3_GetValue()           PORTCbits.RC4
#define G3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define G3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define G3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define G3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define G3_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define G3_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)
#define G3_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define G3_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set G2 aliases
#define G2_TRIS                 TRISCbits.TRISC5
#define G2_LAT                  LATCbits.LATC5
#define G2_PORT                 PORTCbits.RC5
#define G2_WPU                  WPUCbits.WPUC5
#define G2_OD                   ODCONCbits.ODC5
#define G2_ANS                  ANSELCbits.ANSC5
#define G2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define G2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define G2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define G2_GetValue()           PORTCbits.RC5
#define G2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define G2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define G2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define G2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define G2_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define G2_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define G2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define G2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set G1 aliases
#define G1_TRIS                 TRISCbits.TRISC6
#define G1_LAT                  LATCbits.LATC6
#define G1_PORT                 PORTCbits.RC6
#define G1_WPU                  WPUCbits.WPUC6
#define G1_OD                   ODCONCbits.ODC6
#define G1_ANS                  ANSELCbits.ANSC6
#define G1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define G1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define G1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define G1_GetValue()           PORTCbits.RC6
#define G1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define G1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define G1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define G1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define G1_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define G1_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define G1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define G1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set M_RB aliases
#define M_RB_TRIS                 TRISCbits.TRISC7
#define M_RB_LAT                  LATCbits.LATC7
#define M_RB_PORT                 PORTCbits.RC7
#define M_RB_WPU                  WPUCbits.WPUC7
#define M_RB_OD                   ODCONCbits.ODC7
#define M_RB_ANS                  ANSELCbits.ANSC7
#define M_RB_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define M_RB_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define M_RB_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define M_RB_GetValue()           PORTCbits.RC7
#define M_RB_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define M_RB_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define M_RB_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define M_RB_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define M_RB_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define M_RB_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define M_RB_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define M_RB_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set G7 aliases
#define G7_TRIS                 TRISDbits.TRISD0
#define G7_LAT                  LATDbits.LATD0
#define G7_PORT                 PORTDbits.RD0
#define G7_WPU                  WPUDbits.WPUD0
#define G7_OD                   ODCONDbits.ODD0
#define G7_ANS                  ANSELDbits.ANSD0
#define G7_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define G7_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define G7_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define G7_GetValue()           PORTDbits.RD0
#define G7_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define G7_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define G7_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define G7_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define G7_SetPushPull()        do { ODCONDbits.ODD0 = 0; } while(0)
#define G7_SetOpenDrain()       do { ODCONDbits.ODD0 = 1; } while(0)
#define G7_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define G7_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set G6 aliases
#define G6_TRIS                 TRISDbits.TRISD1
#define G6_LAT                  LATDbits.LATD1
#define G6_PORT                 PORTDbits.RD1
#define G6_WPU                  WPUDbits.WPUD1
#define G6_OD                   ODCONDbits.ODD1
#define G6_ANS                  ANSELDbits.ANSD1
#define G6_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define G6_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define G6_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define G6_GetValue()           PORTDbits.RD1
#define G6_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define G6_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define G6_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define G6_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define G6_SetPushPull()        do { ODCONDbits.ODD1 = 0; } while(0)
#define G6_SetOpenDrain()       do { ODCONDbits.ODD1 = 1; } while(0)
#define G6_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define G6_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set G5 aliases
#define G5_TRIS                 TRISDbits.TRISD2
#define G5_LAT                  LATDbits.LATD2
#define G5_PORT                 PORTDbits.RD2
#define G5_WPU                  WPUDbits.WPUD2
#define G5_OD                   ODCONDbits.ODD2
#define G5_ANS                  ANSELDbits.ANSD2
#define G5_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define G5_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define G5_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define G5_GetValue()           PORTDbits.RD2
#define G5_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define G5_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define G5_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define G5_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define G5_SetPushPull()        do { ODCONDbits.ODD2 = 0; } while(0)
#define G5_SetOpenDrain()       do { ODCONDbits.ODD2 = 1; } while(0)
#define G5_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define G5_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set G4 aliases
#define G4_TRIS                 TRISDbits.TRISD3
#define G4_LAT                  LATDbits.LATD3
#define G4_PORT                 PORTDbits.RD3
#define G4_WPU                  WPUDbits.WPUD3
#define G4_OD                   ODCONDbits.ODD3
#define G4_ANS                  ANSELDbits.ANSD3
#define G4_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define G4_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define G4_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define G4_GetValue()           PORTDbits.RD3
#define G4_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define G4_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define G4_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define G4_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define G4_SetPushPull()        do { ODCONDbits.ODD3 = 0; } while(0)
#define G4_SetOpenDrain()       do { ODCONDbits.ODD3 = 1; } while(0)
#define G4_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define G4_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set M_RF aliases
#define M_RF_TRIS                 TRISDbits.TRISD4
#define M_RF_LAT                  LATDbits.LATD4
#define M_RF_PORT                 PORTDbits.RD4
#define M_RF_WPU                  WPUDbits.WPUD4
#define M_RF_OD                   ODCONDbits.ODD4
#define M_RF_ANS                  ANSELDbits.ANSD4
#define M_RF_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define M_RF_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define M_RF_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define M_RF_GetValue()           PORTDbits.RD4
#define M_RF_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define M_RF_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define M_RF_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define M_RF_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define M_RF_SetPushPull()        do { ODCONDbits.ODD4 = 0; } while(0)
#define M_RF_SetOpenDrain()       do { ODCONDbits.ODD4 = 1; } while(0)
#define M_RF_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define M_RF_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set M_LB aliases
#define M_LB_TRIS                 TRISDbits.TRISD5
#define M_LB_LAT                  LATDbits.LATD5
#define M_LB_PORT                 PORTDbits.RD5
#define M_LB_WPU                  WPUDbits.WPUD5
#define M_LB_OD                   ODCONDbits.ODD5
#define M_LB_ANS                  ANSELDbits.ANSD5
#define M_LB_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define M_LB_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define M_LB_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define M_LB_GetValue()           PORTDbits.RD5
#define M_LB_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define M_LB_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define M_LB_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define M_LB_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define M_LB_SetPushPull()        do { ODCONDbits.ODD5 = 0; } while(0)
#define M_LB_SetOpenDrain()       do { ODCONDbits.ODD5 = 1; } while(0)
#define M_LB_SetAnalogMode()      do { ANSELDbits.ANSD5 = 1; } while(0)
#define M_LB_SetDigitalMode()     do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set M_LF aliases
#define M_LF_TRIS                 TRISDbits.TRISD6
#define M_LF_LAT                  LATDbits.LATD6
#define M_LF_PORT                 PORTDbits.RD6
#define M_LF_WPU                  WPUDbits.WPUD6
#define M_LF_OD                   ODCONDbits.ODD6
#define M_LF_ANS                  ANSELDbits.ANSD6
#define M_LF_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define M_LF_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define M_LF_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define M_LF_GetValue()           PORTDbits.RD6
#define M_LF_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define M_LF_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define M_LF_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define M_LF_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define M_LF_SetPushPull()        do { ODCONDbits.ODD6 = 0; } while(0)
#define M_LF_SetOpenDrain()       do { ODCONDbits.ODD6 = 1; } while(0)
#define M_LF_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define M_LF_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/