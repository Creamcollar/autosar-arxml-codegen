#ifndef ADC_CFG_H
#define ADC_CFG_H

/**
 * Developer Aruvi B & Auroshaa A from CreamCollar
 * @file Adc_Cfg.h
 * @brief ADC Configuration Header File
 * @details Generated ADC Configuration Header from ARXML
 * 
 * Generated from ARXML: adc_config.arxml
 * Generated on: 2026-05-23 15:42:44
 */

#include "Std_Types.h"

/*==================================================================================================
*                              MODULE IDENTIFICATION
==================================================================================================*/
#define ADC_CFG_VENDOR_ID                    (1810U)
#define ADC_CFG_MODULE_ID                    (123U)
#define ADC_CFG_INSTANCE_ID                  (0U)

/*==================================================================================================
*                              VERSION INFORMATION
==================================================================================================*/
#define ADC_CFG_SW_MAJOR_VERSION             (1U)
#define ADC_CFG_SW_MINOR_VERSION             (0U)
#define ADC_CFG_SW_PATCH_VERSION             (0U)

/*==================================================================================================
*                              ADC GENERAL CONFIGURATION
==================================================================================================*/
#define ADC_DEINIT_API                       STD_OFF
#define ADC_DEV_ERROR_DETECT                 STD_OFF
#define ADC_ENABLE_LIMIT_CHECK               STD_OFF
#define ADC_ENABLE_QUEUING                   STD_OFF
#define ADC_ENABLE_START_STOP_GROUP_API      STD_OFF
#define ADC_GRP_NOTIF_CAPABILITY             STD_OFF
#define ADC_HW_TRIGGER_API                   STD_OFF
#define ADC_LOW_POWER_STATES_SUPPORT         STD_OFF
#define ADC_POWER_STATE_ASYNCH_TRANSITION_MODE STD_OFF
#define ADC_READ_GROUP_API                   STD_OFF
#define ADC_VERSION_INFO_API                 STD_OFF

/*==================================================================================================
*                              ADC PRIORITY AND ALIGNMENT CONFIGURATION
==================================================================================================*/
#define ADC_PRIORITY_IMPLEMENTATION          ADC_PRIORITY_NONE
#define ADC_RESULT_ALIGNMENT                 ADC_ALIGN_RIGHT

/*==================================================================================================
*                              ADC HARDWARE CONFIGURATION
==================================================================================================*/
#define ADC_HW_UNIT                          (0U)

/*==================================================================================================
*                              CONFIGURATION COUNTS
==================================================================================================*/
#define ADC_CHANNEL_COUNT                    (1U)
#define ADC_GROUP_COUNT                      (1U)
#define ADC_HW_UNIT_COUNT                    (1U)

/*==================================================================================================
*                              ADC CHANNEL SYMBOLIC NAMES
==================================================================================================*/
#define ADC_CHANNEL_0                            (0U)

/*==================================================================================================
*                              ADC CHANNEL CONFIGURATION DETAILS
==================================================================================================*/
#define ADC_CHANNEL_0_CONV_TIME        (0U)
#define ADC_CHANNEL_0_HIGH_LIMIT       (4095U)
#define ADC_CHANNEL_0_LIMIT_CHECK      STD_OFF
#define ADC_CHANNEL_0_LOW_LIMIT        (0U)
#define ADC_CHANNEL_0_RANGE_SELECT     ADC_RANGE_ALWAYS
#define ADC_CHANNEL_0_REF_VOLT_HIGH    STD_OFF
#define ADC_CHANNEL_0_REF_VOLT_LOW     STD_OFF
#define ADC_CHANNEL_0_RESOLUTION       (10U)
#define ADC_CHANNEL_0_SAMP_TIME        (0U)

/*==================================================================================================
*                              ADC GROUP SYMBOLIC NAMES
==================================================================================================*/
#define ADC_GROUP_0                              (0U)

/*==================================================================================================
*                              ADC GROUP CONFIGURATION DETAILS
==================================================================================================*/
#define ADC_GROUP_0_ACCESS_MODE          ADC_ACCESS_MODE_SINGLE
#define ADC_GROUP_0_CONVERSION_MODE      ADC_CONV_MODE_ONESHOT
#define ADC_GROUP_0_PRIORITY             (0U)
#define ADC_GROUP_0_REPLACEMENT          ADC_GROUP_REPL_ABORT_RESTART
#define ADC_GROUP_0_TRIGGER_SRC          ADC_TRIGG_SRC_SW
#define ADC_GROUP_0_NUM_SAMPLES          (1U)
#define ADC_GROUP_0_HW_TRIGGER_SIGNAL    ADC_HW_TRIG_BOTH_EDGES
#define ADC_GROUP_0_HW_TRIGGER_TIMER     (0U)
#define ADC_GROUP_0_NOTIFICATION         STD_OFF
#define ADC_GROUP_0_STREAM_BUFFER_MODE   ADC_STREAM_BUFFER_CIRCULAR

/*==================================================================================================
*                              ADC PUBLISHED INFORMATION
==================================================================================================*/
#define ADC_ADCCHANNELVALUESIGNED               STD_OFF
#define ADC_ADCGROUPFIRSTCHANNELFIXED           STD_OFF
#define ADC_ADCMAXCHANNELRESOLUTION             (0U)

/*==================================================================================================
*                              ADC HARDWARE UNIT CONFIGURATION
==================================================================================================*/
#define ADC_HW_UNIT_0_ID                   (0U)
#define ADC_HW_UNIT_0_CLOCK_SOURCE         STD_OFF
#define ADC_HW_UNIT_0_PRESCALE             (0U)

/*==================================================================================================
*                              DET ERROR CODES
==================================================================================================*/
#define ADC_E_UNINIT                         (0x0AU)
#define ADC_E_BUSY                           (0x0BU)
#define ADC_E_IDLE                           (0x0CU)
#define ADC_E_ALREADY_INITIALIZED            (0x0DU)
#define ADC_E_PARAM_CONFIG                   (0x0EU)
#define ADC_E_PARAM_POINTER                  (0x14U)
#define ADC_E_PARAM_GROUP                    (0x15U)
#define ADC_E_WRONG_CONV_MODE                (0x16U)
#define ADC_E_WRONG_TRIGG_SRC                (0x17U)
#define ADC_E_NOTIF_CAPABILITY               (0x18U)
#define ADC_E_BUFFER_UNINIT                  (0x19U)

/*==================================================================================================
*                              SERVICE IDS
==================================================================================================*/
#define ADC_INIT_SID                         (0x00U)
#define ADC_DEINIT_SID                       (0x01U)
#define ADC_START_GROUP_CONVERSION_SID       (0x02U)
#define ADC_STOP_GROUP_CONVERSION_SID        (0x03U)
#define ADC_READ_GROUP_SID                   (0x04U)
#define ADC_ENABLE_HARDWARE_TRIGGER_SID      (0x05U)
#define ADC_DISABLE_HARDWARE_TRIGGER_SID     (0x06U)
#define ADC_ENABLE_GROUP_NOTIFICATION_SID    (0x07U)
#define ADC_DISABLE_GROUP_NOTIFICATION_SID   (0x08U)
#define ADC_GET_GROUP_STATUS_SID             (0x09U)
#define ADC_GET_VERSION_INFO_SID             (0x0AU)
#define ADC_GET_STREAM_LAST_POINTER_SID      (0x0BU)
#define ADC_SETUP_RESULT_BUFFER_SID          (0x0CU)

/*==================================================================================================
*                              TYPE DEFINITIONS
==================================================================================================*/
typedef uint16_t Adc_ChannelType;
typedef uint16_t Adc_GroupType;
typedef uint16_t Adc_ValueGroupType;

typedef enum {{
    ADC_IDLE = 0U,
    ADC_BUSY,
    ADC_COMPLETED,
    ADC_STREAM_COMPLETED
}} Adc_StatusType;

typedef enum {{
    ADC_TRIGG_SRC_SW = 0U,
    ADC_TRIGG_SRC_HW
}} Adc_TriggerSourceType;

typedef enum {{
    ADC_ACCESS_MODE_SINGLE = 0U,
    ADC_ACCESS_MODE_STREAMING
}} Adc_GroupAccessModeType;

typedef enum {{
    ADC_CONV_MODE_ONESHOT = 0U,
    ADC_CONV_MODE_CONTINUOUS
}} Adc_GroupConvModeType;

typedef struct {{
    /* Channel configuration structure */
    Adc_ChannelType channelId;
    uint16_t resolution;
    uint16_t conversionTime;
    uint16_t samplingTime;
    uint16_t highLimit;
    uint16_t lowLimit;
    boolean limitCheckEnabled;
}} Adc_ChannelConfigType;

typedef struct {{
    /* Group configuration structure */
    Adc_GroupType groupId;
    Adc_GroupAccessModeType accessMode;
    Adc_GroupConvModeType conversionMode;
    uint8_t priority;
    Adc_TriggerSourceType triggerSource;
    uint16_t numSamples;
}} Adc_GroupConfigType;

typedef struct {{
    const Adc_ChannelConfigType* channelConfigs;
    const Adc_GroupConfigType* groupConfigs;
    uint16_t numChannels;
    uint16_t numGroups;
}} Adc_ConfigType;

/*==================================================================================================
*                              FUNCTION DECLARATIONS
==================================================================================================*/
extern const Adc_ConfigType Adc_Config;

#endif /* ADC_CFG_H */

