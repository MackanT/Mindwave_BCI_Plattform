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

// get/set LED aliases
#define LED_TRIS                 TRISBbits.TRISB1
#define LED_LAT                  LATBbits.LATB1
#define LED_PORT                 PORTBbits.RB1
#define LED_WPU                  WPUBbits.WPUB1
#define LED_OD                   ODCONBbits.ODB1
#define LED_ANS                  ANSELBbits.ANSB1
#define LED_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED_GetValue()           PORTBbits.RB1
#define LED_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONBbits.ODB1 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONBbits.ODB1 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set LEFT_B aliases
#define LEFT_B_TRIS                 TRISCbits.TRISC2
#define LEFT_B_LAT                  LATCbits.LATC2
#define LEFT_B_PORT                 PORTCbits.RC2
#define LEFT_B_WPU                  WPUCbits.WPUC2
#define LEFT_B_OD                   ODCONCbits.ODC2
#define LEFT_B_ANS                  ANSELCbits.ANSC2
#define LEFT_B_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LEFT_B_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LEFT_B_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LEFT_B_GetValue()           PORTCbits.RC2
#define LEFT_B_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LEFT_B_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LEFT_B_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LEFT_B_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LEFT_B_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define LEFT_B_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define LEFT_B_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LEFT_B_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LEFT_F aliases
#define LEFT_F_TRIS                 TRISCbits.TRISC3
#define LEFT_F_LAT                  LATCbits.LATC3
#define LEFT_F_PORT                 PORTCbits.RC3
#define LEFT_F_WPU                  WPUCbits.WPUC3
#define LEFT_F_OD                   ODCONCbits.ODC3
#define LEFT_F_ANS                  ANSELCbits.ANSC3
#define LEFT_F_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LEFT_F_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LEFT_F_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LEFT_F_GetValue()           PORTCbits.RC3
#define LEFT_F_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LEFT_F_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LEFT_F_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LEFT_F_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LEFT_F_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define LEFT_F_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define LEFT_F_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LEFT_F_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set RIGHT_B aliases
#define RIGHT_B_TRIS                 TRISDbits.TRISD0
#define RIGHT_B_LAT                  LATDbits.LATD0
#define RIGHT_B_PORT                 PORTDbits.RD0
#define RIGHT_B_WPU                  WPUDbits.WPUD0
#define RIGHT_B_OD                   ODCONDbits.ODD0
#define RIGHT_B_ANS                  ANSELDbits.ANSD0
#define RIGHT_B_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RIGHT_B_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RIGHT_B_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RIGHT_B_GetValue()           PORTDbits.RD0
#define RIGHT_B_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RIGHT_B_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RIGHT_B_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define RIGHT_B_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define RIGHT_B_SetPushPull()        do { ODCONDbits.ODD0 = 0; } while(0)
#define RIGHT_B_SetOpenDrain()       do { ODCONDbits.ODD0 = 1; } while(0)
#define RIGHT_B_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define RIGHT_B_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RIGHT_F aliases
#define RIGHT_F_TRIS                 TRISDbits.TRISD1
#define RIGHT_F_LAT                  LATDbits.LATD1
#define RIGHT_F_PORT                 PORTDbits.RD1
#define RIGHT_F_WPU                  WPUDbits.WPUD1
#define RIGHT_F_OD                   ODCONDbits.ODD1
#define RIGHT_F_ANS                  ANSELDbits.ANSD1
#define RIGHT_F_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RIGHT_F_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RIGHT_F_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RIGHT_F_GetValue()           PORTDbits.RD1
#define RIGHT_F_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RIGHT_F_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RIGHT_F_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define RIGHT_F_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define RIGHT_F_SetPushPull()        do { ODCONDbits.ODD1 = 0; } while(0)
#define RIGHT_F_SetOpenDrain()       do { ODCONDbits.ODD1 = 1; } while(0)
#define RIGHT_F_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define RIGHT_F_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

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