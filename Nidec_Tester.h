/* 
 * File:   Nidec_Tester.h
 * Author: Jeffrey
 *
 * Created on January 7, 2021, 4:08 AM
 */

#ifndef NIDEC_TESTER_H
#define	NIDEC_TESTER_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define PIN_SWITCH_LO       LATCbits.LATC0
#define PIN_SWITCH_HI       LATCbits.LATC1
#define PIN_PWM_CTL         LATCbits.LATC3
#define PIN_LED_LO_FAIL     LATCbits.LATC7
#define PIN_LED_LO_PASS     LATCbits.LATC6
#define PIN_LED_HI_PASS     LATCbits.LATC5
#define PIN_LED_HI_FAIL     LATCbits.LATC4
#define PIN_TACH_BACK       LATBbits.LATB0
#define PIN_TACH_FRONT      LATBbits.LATB1
#define TRUE                1
#define FALSE               0
#define LED_ON              0
#define LED_OFF             1

uint16_t tach_front_acc;
uint16_t tach_back_acc;
extern const uint8_t FAN_RPM_LIMITS_LOW[2];
extern const uint8_t FAN_RPM_LIMITS_HIGH[2];

void ACCUMULATE_Tach_Front(void);
void ACCUMULATE_Tach_Back(void);
bool GET_Lo_Pass(void);
bool GET_Hi_Pass(void);
bool GET_Tach_Pass(void);
bool GET_Tach_Front_Pass(void);
bool GET_Tach_Back_Pass(void);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* NIDEC_TESTER_H */

