/********************************* Copyright(c) ********************************
*
*                          LANMENG Scientific Creation
*                          https: //www.lmiracle.com
*
* File Name     : lm_delay.h
* Change Logs   :
* Date         Author      Notes
* 2019-06-07   terryall    V1.0    first version
*******************************************************************************/

/*******************************************************************************
* Description   : 文件包含区
*******************************************************************************/
#ifndef __LM_DELAY_H__
#define __LM_DELAY_H__

#include "lm_types.h"

/*******************************************************************************
* Description   : 外部函数声明区
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* FunName       : delay_us()
* Description   : us延时
* EntryParam    : nus,us数
* ReturnValue   : None
*******************************************************************************/
extern void delay_us(unsigned int nus);

/*******************************************************************************
* FunName       : delay_ms()
* Description   : ms延时
* EntryParam    : nms,ms数
* ReturnValue   : None
*******************************************************************************/
extern void delay_ms(unsigned short nms);

#ifdef __cplusplus
}
#endif

#endif

/* end of file */
