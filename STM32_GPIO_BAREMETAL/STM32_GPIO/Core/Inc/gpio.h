/*
 * gpio.h
 *
 *  Created on: Jun 11, 2026
 *      Author: shoja
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

void LED_init (void);
void LED_Blink_Fast(void);
void OUTPUT_init_PB8 (void);
uint8_t OUTPUT_PB8_Blink_Fast(void);
void OUTPUT_init_PC7 (void);
uint8_t OUTPUT_PC7_Blink_Fast(void);
void Police_Blink_Fast(void);
void BUTTON_init_PC13(void);
uint8_t BUTTON_Read_PC13(void);
uint8_t LED_Reset(void);
#endif /* INC_GPIO_H_ */
