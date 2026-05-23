#ifndef DIO_CFG_H
#define DIO_CFG_H

/**
 * Developer Aruvi B & Auroshaa A from CreamCollar
 * @file Dio_Cfg.h
 * @brief DIO Configuration Header File
 * @details Generated DIO Configuration Header from ARXML
 * 
 * Generated from ARXML: dio_config.arxml
 * Generated on: 2026-05-23 15:19:48
 */

#include "Std_Types.h"

/*==================================================================================================
*                              MODULE IDENTIFICATION
==================================================================================================*/
#define DIO_CFG_VENDOR_ID                    (1810U)
#define DIO_CFG_MODULE_ID                    (202U)
#define DIO_CFG_INSTANCE_ID                  (0U)

/*==================================================================================================
*                              VERSION INFORMATION
==================================================================================================*/
#define DIO_CFG_SW_MAJOR_VERSION             (1U)
#define DIO_CFG_SW_MINOR_VERSION             (0U)
#define DIO_CFG_SW_PATCH_VERSION             (0U)

/*==================================================================================================
*                              CONFIGURATION SET
==================================================================================================*/
#define DIO_INCLUDE_CONFIG_SET               STD_ON
#define DIO_CONFIG                           STD_ON

/*==================================================================================================
*                              API CONFIGURATION
==================================================================================================*/
#define DIO_DEV_ERROR_DETECT                 STD_ON
#define DIO_VERSION_INFO_API                 STD_ON
#define DIO_FLIP_CHANNEL_API                 STD_ON
#define DIO_MASKED_WRITE_PORT_API            STD_ON

/*==================================================================================================
*                              CONFIGURATION COUNTS
==================================================================================================*/
#define DIO_PORT_COUNT                       (1U)
#define DIO_CHANNEL_COUNT                    (1U)
#define DIO_CHANNEL_GROUP_COUNT              (1U)

/*==================================================================================================
*                              DIO PORT SYMBOLIC NAMES
==================================================================================================*/
#define DioPort                                  (0U)

/*==================================================================================================
*                              DIO CHANNEL SYMBOLIC NAMES
==================================================================================================*/
#define DioChannel                               (0U)

/*==================================================================================================
*                              DIO CHANNEL GROUP SYMBOLIC NAMES
==================================================================================================*/
#define DIO_GROUP_0                              (0U)
#define DIO_GROUP_0_MASK                                (0x00FFU)
#define DIO_GROUP_0_OFFSET                             (0U)
#define DIO_GROUP_0_IDENTIFICATION                     "DIO_GROUP_0"

/*==================================================================================================
*                              FUNCTION DECLARATIONS
==================================================================================================*/
extern const Dio_ConfigType Dio_Config;

#endif /* DIO_CFG_H */

