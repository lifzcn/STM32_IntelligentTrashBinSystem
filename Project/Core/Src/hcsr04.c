#include "hcsr04.h"
#include "main.h"
#include "tim.h"

void HCSR04StartTrigStart_1(void)
{
	HCSR04_TRIG_1_HIGH;
	HAL_Delay_us(20);
	HCSR04_TRIG_1_LOW;
}

void HCSR04_1_TimerFunc(uint8_t mode)
{
	if (mode)
	{
		__HAL_TIM_SetCounter(&htim1, 0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_1_GetDistance_Single(void)
{
	HCSR04StartTrigStart_1();
	while (!HCSR04_ECHO_1)
		;
	HCSR04_1_TimerFunc(1);
	while (HCSR04_ECHO_1)
		;
	HCSR04_1_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1)) / 58.0;
}

float HCSR04_1_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += HCSR04_1_GetDistance_Single();
	}
	return sum / cnt;
}

void HCSR04StartTrigStart_2(void)
{
	HCSR04_TRIG_2_HIGH;
	HAL_Delay_us(20);
	HCSR04_TRIG_2_LOW;
}

void HCSR04_2_TimerFunc(uint8_t mode)
{
	if (mode)
	{
		__HAL_TIM_SetCounter(&htim1, 0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_2_GetDistance_Single(void)
{
	HCSR04StartTrigStart_2();
	while (!HCSR04_ECHO_2)
		;
	HCSR04_2_TimerFunc(2);
	while (HCSR04_ECHO_2)
		;
	HCSR04_2_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1)) / 58.0;
}

float HCSR04_2_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += HCSR04_2_GetDistance_Single();
	}
	return sum / cnt;
}

void HCSR04StartTrigStart_3(void)
{
	HCSR04_TRIG_3_HIGH;
	HAL_Delay_us(30);
	HCSR04_TRIG_3_LOW;
}

void HCSR04_3_TimerFunc(uint8_t mode)
{
	if (mode)
	{
		__HAL_TIM_SetCounter(&htim1, 0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_3_GetDistance_Single(void)
{
	HCSR04StartTrigStart_3();
	while (!HCSR04_ECHO_3)
		;
	HCSR04_3_TimerFunc(3);
	while (HCSR04_ECHO_3)
		;
	HCSR04_3_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1)) / 58.0;
}

float HCSR04_3_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += HCSR04_3_GetDistance_Single();
	}
	return sum / cnt;
}

void HCSR04StartTrigStart_4(void)
{
	HCSR04_TRIG_4_HIGH;
	HAL_Delay_us(40);
	HCSR04_TRIG_4_LOW;
}

void HCSR04_4_TimerFunc(uint8_t mode)
{
	if (mode)
	{
		__HAL_TIM_SetCounter(&htim1, 0);
		HAL_TIM_Base_Start(&htim1);
	}
	else
	{
		HAL_TIM_Base_Stop(&htim1);
	}
}

float HCSR04_4_GetDistance_Single(void)
{
	HCSR04StartTrigStart_4();
	while (!HCSR04_ECHO_4)
		;
	HCSR04_4_TimerFunc(4);
	while (HCSR04_ECHO_4)
		;
	HCSR04_4_TimerFunc(0);
	return (__HAL_TIM_GetCounter(&htim1)) / 58.0;
}

float HCSR04_4_GetDistance_Repeatedly(uint8_t cnt)
{
	float sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += HCSR04_4_GetDistance_Single();
	}
	return sum / cnt;
}
