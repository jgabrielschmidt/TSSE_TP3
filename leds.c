#include "leds.h"
#include "errores.h"

#define LEDS_TO_BIT_OFFSET    1
#define BIT_MASK              1
#define LEDS_ALL_OFF          0
#define CANTIDAD_MAX_LEDS     16
#define CORRECCION_INDICE_LED 1
#define CANTIDAD_MIN_LED      1

#define MASCARA_FFFF 0xFFFF
#define MASCARA_NULA 0x0000


static uint16_t * puerto;


bool LedNumberControl(uint8_t led){
    if(led > CANTIDAD_MAX_LEDS || led < CANTIDAD_MIN_LED){
        return false;
    } else{
        return true;
    }
}

uint16_t LedToMask(uint8_t led){
    if(!LedNumberControl(led)){
        Alerta("Numero de led invalido");
    }else{
        return (BIT_MASK << (led - LEDS_TO_BIT_OFFSET));
    }
}

void LedsInit(uint16_t * direccion){
    puerto = direccion;
    LedAllTurnOff();
}

void LedTurnOn(uint8_t led){
    if(!LedNumberControl(led)){
        Alerta("Numero de led invalido");
    }else{
        *puerto |= LedToMask(led);
    }
}

void LedTurnOff(uint8_t led){
    if(!LedNumberControl(led)){
        Alerta("Numero de led invalido");
    }else{
        *puerto &= ~LedToMask(led);
    }
}

void LedAllTurnOn(void){
    *puerto |= MASCARA_FFFF;
}

void LedAllTurnOff(void){
    *puerto &= MASCARA_NULA;
}

uint8_t LedState(uint8_t led){
    if(!LedNumberControl(led)){
        Alerta("Numero de led invalido");
    }else{
        uint8_t state = (LedToMask(led) & *puerto) >> (led - CORRECCION_INDICE_LED);
        if(state){
            return true;
        }
        return false;
    }
}