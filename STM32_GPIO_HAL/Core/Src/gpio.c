/*
 * gpio.c
 *
 *  Created on: Jun 11, 2026
 *      Author: shoja
 */

#include "stm32f4xx_hal.h"

/* NOTE: HAL_Init() must be called before these functions so that
 * SysTick is running and HAL_Delay() works correctly.
 */

void LED_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable GPIOA clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /* PA5 configuration */
    GPIO_InitStruct.Pin       = GPIO_PIN_5;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;   /* Push-pull */
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;   /* Low speed */
    GPIO_InitStruct.Pull      = GPIO_NOPULL;           /* No pull-up, no pull-down */
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void OUTPUT_init_PB8(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable GPIOB clock */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* PB8 configuration */
    GPIO_InitStruct.Pin       = GPIO_PIN_8;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void OUTPUT_init_PC7(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable GPIOC clock */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* PC7 configuration */
    GPIO_InitStruct.Pin       = GPIO_PIN_7;
    GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void LED_Blink_Fast(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); /* Toggle PA5 */
    HAL_Delay(30);                         /* ~fast blink delay */
}

uint8_t OUTPUT_PB8_Blink_Fast(void)
{
    HAL_Delay(50);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8); /* Toggle PB8 */
    return (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == GPIO_PIN_SET) ? 1 : 0;
}

uint8_t OUTPUT_PC7_Blink_Fast(void)
{
    HAL_Delay(50);
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7); /* Toggle PC7 */
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == GPIO_PIN_SET) ? 1 : 0;
}

void Police_Blink_Fast(void)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7) == GPIO_PIN_SET)
    {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET); /* Turn off PC7 */
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);   /* Turn on PB8 */
    }
    else
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET); /* Turn off PB8 */
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);   /* Turn on PC7 */
    }
    HAL_Delay(100);
}

void BUTTON_init_PC13(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable GPIOC clock */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* PC13 configuration */
    GPIO_InitStruct.Pin       = GPIO_PIN_13;
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;           /* Pull-up */
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;   /* Not critical for input, but good practice */
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

uint8_t BUTTON_Read_PC13(void)
{
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET) ? 1 : 0;
}

uint8_t LED_Reset(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); /* Turn off PA5 */
    return (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) == GPIO_PIN_SET) ? 1 : 0;
}
