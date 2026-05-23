#ifndef ADC_H_
#define ADC_H_

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Adc.h
 * @brief ADC Configuration Header File
 * @details Generated ADC Configuration Header from ARXML
 * Generated from ARXML: adc_config.arxml
 */

#include "Std_Types.h"

/* ============================ */
/*      AUTOSAR Version Info    */
/* ============================ */
#define ADC_AR_RELEASE_MAJOR_VERSION   (4U)
#define ADC_AR_RELEASE_MINOR_VERSION   (4U)
#define ADC_AR_RELEASE_REVISION_VERSION (0U)

#define ADC_SW_MAJOR_VERSION           (1U)
#define ADC_SW_MINOR_VERSION           (0U)
#define ADC_SW_PATCH_VERSION           (0U)



/* ============================ */
/*          DEFINES             */
/* ============================ */
#define ADC_VENDOR_ID                  (1234U)
#define ADC_MODULE_ID                  (123U)
#define ADC_INSTANCE_ID                (0U)

/* Development error codes */
#define ADC_E_UNINIT                   (0x01U)
#define ADC_E_PARAM_GROUP              (0x02U)
#define ADC_E_ALREADY_INITIALIZED      (0x03U)
#define ADC_E_PARAM_CONFIG             (0x04U)

/* API Service IDs */
#define ADC_INIT_ID                    (0x00U)
#define ADC_DEINIT_ID                  (0x01U)
#define ADC_START_GROUP_CONVERSION_ID  (0x02U)
#define ADC_STOP_GROUP_CONVERSION_ID   (0x03U)
#define ADC_READ_GROUP_ID              (0x04U)
#define ADC_ENABLE_HARDWARE_TRIGGER_ID (0x05U)
#define ADC_DISABLE_HARDWARE_TRIGGER_ID (0x06U)
#define ADC_ENABLE_NOTIFICATION_ID     (0x07U)
#define ADC_DISABLE_NOTIFICATION_ID    (0x08U)
#define ADC_GET_GROUP_STATUS_ID        (0x09U)
#define ADC_GET_VERSION_INFO_ID        (0x0AU)
#define ADC_SETUP_RESULT_BUFFER_ID     (0x0BU)
#define ADC_GET_STREAM_LAST_POINTER_ID (0x0CU)

/* ============================ */
/*          TYPES               */
/* ============================ */

/* AUTOSAR-defined types */
typedef uint8 Adc_GroupType;
typedef uint16 Adc_ValueGroupType;
typedef uint8 Adc_PrescaleType;
typedef uint16 Adc_ConversionTimeType;
typedef uint16 Adc_SamplingTimeType;
typedef uint8 Adc_ResolutionType;
typedef uint8 Adc_StatusType;
typedef uint8 Adc_GroupPriorityType;
typedef uint16* Adc_GroupDefType;
typedef uint16 Adc_StreamNumSampleType;
typedef uint8 Adc_HwTriggerSignalType;
typedef uint32 Adc_HwTriggerTimerType;
typedef uint8 Adc_PowerStateRequestResultType;


/* Priority Implementation */
typedef enum {
    ADC_PRIORITY_HW,
    ADC_PRIORITY_HW_SW,
    ADC_PRIORITY_NONE
} Adc_PriorityImplementationType;

/* Result Alignment */
typedef enum {
    ADC_ALIGN_LEFT,
    ADC_ALIGN_RIGHT
} AdcResultAlignmentType;

/* Channel Range */
typedef enum {
    ADC_RANGE_DEFAULT,
    ADC_RANGE_EXTENDED
} AdcChannelRangeSelectType;

/* Access Mode */
typedef enum {
    ADC_ACCESS_MODE_SINGLE,
    ADC_ACCESS_MODE_STREAMING
} AdcGroupAccessModeType;

/* Conversion Mode */
typedef enum {
    ADC_CONV_MODE_ONESHOT,
    ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/* Replacement Mode */
typedef enum {
    ADC_REPLACE_MODE_DISCARD_OLD,
    ADC_REPLACE_MODE_OVERWRITE
} AdcGroupReplacementType;

/* Trigger Source */
typedef enum {
    ADC_TRIGG_SRC_SW,
    ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;

/* Streaming Buffer Mode */
typedef enum {
    ADC_STREAM_BUFFER_LINEAR,
    ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/* Adc Channel Configuration */
typedef struct {
    uint16 AdcChannelId;
    uint16 AdcChannelConvTime;
    uint16 AdcChannelHighLimit;
    uint16 AdcChannelLowLimit;
    boolean AdcChannelLimitCheck;
    AdcChannelRangeSelectType AdcChannelRangeSelect;
    boolean AdcChannelRefVoltsrcHigh;
    boolean AdcChannelRefVoltsrcLow;
    uint8 AdcChannelResolution;
    uint16 AdcChannelSampTime;
} Adc_ChannelType;

/* Adc Group Configuration */
typedef struct {
    uint16 AdcGroupId;
    AdcGroupAccessModeType AdcGroupAccessMode;
    Adc_GroupConvModeType AdcGroupConversionMode;
    uint8 AdcGroupPriority;
    AdcGroupReplacementType AdcGroupReplacement;
    Adc_TriggerSourceType AdcGroupTriggSrc;
    uint8 AdcHwTrigSignal;
    uint16 AdcHwTrigTimer;
    boolean AdcNotification;
    Adc_StreamBufferModeType AdcStreamingBufferMode;
    uint16 AdcStreamingNumSamples;
    uint16 AdcGroupDefinition; /* links to channel IDs */
} AdcGroupConfigType;

/* Adc Power State Config */
typedef struct {
    uint8 AdcPowerState;
    const char* AdcPowerStateReadyCbkRef;
} Adc_PowerStateType;

/* Main Adc Config */
typedef struct {
    Adc_PriorityImplementationType AdcPriorityImplementation;
    AdcResultAlignmentType AdcResultAlignment;
    uint8 AdcHwUnit;
    const Adc_ChannelType* AdcChannels;
    uint16 NumChannels;
    const AdcGroupConfigType* AdcGroups;
    uint16 NumGroups;
    const Adc_PowerStateType* AdcPowerStates;
    uint16 NumPowerStates;
} Adc_ConfigType;

/* ============================ */
/*        API PROTOTYPES        */
/* ============================ */
void Adc_Init(const Adc_ConfigType* ConfigPtr);

#if (ADC_DEINIT_API == STD_ON)
void Adc_DeInit(void);
#endif

Std_ReturnType Adc_SetupResultBuffer(uint16 Group, uint16* BufferPtr);

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
Std_ReturnType Adc_StartGroupConversion(uint16 Group);
Std_ReturnType Adc_StopGroupConversion(uint16 Group);
#endif

#if (ADC_READ_GROUP_API == STD_ON)
Std_ReturnType Adc_ReadGroup(uint16 Group, uint16* DataBufferPtr);
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
void Adc_EnableHardwareTrigger(uint16 Group);
void Adc_DisableHardwareTrigger(uint16 Group);
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
void Adc_EnableGroupNotification(uint16 Group);
void Adc_DisableGroupNotification(uint16 Group);
#endif

Std_ReturnType Adc_GetGroupStatus(uint16 Group);
Std_ReturnType Adc_GetStreamLastPointer(uint16 Group, uint16** PtrToSamplePtr);

#if (ADC_VERSION_INFO_API == STD_ON)
void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/* Power States */
Std_ReturnType Adc_SetPowerState(uint8 PowerState);
Std_ReturnType Adc_GetCurrentPowerState(uint8* CurrentState);
Std_ReturnType Adc_GetTargetPowerState(uint8* TargetState);
Std_ReturnType Adc_PreparePowerState(uint8 PowerState, uint8 TransitionMode);
void Adc_Main_PowerTransitionManager(void);
#endif

#endif /* ADC_H_ */

