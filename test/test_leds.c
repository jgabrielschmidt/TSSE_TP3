#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

static uint16_t ledsVirtuales;

void setUp(void){
    LedsInit(&ledsVirtuales);
}

// Despues de la inicializacion todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    LedsInit(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede prender un LED individual.
void test_TurnOnOneLed(void){
    LedTurnOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_TurnOffOneLed(void){
    LedTurnOn(5);
    LedTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se pueden prender y apagar multiples LEDs.
void test_TurnOnAndOffManyLeds(void){
    LedTurnOn(5);
    LedTurnOn(11);
    LedTurnOff(3);
    LedTurnOff(11);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales);
}

// Se puede prender todos los LEDs de una vez.
void test_LedAllTurnOn(void){
    LedAllTurnOn(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se puede apagar todos los LEDs de una vez.
void test_LedAllTurnOff(void){
    LedAllTurnOn(&ledsVirtuales);
    LedAllTurnOff(&ledsVirtuales);  
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede consultar el estado de un LED on.
void test_LedStateOn(void){
    uint8_t led = 5;
    LedTurnOn(led);
    uint8_t state = LedState(led);
    TEST_ASSERT_EQUAL_HEX16(1, state);
}

// Se puede consultar el estado de un LED off.
void test_LedStateOff(void){
    uint8_t led = 5;
    LedTurnOff(led);
    uint8_t state = LedState(led);
    TEST_ASSERT_EQUAL_HEX16(0, state);
}

void test_InvalidUpperLimitTurnOnLed(void){
    RegistrarMensaje_Expect(ALERTA, "LedTurnOn", 0, "Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    LedTurnOn(17);
}