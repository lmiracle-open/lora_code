/********************************* Copyright(c) ********************************
*
*                          LANMENG Scientific Creation
*                          https: //www.lmiracle.com
*
* File Name     : lm_clock.c
* Change Logs   :
* Date         Author      Notes
* 2019-06-07   terryall    V1.0    first version
*******************************************************************************/

/*******************************************************************************
* Description   : 文件包含区
*******************************************************************************/
#include "lm_clock.h"
#include "lm_error.h"

#include "lm_driver.h"

#include "stm32l0xx_hal.h"

/*******************************************************************************
* Description   : 模块内部函数定义区
*******************************************************************************/

/*******************************************************************************
* FunName       : lm_system_clock_Config()
* Description   : 系统时钟配置
* EntryParam    : None
* ReturnValue   : None
*******************************************************************************/
static int8_t lm_system_clock_Config(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Enable Power Control clock */
    __HAL_RCC_PWR_CLK_ENABLE();       //

    /* The voltage scaling allows optimizing the power consumption when the
     * device is clocked below the maximum system frequency, to update the
     * voltage scaling value regarding system frequency refer to product
     * datasheet.
     */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /* Enable HSI Oscillator and activate PLL with HSI as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
    RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
    RCC_OscInitStruct.HSICalibrationValue = 0x10;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
    clocks dividers */
    RCC_ClkInitStruct.ClockType = ( RCC_CLOCKTYPE_SYSCLK    | \
                                    RCC_CLOCKTYPE_HCLK      | \
                                    RCC_CLOCKTYPE_PCLK1     | \
                                    RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);

    return LM_ERR_SUCCESS;
}

/*******************************************************************************
* Description   : 注册系统时钟初始化模块
*******************************************************************************/
LM_DRIVER_INIT(lm_system_clock_Config);

/* end of file */
