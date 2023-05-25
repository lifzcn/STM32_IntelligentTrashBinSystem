#ifndef __HCSR04_H__
#define __HCSR04_H__

#include "stm32f1xx_hal.h"
#include "main.h"

#define HCSR04_TRIG_1_HIGH HAL_GPIO_WritePin(HCSR04_TRIG_1_GPIO_Port, HCSR04_TRIG_1_Pin, GPIO_PIN_SET)
#define HCSR04_TRIG_1_LOW HAL_GPIO_WritePin(HCSR04_TRIG_1_GPIO_Port, HCSR04_TRIG_1_Pin, GPIO_PIN_RESET)
#define HCSR04_ECHO_1 HAL_GPIO_ReadPin(HCSR04_ECHO_1_GPIO_Port, HCSR04_ECHO_1_Pin)

void HCSR04StartTrigStart_1(void);
void HCSR04_1_TimerFunc(uint8_t mode);
float HCSR04_1_GetDistance_Single(void);
float HCSR04_1_GetDistance_Repeatedly(uint8_t cnt);

#define HCSR04_TRIG_2_HIGH HAL_GPIO_WritePin(HCSR04_TRIG_2_GPIO_Port, HCSR04_TRIG_2_Pin, GPIO_PIN_SET)
#define HCSR04_TRIG_2_LOW HAL_GPIO_WritePin(HCSR04_TRIG_2_GPIO_Port, HCSR04_TRIG_2_Pin, GPIO_PIN_RESET)
#define HCSR04_ECHO_2 HAL_GPIO_ReadPin(HCSR04_ECHO_2_GPIO_Port, HCSR04_ECHO_2_Pin)

void HCSR04StartTrigStart_2(void);
void HCSR04_2_TimerFunc(uint8_t mode);
float HCSR04_2_GetDistance_Single(void);
float HCSR04_2_GetDistance_Repeatedly(uint8_t cnt);

#define HCSR04_TRIG_3_HIGH HAL_GPIO_WritePin(HCSR04_TRIG_3_GPIO_Port, HCSR04_TRIG_3_Pin, GPIO_PIN_SET)
#define HCSR04_TRIG_3_LOW HAL_GPIO_WritePin(HCSR04_TRIG_3_GPIO_Port, HCSR04_TRIG_3_Pin, GPIO_PIN_RESET)
#define HCSR04_ECHO_3 HAL_GPIO_ReadPin(HCSR04_ECHO_3_GPIO_Port, HCSR04_ECHO_3_Pin)

void HCSR04StartTrigStart_3(void);
void HCSR04_3_TimerFunc(uint8_t mode);
float HCSR04_3_GetDistance_Single(void);
float HCSR04_3_GetDistance_Repeatedly(uint8_t cnt);

#define HCSR04_TRIG_4_HIGH HAL_GPIO_WritePin(HCSR04_TRIG_4_GPIO_Port, HCSR04_TRIG_4_Pin, GPIO_PIN_SET)
#define HCSR04_TRIG_4_LOW HAL_GPIO_WritePin(HCSR04_TRIG_4_GPIO_Port, HCSR04_TRIG_4_Pin, GPIO_PIN_RESET)
#define HCSR04_ECHO_4 HAL_GPIO_ReadPin(HCSR04_ECHO_4_GPIO_Port, HCSR04_ECHO_4_Pin)

void HCSR04StartTrigStart_4(void);
void HCSR04_4_TimerFunc(uint8_t mode);
float HCSR04_4_GetDistance_Single(void);
float HCSR04_4_GetDistance_Repeatedly(uint8_t cnt);

#endif
