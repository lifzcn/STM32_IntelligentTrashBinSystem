/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "hcsr04.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t x = 0;
	uint8_t y = 0;
	double distanceValue_1 = 0;
	uint8_t distanceValue_1_Integer = 0;
	uint8_t distanceValue_1_Decimal = 0;
	double distanceValue_2 = 0;
	uint8_t distanceValue_2_Integer = 0;
	uint8_t distanceValue_2_Decimal = 0;
	double distanceValue_3 = 0;
	uint8_t distanceValue_3_Integer = 0;
	uint8_t distanceValue_3_Decimal = 0;
	double distanceValue_4 = 0;
	uint8_t distanceValue_4_Integer = 0;
	uint8_t distanceValue_4_Decimal = 0;
	uint8_t rxBuffer[1] = {'0'};
	uint8_t distanceLimitValue = 4;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	OLED_Init();
	OLED_Clear();
	OLED_ShowChinese(x + 16 * 0, y + 2 * 0, 0);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 0, 1);
	OLED_ShowChinese(x + 16 * 2, y + 2 * 0, 2);
	OLED_ShowChar(x + 16 * 3 + 8 * 0, y + 2 * 0, '1', 16);
	OLED_ShowChar(x + 16 * 3 + 8 * 1, y + 2 * 0, ':', 16);
	OLED_ShowChinese(x + 16 * 0, y + 2 * 1, 0);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 1, 1);
	OLED_ShowChinese(x + 16 * 2, y + 2 * 1, 2);
	OLED_ShowChar(x + 16 * 3 + 8 * 0, y + 2 * 1, '2', 16);
	OLED_ShowChar(x + 16 * 3 + 8 * 1, y + 2 * 1, ':', 16);
	OLED_ShowChinese(x + 16 * 0, y + 2 * 2, 0);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 2, 1);
	OLED_ShowChinese(x + 16 * 2, y + 2 * 2, 2);
	OLED_ShowChar(x + 16 * 3 + 8 * 0, y + 2 * 2, '3', 16);
	OLED_ShowChar(x + 16 * 3 + 8 * 1, y + 2 * 2, ':', 16);
	OLED_ShowChinese(x + 16 * 0, y + 2 * 3, 0);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 3, 1);
	OLED_ShowChinese(x + 16 * 2, y + 2 * 3, 2);
	OLED_ShowChar(x + 16 * 3 + 8 * 0, y + 2 * 3, '4', 16);
	OLED_ShowChar(x + 16 * 3 + 8 * 1, y + 2 * 3, ':', 16);
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 500);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 500);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 500);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_UART_Receive_DMA(&huart1, rxBuffer, 1);
		
		distanceValue_1 = HCSR04_1_GetDistance_Repeatedly(5);
		distanceValue_1_Integer = (int)distanceValue_1;
		distanceValue_1_Decimal = 10 * (distanceValue_1 - distanceValue_1_Integer);
		
		OLED_ShowNum(x + 16 * 3 + 8 * 2, y + 2 * 0, distanceValue_1_Integer, 2, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 4, y + 2 * 0, '.', 16);
		OLED_ShowNum(x + 16 * 3 + 8 * 5, y + 2 * 0, distanceValue_1_Decimal, 1, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 6, y + 2 * 0, 'c', 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 7, y + 2 * 0, 'm', 16);
		
		distanceValue_2 = HCSR04_2_GetDistance_Repeatedly(5);
		distanceValue_2_Integer = (int)distanceValue_2;
		distanceValue_2_Decimal = 10 * (distanceValue_2 - distanceValue_2_Integer);
		
		OLED_ShowNum(x + 16 * 3 + 8 * 2, y + 2 * 1, distanceValue_2_Integer, 2, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 4, y + 2 * 1, '.', 16);
		OLED_ShowNum(x + 16 * 3 + 8 * 5, y + 2 * 1, distanceValue_2_Decimal, 1, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 6, y + 2 * 1, 'c', 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 7, y + 2 * 1, 'm', 16);
		
		distanceValue_3 = HCSR04_3_GetDistance_Repeatedly(5);
		distanceValue_3_Integer = (int)distanceValue_3;
		distanceValue_3_Decimal = 10 * (distanceValue_3 - distanceValue_3_Integer);
		
		OLED_ShowNum(x + 16 * 3 + 8 * 2, y + 2 * 2, distanceValue_3_Integer, 2, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 4, y + 2 * 2, '.', 16);
		OLED_ShowNum(x + 16 * 3 + 8 * 5, y + 2 * 2, distanceValue_3_Decimal, 1, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 6, y + 2 * 2, 'c', 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 7, y + 2 * 2, 'm', 16);
		
		distanceValue_4 = HCSR04_4_GetDistance_Repeatedly(5);
		distanceValue_4_Integer = (int)distanceValue_4;
		distanceValue_4_Decimal = 10 * (distanceValue_4 - distanceValue_4_Integer);
		
		OLED_ShowNum(x + 16 * 3 + 8 * 2, y + 2 * 3, distanceValue_4_Integer, 2, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 4, y + 2 * 3, '.', 16);
		OLED_ShowNum(x + 16 * 3 + 8 * 5, y + 2 * 3, distanceValue_4_Decimal, 1, 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 6, y + 2 * 3, 'c', 16);
		OLED_ShowChar(x + 16 * 3 + 8 * 7, y + 2 * 3, 'm', 16);
		
		switch(rxBuffer[0])
		{
			case '1':
				printf("可回收垃圾\n");
			break;
			case '2':
				printf("可回收垃圾\n");
			break;
			case '3':
				printf("厨余垃圾\n");
			break;
			case '4':
				printf("厨余垃圾\n");
			break;
			case '5':
				printf("有害垃圾\n");
			break;
			case '6':
				printf("有害垃圾\n");
			break;
			case '7':
				printf("其他垃圾\n");
			break;
			case '8':
				printf("其他垃圾\n");
			break;
			default:
				;
			break;
		}
		
		if (distanceValue_1 > distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, (int)2000 * 100 / 180);
		}
		else if (distanceValue_1 < distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 500);
			HAL_GPIO_WritePin(SYN6288_IO_GPIO_Port, SYN6288_IO_Pin, GPIO_PIN_SET);
		}
		
		if (distanceValue_2 > distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, (int)2000 * 100 / 180);
		}
		else if (distanceValue_2 < distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 500);
			HAL_GPIO_WritePin(SYN6288_IO_GPIO_Port, SYN6288_IO_Pin, GPIO_PIN_SET);
		}
		
		if (distanceValue_3 > distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, (int)2000 * 100 / 180);
		}
		else if (distanceValue_3 < distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 500);
			HAL_GPIO_WritePin(SYN6288_IO_GPIO_Port, SYN6288_IO_Pin, GPIO_PIN_SET);
		}
		
		if (distanceValue_4 > distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, (int)2000 * 100 / 180);
		}
		else if (distanceValue_4 < distanceLimitValue)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 500);
			HAL_GPIO_WritePin(SYN6288_IO_GPIO_Port, SYN6288_IO_Pin, GPIO_PIN_SET);
		}
		
    HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
