
#include "Nidec_Tester.h"

uint16_t tach_front_acc = 0;
uint16_t tach_back_acc = 0;
const uint8_t FAN_RPM_LIMITS_LOW[2] = {40, 125};
const uint8_t FAN_RPM_LIMITS_HIGH[2] = {60, 145};

void ACCUMULATE_Tach_Front(){
    tach_front_acc++;
}

void ACCUMULATE_Tach_Back(){
    tach_back_acc++;
}

bool GET_Lo_Pass(){
    return (tach_front_acc >= FAN_RPM_LIMITS_LOW[0]) && (tach_front_acc <= FAN_RPM_LIMITS_HIGH[0]) &&
            (tach_back_acc >= FAN_RPM_LIMITS_LOW[0]) && (tach_back_acc <= FAN_RPM_LIMITS_HIGH[0]);
}

bool GET_Hi_Pass(){
    bool result = (tach_front_acc >= FAN_RPM_LIMITS_LOW[1]) && (tach_front_acc <= FAN_RPM_LIMITS_HIGH[1]) &&
            (tach_back_acc >= FAN_RPM_LIMITS_LOW[1]) && (tach_back_acc <= FAN_RPM_LIMITS_HIGH[1]);
    tach_front_acc = 0;
    tach_back_acc = 0;
    return result;
}

bool GET_Tach_Pass() {
    bool result = GET_Tach_Front_Pass() && GET_Tach_Back_Pass();
    tach_front_acc = 0;
    tach_back_acc = 0;
    return result;
}

bool GET_Tach_Front_Pass(){
    if (PIN_SWITCH_HI) {
        return (tach_front_acc >= FAN_RPM_LIMITS_LOW[1]) && (tach_front_acc <= FAN_RPM_LIMITS_HIGH[1]);
    } else {
        return (tach_front_acc >= FAN_RPM_LIMITS_LOW[0]) && (tach_front_acc <= FAN_RPM_LIMITS_HIGH[0]);
    }
}

bool GET_Tach_Back_Pass(){
    if (PIN_SWITCH_HI) {
        return (tach_back_acc >= FAN_RPM_LIMITS_LOW[1]) && (tach_back_acc <= FAN_RPM_LIMITS_HIGH[1]);
    } else {
        return (tach_back_acc >= FAN_RPM_LIMITS_LOW[0]) && (tach_back_acc <= FAN_RPM_LIMITS_HIGH[0]);
    }
}
