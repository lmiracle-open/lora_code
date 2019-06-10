/********************************* Copyright(c) ********************************
*
*                          LANMENG Scientific Creation
*                          https: //www.lmiracle.com
*
* File Name     : lm_delay.c
* Change Logs   :
* Date         Author      Notes
* 2019-06-07   terryall    V1.0    first version
*******************************************************************************/

/*******************************************************************************
* Description   : 文件包含区
*******************************************************************************/
#include "lm_delay.h"
#include "lm_error.h"

#include "lm_app.h"

/*******************************************************************************
* Description   : 模块内部变量定义区
*******************************************************************************/
static unsigned char  fac_us = 0;
static unsigned short fac_ms = 0;

/*******************************************************************************
* Description   : 模块内部函数定义区
*******************************************************************************/

/*******************************************************************************
* FunName       : lm_delay_init()
* Description   : 延时初始化
* EntryParam    : None
* ReturnValue   : None
*******************************************************************************/
static int8_t lm_delay_init(void)
{
    SysTick->CTRL &= ~(1<<2);
    fac_us = 32/8;
    fac_ms=(unsigned short)fac_us*1000;

    return LM_ERR_SUCCESS;
}

/*******************************************************************************
* Description   : 外部函数定义区
*******************************************************************************/

/*******************************************************************************
* FunName       : delay_us()
* Description   : us延时
* EntryParam    : nus,us数
* ReturnValue   : None
*******************************************************************************/
void delay_us(unsigned int nus)
{
    unsigned int temp;
    SysTick->LOAD=nus*fac_us;
    SysTick->VAL=0x00;
    SysTick->CTRL=0x01 ;

    do {
        temp=SysTick->CTRL;
    } while((temp&0x01)&&!(temp&(1<<16)));
    SysTick->CTRL=0x00;
    SysTick->VAL =0X00;
}

/*******************************************************************************
* FunName       : delay_ms()
* Description   : ms延时
* EntryParam    : nms,ms数
* ReturnValue   : None
*******************************************************************************/
void delay_ms(unsigned short nms)
{
    unsigned int temp;
    SysTick->LOAD=(unsigned int)nms*fac_ms;
    SysTick->VAL =0x00;
    SysTick->CTRL=0x01 ;
    do {
        temp=SysTick->CTRL;
    } while((temp&0x01)&&!(temp&(1<<16)));
    SysTick->CTRL=0x00;
    SysTick->VAL =0X00;
}

/*******************************************************************************
* FunName       : SYSTICK_IRQ_HANDLER()
* Description   : systick中断函数
* EntryParam    : None
* ReturnValue   : None
*******************************************************************************/
void SYSTICK_IRQ_HANDLER(void)
{
    HAL_IncTick();
}

/*******************************************************************************
* Description   : 注册延时初始化模块
*******************************************************************************/
LM_APP_INIT(lm_delay_init);

/* end of file */
