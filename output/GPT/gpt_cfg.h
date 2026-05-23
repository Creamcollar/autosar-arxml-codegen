#ifndef GPT_CFG_H_
#define GPT_CFG_H_

/*
 * Developer Aruvi B and Auroshaa from CreamCollar
 * Generated GPT Configuration Header
 * Generated from ARXML: gpt_config.arxml
 * Generated on: 2026-05-23 15:43:28
 */

/* Module identification */
#define GPT_VENDOR_ID                    (1810U)
#define GPT_MODULE_ID                    (100U)
#define GPT_INSTANCE_ID                  (0U)

/* Module version information */
#define GPT_SW_MAJOR_VERSION             (1U)
#define GPT_SW_MINOR_VERSION             (0U)
#define GPT_SW_PATCH_VERSION             (0U)

/* GPT Driver Configuration */
#define GPT_DEV_ERROR_DETECT             STD_OFF
#define GPT_PREDEF_TIMER_100US_32BIT_ENABLE STD_OFF
#define GPT_PREDEF_TIMER_1US_ENABLING_GRADE (GPT_PREDEF_TIMER_1US_DISABLED)
#define GPT_REPORT_WAKEUP_SOURCE         STD_OFF

/* GPT Optional API Services */
#define GPT_DEINIT_API                   STD_OFF
#define GPT_ENABLE_DISABLE_NOTIFICATION_API STD_OFF
#define GPT_TIME_ELAPSED_API             STD_OFF
#define GPT_TIME_REMAINING_API           STD_OFF
#define GPT_VERSION_INFO_API             STD_OFF
#define GPT_WAKEUP_FUNCTIONALITY_API     STD_OFF

/* GPT Predef Timer 1us Enabling Grade Options */
#define GPT_PREDEF_TIMER_1US_16BIT_ENABLED          (0x01U)
#define GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED       (0x02U)
#define GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED    (0x03U)
#define GPT_PREDEF_TIMER_1US_DISABLED               (0x00U)

/* GPT Error Codes */
#define GPT_E_UNINIT                     (0x0AU)
#define GPT_E_BUSY                       (0x0BU)
#define GPT_E_MODE                       (0x0CU)
#define GPT_E_PARAM_CHANNEL              (0x14U)
#define GPT_E_PARAM_VALUE                (0x15U)
#define GPT_E_PARAM_POINTER              (0x16U)
#define GPT_E_PARAM_PREDEF_TIMER         (0x17U)
#define GPT_E_PARAM_MODE                 (0x1FU)

/* Service IDs */
#define GPT_INIT_SID                     (0x01U)
#define GPT_DEINIT_SID                   (0x02U)
#define GPT_GET_TIME_ELAPSED_SID         (0x03U)
#define GPT_GET_TIME_REMAINING_SID       (0x04U)
#define GPT_START_TIMER_SID              (0x05U)
#define GPT_STOP_TIMER_SID               (0x06U)
#define GPT_ENABLE_NOTIFICATION_SID      (0x07U)
#define GPT_DISABLE_NOTIFICATION_SID     (0x08U)
#define GPT_SET_MODE_SID                 (0x09U)
#define GPT_DISABLE_WAKEUP_SID           (0x0AU)
#define GPT_ENABLE_WAKEUP_SID            (0x0BU)
#define GPT_CHECK_WAKEUP_SID             (0x0CU)
#define GPT_GET_VERSION_INFO_SID         (0x00U)
#define GPT_GET_PREDEF_TIMER_VALUE_SID   (0x0DU)

/* GPT Channel Mode */
#define GPT_CH_MODE_CONTINUOUS           (0x00U)
#define GPT_CH_MODE_ONESHOT              (0x01U)

/* GPT Mode Type */
#define GPT_MODE_NORMAL                  (0x00U)
#define GPT_MODE_SLEEP                   (0x01U)

/* GPT Predef Timer Type */
#define GPT_PREDEF_TIMER_1US_16BIT       (0x00U)
#define GPT_PREDEF_TIMER_1US_24BIT       (0x01U)
#define GPT_PREDEF_TIMER_1US_32BIT       (0x02U)
#define GPT_PREDEF_TIMER_100US_32BIT     (0x03U)
/* GPT Channel Symbolic Names */
#define GptConf_GptChannelConfiguration_Channel_0    (0U)

/* GPT Channel Configuration */
#define GPT_CHANNEL_0_MODE                     (GPT_CH_MODE_ONESHOT)
#define GPT_CHANNEL_0_TICK_FREQUENCY           (0f)
#define GPT_CHANNEL_0_TICK_VALUE_MAX           (0U)
#define GPT_CHANNEL_0_ENABLE_WAKEUP            (STD_OFF)
#define GPT_CHANNEL_0_CLK_SRC_REF              (STD_OFF)
#define GPT_CHANNEL_0_NOTIFICATION_ENABLED     (STD_OFF)

/* Configuration Counts */
#define GPT_CONFIG_CHANNELS_COUNT            (1U)
#define GPT_CONFIG_CLOCK_REFERENCE_POINTS    (1U)
#define GPT_CONFIG_WAKEUP_SOURCES_COUNT      (1U)
#define GPT_CONFIG_CHANNEL_CONFIG_SETS       (0U)
#define GPT_MAX_CHANNEL_ID                   (0U)

/* GPT Predef Timer Configuration */
#define GPT_PREDEF_TIMER_1US_ENABLED         (STD_OFF)
#define GPT_PREDEF_TIMER_100US_32BIT_ENABLED (STD_OFF)

/* GPT Channel Array Sizes */
#define GPT_CONTINUOUS_CHANNELS_COUNT        (0U)
#define GPT_ONESHOT_CHANNELS_COUNT           (1U)
#define GPT_WAKEUP_CHANNELS_COUNT            (0U)

/* GPT One-Shot Mode Channels */
#define GPT_ONESHOT_CHANNEL_0              (0U)

/* GPT Clock Reference Points Configuration */
#define GPT_CLOCK_REFERENCE_0_ENABLED      (STD_OFF)

/* GPT Timer Value Type Definitions */
typedef uint16 Gpt_ValueType;
typedef uint32 Gpt_ChannelType;

/* GPT Channel Mode Type */
typedef uint8 Gpt_ModeType;
typedef uint8 Gpt_ChannelModeType;

/* GPT Notification Function Type */
typedef void (*Gpt_NotificationCallbackType)(void);

/* GPT Hardware Specific Definitions */
#define GPT_HW_CHANNEL_OFFSET                (0x00U)
#define GPT_PRESCALER_MIN                    (1U)
#define GPT_PRESCALER_MAX                    (65535U)

/* GPT Channel Frequency Calculations */

/* GPT Configuration Structure Forward Declarations */
typedef struct Gpt_ConfigType Gpt_ConfigType;
typedef struct Gpt_ChannelConfigType Gpt_ChannelConfigType;

/* GPT Configuration Variable Declaration */
extern const Gpt_ConfigType GptConfigSet;

/* GPT Conditional Compilation Guards */
#define Gpt_DeInit()    /* Not configured */
#define Gpt_EnableNotification(Channel)     /* Not configured */
#define Gpt_DisableNotification(Channel)    /* Not configured */
#define Gpt_GetTimeElapsed(Channel)         /* Not configured */
#define Gpt_GetTimeRemaining(Channel)       /* Not configured */
#define Gpt_GetVersionInfo(VersionInfo)     /* Not configured */
#define Gpt_SetWakeup(Channel)              /* Not configured */
#define Gpt_CheckWakeup(WakeupSource)       /* Not configured */

#endif /* GPT_CFG_H_ */

