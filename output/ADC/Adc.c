#include "Adc.h"
#include "Adc_Cfg.h"
#include "stm32_regs.h"

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Adc.c
 * @brief ADC Implementation File
 * @details Generated ADC Implementation from ARXML
 * Generated from ARXML: adc_config.arxml
 */


/* Global state */
static const Adc_ConfigType* Adc_ConfigPtr = NULL_PTR;
static boolean Adc_Initialized = FALSE;
static uint8 Adc_CurrentPowerState = 0U;

/* ============================ */
/*        API DEFINITIONS       */
/* ============================ */


/* Initialize ADC */
void Adc_Init(const Adc_ConfigType* ConfigPtr)
{
    /* Enable ADC1 clock */
    RCC_APB2ENR |= RCC_APB2ENR_ADC1EN;

    /* Enable ADC1 */
    ADC1_CR2 |= ADC_CR2_ADON;

    /* Example: Set sample time for channel 0 */
    ADC1_SMPR2 |= (0x7 << 0);  // 480 cycles for channel 0
}

/* Start conversion on a group (simulate group as channel 0) */
Std_ReturnType Adc_StartGroupConversion(Adc_GroupType Group)
{
    /* Select channel 0 */
    ADC1_SQR3 = 0;

    /* Start conversion */
    ADC1_CR2 |= ADC_CR2_SWSTART;

    return E_OK;
}

/* Read conversion result */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
    while (!(ADC1_SR & ADC_SR_EOC)) ;  // Wait for conversion
    DataBufferPtr[0] = (uint16)ADC1_DR;
    return E_OK;
}


#if (ADC_DEINIT_API == STD_ON)
void Adc_DeInit(void)
{
    Adc_ConfigPtr = NULL_PTR;
    Adc_Initialized = FALSE;
}
#endif

/* Setup buffer for group results */
Std_ReturnType Adc_SetupResultBuffer(uint16 Group, uint16* BufferPtr)
{
    if (!Adc_Initialized) {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_SETUP_RESULT_BUFFER_ID, ADC_E_UNINIT);
#endif
        return E_NOT_OK;
    }
    /* TODO: assign buffer for group */
    return E_OK;
}

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/* Start group conversion */


/* Stop group conversion */
Std_ReturnType Adc_StopGroupConversion(uint16 Group)
{
    if (!Adc_Initialized) {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_STOP_GROUP_CONVERSION_ID, ADC_E_UNINIT);
#endif
        return E_NOT_OK;
    }
    /* TODO: stop hardware conversion */
    return E_OK;
}
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
void Adc_EnableHardwareTrigger(uint16 Group)
{
    if (!Adc_Initialized) {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_ENABLE_HARDWARE_TRIGGER_ID, ADC_E_UNINIT);
#endif
        return;
    }
    /* TODO: enable hardware trigger for group */
}

void Adc_DisableHardwareTrigger(uint16 Group)
{
    if (!Adc_Initialized) {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_DISABLE_HARDWARE_TRIGGER_ID, ADC_E_UNINIT);
#endif
        return;
    }
    /* TODO: disable hardware trigger for group */
}
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/* Notifications */
void Adc_EnableGroupNotification(uint16 Group)
{
    /* TODO: enable interrupts for group */
}

void Adc_DisableGroupNotification(uint16 Group)
{
    /* TODO: disable interrupts for group */
}
#endif

Std_ReturnType Adc_GetGroupStatus(uint16 Group)
{
    if (!Adc_Initialized) {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_GET_GROUP_STATUS_ID, ADC_E_UNINIT);
#endif
        return E_NOT_OK;
    }
    /* TODO: get group status */
    return E_OK;
}

Std_ReturnType Adc_GetStreamLastPointer(uint16 Group, uint16** PtrToSamplePtr)
{
    if (!Adc_Initialized) {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID, ADC_GET_STREAM_LAST_POINTER_ID, ADC_E_UNINIT);
#endif
        return E_NOT_OK;
    }
    /* TODO: get stream last pointer */
    return E_OK;
}

#if (ADC_VERSION_INFO_API == STD_ON)
/* Version Info */
void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    if (versioninfo != NULL_PTR) {
        versioninfo->vendorID = ADC_VENDOR_ID;
        versioninfo->moduleID = ADC_MODULE_ID;
        versioninfo->sw_major_version = ADC_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = ADC_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = ADC_SW_PATCH_VERSION;
    }
}
#endif

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/* Power States */
Std_ReturnType Adc_SetPowerState(uint8 PowerState)
{
    Adc_CurrentPowerState = PowerState;
    return E_OK;
}

Std_ReturnType Adc_GetCurrentPowerState(uint8* CurrentState)
{
    if (CurrentState != NULL_PTR) {
        *CurrentState = Adc_CurrentPowerState;
        return E_OK;
    }
    return E_NOT_OK;
}

Std_ReturnType Adc_GetTargetPowerState(uint8* TargetState)
{
    /* Stub */
    return E_OK;
}

Std_ReturnType Adc_PreparePowerState(uint8 PowerState, uint8 TransitionMode)
{
    /* Stub */
    return E_OK;
}

void Adc_Main_PowerTransitionManager(void)
{
    /* Stub */
    return E_OK;
}
#endif

