#include "leds.h"
#include "errores.h"

#define LEDS_TO_BIT_OFFSET  1
#define BIT_MASK            1
#define LEDS_ALL_OFF        0

static uint16_t * puerto;

uint16_t LedToMask(uint8_t led){

    return (BIT_MASK << (led - LEDS_TO_BIT_OFFSET));
}

void LedsInit(uint16_t * direccion){
    puerto = direccion;
    *puerto = LEDS_ALL_OFF;
}

void LedTurnOn(uint8_t led){
    if(led > 16){
        Alerta("Numero de led invalido");
    } else{
        *puerto |= LedToMask(led);
    }
}

void LedTurnOff(uint8_t led){
    *puerto &= ~LedToMask(led);
}

void LedAllTurnOn(uint16_t * direccion){
    puerto = direccion;
    *puerto |= 0xFFFF;
}

void LedAllTurnOff(uint16_t * direccion){
    puerto = direccion;
    *puerto &= 0x0000;
}

uint8_t LedState(uint8_t led){
    uint8_t state = (LedToMask(led) & *puerto) >> (led - 1);
    if(state){
        return 1;
    }
    return 0;
}