/********************************* Copyright(c) ********************************
*
*                          LANMENG Scientific Creation
*                          https: //www.lmiracle.com
*
* File Name     : lm_app_config.h
* Change Logs   :
* Date         Author      Notes
* 2019-06-07   terryall    V1.0    first version
*******************************************************************************/

/*******************************************************************************
* Description   : 文件包含区
*******************************************************************************/
#ifndef __LM_APP_CONFIG_H__
#define __LM_APP_CONFIG_H__

#include "lm_types.h"
#include "lm_delay.h"

/*******************************************************************************
* Description   : 宏定义区
*******************************************************************************/

#define lm_delay_ms(cnt)            delay_ms(cnt)       /* ms延时 */

#define lm_kprintf(format,...)  \
        printf(format"",##__VA_ARGS__)                  /* 格式化输出 */

#endif

/* end of file */
