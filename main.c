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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F25K22
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
#include "Nidec_Tester.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    PIN_LED_LO_FAIL = LED_OFF;
    PIN_LED_LO_PASS = LED_OFF;
    PIN_LED_HI_PASS = LED_OFF;
    PIN_LED_HI_FAIL = LED_OFF;
    
    while (1)
    {
        // Add your application code
        __delay_ms(1000);
//        PIN_LED_HI_FAIL = ~PIN_LED_HI_FAIL;
//        PIN_LED_LO_PASS = ~PIN_LED_LO_PASS;
        
        bool lo = GET_Lo_Pass();
        bool hi = GET_Hi_Pass();
        
        PIN_LED_HI_FAIL = LED_ON;
        PIN_LED_HI_PASS = LED_OFF;
        PIN_LED_LO_FAIL = LED_ON;
        PIN_LED_LO_PASS = LED_OFF;
        
        if(lo) {
            PIN_LED_HI_FAIL = LED_OFF;
            PIN_LED_HI_PASS = LED_OFF;
            PIN_LED_LO_FAIL = LED_OFF;
            PIN_LED_LO_PASS = LED_ON;
        }
        
        if(hi) {
            PIN_LED_HI_FAIL = LED_OFF;
            PIN_LED_HI_PASS = LED_ON;
            PIN_LED_LO_FAIL = LED_OFF;
            PIN_LED_LO_PASS = LED_OFF;
        }
        
//        bool pass = GET_Tach_Pass();
//    
//        if (PIN_SWITCH_LO) {
//            PIN_LED_HI_FAIL = pass ? LED_OFF : LED_ON;
//            PIN_LED_HI_PASS = pass ? LED_ON : LED_OFF;
//            PIN_LED_LO_FAIL = LED_OFF;
//            PIN_LED_LO_PASS = LED_OFF;
//        } else {
//            PIN_LED_LO_FAIL = pass ? LED_OFF : LED_ON;
//            PIN_LED_LO_PASS = pass ? LED_ON : LED_OFF;
//            PIN_LED_HI_FAIL = LED_OFF;
//            PIN_LED_HI_PASS = LED_OFF;
//        }
    }
}
/**
 End of File
*/