#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>
#include <stdbool.h>
/**
 * @brief Configura la biblioteca y apaga todos los LEDs.
 * 
 * @param direccion Direccion del puerto GPIO que controla los LEDs.
 */
void LedsInit(uint16_t * direccion);

/**
 * @brief Prende un LED
 * 
 * @param led Numero de LED a prender (1 al 16).
 */
void LedTurnOn(uint8_t led);

/**
 * @brief Apaga un LED.
 * 
 * @param led Numero de LED a apagar (1 al 16).
 */
void LedTurnOff(uint8_t led);

/**
 * @brief Prende todos los LEDs de una vez.
 * 
 */
void LedAllTurnOn(void);

/**
 * @brief Apaga todos los LEDs de una vez.
 * 
 */
void LedAllTurnOff(void); 

/**
 * @brief Consulta el estado de un LED
 * 
 * @param led Numro de led a consultar.
 * @return uint8_t Devuelve el estado del LED. 1: Prendido, 0: Apagado
 */
uint8_t LedState(uint8_t led);

#endif