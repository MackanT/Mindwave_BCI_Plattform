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

// get/set AT_MODE aliases
#define AT_MODE_TRIS                 TRISAbits.TRISA1
#define AT_MODE_LAT                  LATAbits.LATA1
#define AT_MODE_PORT                 PORTAbits.RA1
#define AT_MODE_WPU                  WPUAbits.WPUA1
#define AT_MODE_OD                   ODCONAbits.ODA1
#define AT_MODE_ANS                  ANSELAbits.ANSA1
#define AT_MODE_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define AT_MODE_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define AT_MODE_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define AT_MODE_GetValue()           PORTAbits.RA1
#define AT_MODE_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define AT_MODE_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define AT_MODE_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define AT_MODE_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define AT_MODE_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define AT_MODE_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define AT_MODE_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define AT_MODE_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set AT_POWER aliases
#define AT_POWER_TRIS                 TRISBbits.TRISB0
#define AT_POWER_LAT                  LATBbits.LATB0
#define AT_POWER_PORT                 PORTBbits.RB0
#define AT_POWER_WPU                  WPUBbits.WPUB0
#define AT_POWER_OD                   ODCONBbits.ODB0
#define AT_POWER_ANS                  ANSELBbits.ANSB0
#define AT_POWER_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define AT_POWER_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define AT_POWER_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define AT_POWER_GetValue()           PORTBbits.RB0
#define AT_POWER_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define AT_POWER_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define AT_POWER_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define AT_POWER_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define AT_POWER_SetPushPull()        do { ODCONBbits.ODB0 = 0; } while(0)
#define AT_POWER_SetOpenDrain()       do { ODCONBbits.ODB0 = 1; } while(0)
#define AT_POWER_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define AT_POWER_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

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