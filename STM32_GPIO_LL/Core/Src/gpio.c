/*
 * gpio.c
 *
 *  Created on: Jun 11, 2026
 *      Author: shoja
 */

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"

void LED_init(void)
{
    /* Enable GPIOA clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

    /* PA5 configuration */
    LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_5, LL_GPIO_SPEED_FREQ_LOW);
    LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_5, LL_GPIO_OUTPUT_PUSHPULL);
    LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_5, LL_GPIO_PULL_NO);
}

void OUTPUT_init_PB8(void)
{
    /* Enable GPIOB clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

    /* PB8 configuration */
    LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinSpeed(GPIOB, LL_GPIO_PIN_8, LL_GPIO_SPEED_FREQ_LOW);
    LL_GPIO_SetPinOutputType(GPIOB, LL_GPIO_PIN_8, LL_GPIO_OUTPUT_PUSHPULL);
    LL_GPIO_SetPinPull(GPIOB, LL_GPIO_PIN_8, LL_GPIO_PULL_NO);
}

void OUTPUT_init_PC7(void)
{
    /* Enable GPIOC clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);

    /* PC7 configuration */
    LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_7, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinSpeed(GPIOC, LL_GPIO_PIN_7, LL_GPIO_SPEED_FREQ_LOW);
    LL_GPIO_SetPinOutputType(GPIOC, LL_GPIO_PIN_7, LL_GPIO_OUTPUT_PUSHPULL);
    LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_7, LL_GPIO_PULL_NO);
}

void LED_Blink_Fast(void)
{
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5); /* Toggle PA5 */
    for (volatile int i = 0; i < 50000; i++); /* Delay */
}

uint8_t OUTPUT_PB8_Blink_Fast(void)
{
    for (volatile int i = 0; i < 50000; i++); /* Delay */
    LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_8); /* Toggle PB8 */
    return LL_GPIO_IsOutputPinSet(GPIOB, LL_GPIO_PIN_8) ? 1 : 0;
}

uint8_t OUTPUT_PC7_Blink_Fast(void)
{
    for (volatile int i = 0; i < 50000; i++); /* Delay */
    LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_7); /* Toggle PC7 */
    return LL_GPIO_IsOutputPinSet(GPIOC, LL_GPIO_PIN_7) ? 1 : 0;
}

void Police_Blink_Fast(void)
{
    if (LL_GPIO_IsOutputPinSet(GPIOC, LL_GPIO_PIN_7))
    {
        LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_7); /* Turn off PC7 */
        LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_8);     /* Turn on PB8 */
    }
    else
    {
        LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8); /* Turn off PB8 */
        LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_7);   /* Turn on PC7 */
    }
    for (volatile int i = 0; i < 100000; i++); /* Delay */
}

void BUTTON_init_PC13(void)
{
    /* Enable GPIOC clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);

    /* PC13 configuration */
    LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_13, LL_GPIO_MODE_INPUT);
    LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_13, LL_GPIO_PULL_UP);
    LL_GPIO_SetPinSpeed(GPIOC, LL_GPIO_PIN_13, LL_GPIO_SPEED_FREQ_LOW);
}

uint8_t BUTTON_Read_PC13(void)
{
    return LL_GPIO_IsInputPinSet(GPIOC, LL_GPIO_PIN_13) ? 1 : 0;
}

uint8_t LED_Reset(void)
{
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5); /* Turn off PA5 */
    return LL_GPIO_IsOutputPinSet(GPIOA, LL_GPIO_PIN_5) ? 1 : 0;
}
