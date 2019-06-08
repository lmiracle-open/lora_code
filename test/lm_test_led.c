/********************************* Copyright(c) ********************************
*
*                          LANMENG Scientific Creation
*                          https: //www.lmiracle.com
*
* File Name     : lm_test_led.c
* Change Logs   :
* Date         Author      Notes
* 2019-06-07   terryall    V1.0    first version
*******************************************************************************/

/*******************************************************************************
* Description   : 文件包含区
*******************************************************************************/
#include "lm_driver_led.h"
#include "lm_error.h"
#include "lm_app_config.h"

#include "lm_app.h"

/*******************************************************************************
* Description   : 模块内部函数定义区
*******************************************************************************/

/*******************************************************************************
* FunName       : lm_test_led1_flicker()
* Description   : LED闪烁
* EntryParam    : None
* ReturnValue   : 错误码
*******************************************************************************/
static int8_t lm_test_led1_flicker(void)
{
    LED1_ON;
    lm_delay_ms(200);
    LED1_OFF;

    return LM_ERR_SUCCESS;
}

/*******************************************************************************
* Description   : 注册1s应用程序任务
*******************************************************************************/
LM_APP_TASK_1S(lm_test_led1_flicker);

/* end of file */
