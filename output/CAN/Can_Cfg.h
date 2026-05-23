#ifndef CAN_CFG_H
#define CAN_CFG_H

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Can_Cfg.h
 * @brief CAN Configuration Header File
 * @details Generated CAN Configuration Header from ARXML
 * 
 * Generated from ARXML: can_config.arxml
 * Generated on: 2026-05-23 15:44:22
 */

#include "Std_Types.h"

/*==================================================================================================
*                              MODULE IDENTIFICATION
==================================================================================================*/
#define CAN_CFG_VENDOR_ID                    (1810U)
#define CAN_CFG_MODULE_ID                    (80U)
#define CAN_CFG_INSTANCE_ID                  (0U)

/*==================================================================================================
*                              VERSION INFORMATION
==================================================================================================*/
#define CAN_CFG_SW_MAJOR_VERSION             (1U)
#define CAN_CFG_SW_MINOR_VERSION             (0U)
#define CAN_CFG_SW_PATCH_VERSION             (0U)

/*==================================================================================================
*                              CONFIGURATION SET
==================================================================================================*/
#define CAN_CONFIG_SET                       STD_ON

/*==================================================================================================
*                              CAN GENERAL CONFIGURATION
==================================================================================================*/
#define CAN_DEV_ERROR_DETECT                 STD_ON
#define CAN_ENABLE_SECURITY_EVENT_REPORTING  STD_OFF
#define CAN_GLOBAL_TIME_SUPPORT              STD_OFF
#define CAN_INDEX                            (0U)
#define CAN_LPDU_RECEIVE_CALLOUT_FUNCTION    "None"
#define CAN_MAIN_FUNCTION_BUSOFF_PERIOD      (100U)
#define CAN_MAIN_FUNCTION_MODE_PERIOD        (100U)
#define CAN_MAIN_FUNCTION_WAKEUP_PERIOD      (100U)
#define CAN_MULTIPLEXED_TRANSMISSION         (0U)
#define CAN_SET_BAUDRATE_API                 STD_OFF
#define CAN_TIMEOUT_DURATION                 (100U)
#define CAN_VERSION_INFO_API                 STD_ON

/*==================================================================================================
*                              CAN CONTROLLER CONFIGURATION
==================================================================================================*/
#define CAN_CONTROLLER_COUNT                 (1U)
#define CAN_HW_OBJECT_COUNT                  (1U)

/* Controller 0 Configuration */
#define CAN_CONTROLLER_0_CANCONTROLLERACTIVATION    STD_ON
#define CAN_CONTROLLER_0_CANHWPNSUPPORT    STD_OFF
#define CAN_CONTROLLER_0_CANWAKEUPSUPPORT    STD_OFF
#define CAN_CONTROLLER_0_CANCONTROLLERBASEADDRESS    (0U)
#define CAN_CONTROLLER_0_CANCONTROLLERID    (0U)
#define CAN_CONTROLLER_0_CANBUSOFFPROCESSING    INTERRUPT
#define CAN_CONTROLLER_0_CANRXPROCESSING    INTERRUPT
#define CAN_CONTROLLER_0_CANTXPROCESSING    INTERRUPT
#define CAN_CONTROLLER_0_CANWAKEUPPROCESSING    INTERRUPT

/* Controller 0 Baudrate Configurations */
#define CAN_CTRL_0_BR_0_CANCONTROLLERBAUDRATE    (500000U)
#define CAN_CTRL_0_BR_0_CANCONTROLLERBAUDRATECONFIGID    (0U)
#define CAN_CTRL_0_BR_0_CANCONTROLLERPROPSEG    (1U)
#define CAN_CTRL_0_BR_0_CANCONTROLLERSEG1    (1U)
#define CAN_CTRL_0_BR_0_CANCONTROLLERSEG2    (1U)
#define CAN_CTRL_0_BR_0_CANCONTROLLERSYNCJUMPWIDTH    (1U)

/* Controller 0 FD Baudrate Configurations */
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERSSPOFFSET    STD_OFF
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERTXBITRATESWITCH    STD_OFF
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERFDBAUDRATE    (2000000U)
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERPROPSEG    (1U)
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERSEG1    (1U)
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERSEG2    (1U)
#define CAN_CTRL_0_FD_BR_0_CANCONTROLLERSYNCJUMPWIDTH    (1U)

/*==================================================================================================
*                              CAN HARDWARE OBJECT CONFIGURATION
==================================================================================================*/
/* Hardware Object 0 Configuration */
#define CAN_HW_OBJ_0_CANHARDWAREOBJECTUSESPOLLING    STD_OFF
#define CAN_HW_OBJ_0_CANTRIGGERTRANSMITENABLE    STD_OFF
#define CAN_HW_OBJ_0_CANFDPADDINGVALUE    (0U)
#define CAN_HW_OBJ_0_CANHWOBJECTCOUNT    (1U)
#define CAN_HW_OBJ_0_CANOBJECTID    (0U)
#define CAN_HW_OBJ_0_CANHANDLETYPE    BASIC
#define CAN_HW_OBJ_0_CANIDTYPE    STANDARD
#define CAN_HW_OBJ_0_CANOBJECTPAYLOADLENGTH    CAN_OBJECT_PL_8
#define CAN_HW_OBJ_0_CANOBJECTTYPE    RECEIVE

/*==================================================================================================
*                              CAN HARDWARE FILTER CONFIGURATION
==================================================================================================*/
/* Hardware Filter 0 Configuration */
#define CAN_HW_FILTER_0_CANHWFILTERCODE    (0U)
#define CAN_HW_FILTER_0_CANHWFILTERMASK    (0U)

/*==================================================================================================
*                              CAN PARTIAL NETWORK CONFIGURATION
==================================================================================================*/
#define CAN_PN_CANPNENABLED    STD_OFF
#define CAN_PN_CANPNFRAMECANID    (0U)
#define CAN_PN_CANPNFRAMECANIDMASK    (0U)
#define CAN_PN_CANPNFRAMEDLC    (8U)

/*==================================================================================================
*                              CAN TIME TRIGGERED CONFIGURATION
==================================================================================================*/
#define CAN_TT_CANTTCONTROLLEREXTERNALCLOCKSYNCHRONISATION    STD_OFF
#define CAN_TT_CANTTCONTROLLERGLOBALTIMEFILTERING    STD_OFF
#define CAN_TT_CANTTCONTROLLERLEVEL2    STD_OFF
#define CAN_TT_CANTTCONTROLLERTIMEMASTER    STD_OFF
#define CAN_TT_CANTTCONTROLLERTURRESTORE    STD_OFF
#define CAN_TT_CANTTCONTROLLERAPPLWATCHDOGLIMIT    (0U)
#define CAN_TT_CANTTCONTROLLERCYCLECOUNTMAX    (0U)
#define CAN_TT_CANTTCONTROLLEREXPECTEDTXTRIGGER    (0U)
#define CAN_TT_CANTTCONTROLLERINITIALREFOFFSET    (0U)
#define CAN_TT_CANTTCONTROLLERINTERRUPTENABLE    (0U)
#define CAN_TT_CANTTCONTROLLERNTUCONFIG    (0U)
#define CAN_TT_CANTTCONTROLLERSYNCDEVIATION    (0U)
#define CAN_TT_CANTTCONTROLLERTIMEMASTERPRIORITY    (0U)
#define CAN_TT_CANTTCONTROLLERTXENABLEWINDOWLENGTH    (0U)
#define CAN_TT_CANTTCONTROLLERWATCHTRIGGERGAPTIMEMARK    (0U)
#define CAN_TT_CANTTCONTROLLERWATCHTRIGGERTIMEMARK    (0U)
#define CAN_TT_CANTTCONTROLLEROPERATIONMODE    CAN_TT_TIME_TRIGGERED
#define CAN_TT_CANTTIRQPROCESSING    INTERRUPT

/*==================================================================================================
*                              CAN XL CONFIGURATION
==================================================================================================*/
#define CAN_XL_CANXLETHGLOBALTIMESUPPORT    STD_OFF

/*==================================================================================================
*                              CAN ICOM CONFIGURATION
==================================================================================================*/
#define CAN_ICOM_SUPPORT                     STD_ON
/* ICOM General Configuration */
#define CAN_ICOM_CANICOMLEVEL    "CAN_ICOM_LEVEL_ONE"
#define CAN_ICOM_CANICOMVARIANT    "CAN_ICOM_VARIANT_HW"

#define CAN_ICOM_RX_MESSAGE_COUNT            (1U)

/* ICOM RX Message 0 Configuration */
#define CAN_ICOM_RX_MSG_0_CANICOMPAYLOADLENGTHERROR    STD_OFF
#define CAN_ICOM_RX_MSG_0_CANICOMCOUNTERVALUE    (0U)
#define CAN_ICOM_RX_MSG_0_CANICOMMESSAGEID    (0U)
#define CAN_ICOM_RX_MSG_0_CANICOMMESSAGEIDMASK    (0U)
#define CAN_ICOM_RX_MSG_0_CANICOMMISSINGMESSAGETIMERVALUE    (0U)
#define CAN_ICOM_RX_MSG_0_SIGNAL_COUNT    (1U)
/* ICOM RX Message 0 Signal 0 Configuration */
#define CAN_ICOM_RX_MSG_0_SIG_0_CANICOMSIGNALREF    STD_OFF
#define CAN_ICOM_RX_MSG_0_SIG_0_CANICOMSIGNALMASK    (0U)
#define CAN_ICOM_RX_MSG_0_SIG_0_CANICOMSIGNALVALUE    (0U)
#define CAN_ICOM_RX_MSG_0_SIG_0_CANICOMSIGNALOPERATION    "AND"


/*==================================================================================================
*                              FUNCTION DECLARATIONS
==================================================================================================*/
extern const Can_ConfigType Can_Config;

#endif /* CAN_CFG_H */

