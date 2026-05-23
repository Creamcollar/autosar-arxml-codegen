
#include "Can.h"
#include "Can_Cfg.h"
#include <stddef.h>

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Can.c
 * @brief CAN Implementation File
 * @details Generated CAN Implementation from ARXML
 * Generated from ARXML: can_config.arxml
 */

/*
 * =================================================================================================
 * Section 1: STM32F407VGT6 Peripheral Register Definitions
 * =================================================================================================
 */

#define PERIPH_BASE           ((uint32_t)0x40000000)
#define APB1PERIPH_BASE       PERIPH_BASE
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)

/* RCC Registers */
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)
#define RCC_APB1ENR           (*(volatile uint32_t*)(RCC_BASE + 0x40))
#define RCC_AHB1ENR           (*(volatile uint32_t*)(RCC_BASE + 0x30))

/* GPIOA Registers (for CAN) */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOA_MODER           (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_AFRH            (*(volatile uint32_t*)(GPIOA_BASE + 0x24))
#define GPIOA_PUPDR           (*(volatile uint32_t*)(GPIOA_BASE + 0x0C))

/* CAN1 Registers */
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400)
typedef struct {
    volatile uint32_t MCR;
    volatile uint32_t MSR;
    volatile uint32_t TSR;
    volatile uint32_t RF0R;
    volatile uint32_t RF1R;
    volatile uint32_t IER;
    volatile uint32_t ESR;
    volatile uint32_t BTR;
    volatile uint32_t RESERVED0;
    struct {
        volatile uint32_t TIR;
        volatile uint32_t TDTR;
        volatile uint32_t TDLR;
        volatile uint32_t TDHR;
    } sTxMailBox[3];
    struct {
        volatile uint32_t RIR;
        volatile uint32_t RDTR;
        volatile uint32_t RDLR;
        volatile uint32_t RDHR;
    } sFIFOMailBox[2];
    volatile uint32_t RESERVED1[4];
    volatile uint32_t FMR;
    volatile uint32_t FM1R;
    volatile uint32_t RESERVED2;
    volatile uint32_t FS1R;
    volatile uint32_t RESERVED3;
    volatile uint32_t FFA1R;
    volatile uint32_t RESERVED4;
    volatile uint32_t FA1R;
    volatile uint32_t RESERVED5[8];
    struct {
        volatile uint32_t FR1;
        volatile uint32_t FR2;
    } sFilterRegister[28];
} CAN_TypeDef;

#define CAN1                  ((CAN_TypeDef *)CAN1_BASE)

/* NVIC Registers */
#define NVIC_ISER_BASE        ((volatile uint32_t*)0xE000E100)
#define NVIC_ICER_BASE        ((volatile uint32_t*)0xE000E180)

#define CAN1_TX_IRQn          19
#define CAN1_RX0_IRQn         20

/*
 * =================================================================================================
 * Section 2: Mock CAN Interface (CanIf) Callbacks
 * =================================================================================================
 */

void CanIf_TxConfirmation(PduIdType CanTxPduId);
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr);
void CanIf_ControllerBusOff(uint8_t ControllerId);

/*
 * =================================================================================================
 * Section 3: CAN Driver Static Data and State Variables
 * =================================================================================================
 */

/* Module Version Information */
#define CAN_SW_MAJOR_VERSION   (1U)
#define CAN_SW_MINOR_VERSION   (0U)
#define CAN_SW_PATCH_VERSION   (0U)

/* AUTOSAR Specification Version */
#define CAN_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_AR_RELEASE_MINOR_VERSION   (11U)
#define CAN_AR_RELEASE_REVISION_VERSION (0U) /* Corresponds to R24-11 */

/* Vendor and Module Information */
#define CAN_VENDOR_ID    (0xFFFFU) /* Fictitious Vendor ID */
#define CAN_MODULE_ID    (80U)

/* Module State Variables */
static const Can_ConfigType* Can_GlobalConfig = NULL;
static Can_ControllerStateType Can_ControllerState[CAN_CONTROLLER_MAX_COUNT];
static uint8_t Can_InterruptDisableCount[CAN_CONTROLLER_MAX_COUNT] = {0};
static Can_TimeStampType Can_SystemTimestamp = 0; /* Simple timestamp counter */

/*
 * =================================================================================================
 * Section 4: AUTOSAR CAN Driver API Implementation
 * =================================================================================================
 */

#if (CAN_VERSION_INFO_API == TRUE)
void Can_GetVersionInfo(Std_VersionInfoType* versioninfo) {
    if (versioninfo == NULL) {
        /* Per SWS_Can_00177, DET: Report CAN_E_PARAM_POINTER */
        return;
    }
    versioninfo->vendorID = CAN_VENDOR_ID;
    versioninfo->moduleID = CAN_MODULE_ID;
    versioninfo->sw_major_version = CAN_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = CAN_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = CAN_SW_PATCH_VERSION;
}
#endif

void Can_Init(const Can_ConfigType* Config) {
    if (Can_GlobalConfig != NULL) {
        /* Per SWS_Can_00174, DET: Report CAN_E_TRANSITION */
        return;
    }
    Can_GlobalConfig = Config;
    const Can_ControllerConfigType* controllerCfg = &Can_GlobalConfig->Controllers[0];
    const Can_ControllerBaudrateConfigType* baudrateCfg = controllerCfg->DefaultBaudrate;

    /* 1. Enable peripheral clocks */
    RCC_AHB1ENR |= (1 << 0);  /* Enable GPIOA clock */
    RCC_APB1ENR |= (1 << 25); /* Enable CAN1 clock */

    /* 2. Configure GPIO pins for CAN1 (PA11-RX, PA12-TX) */
    GPIOA_MODER &= ~((3U << 22) | (3U << 24)); /* Clear mode for PA11, PA12 */
    GPIOA_MODER |=  ((2U << 22) | (2U << 24)); /* Set PA11, PA12 to Alternate Function */
    GPIOA_AFRH  &= ~((0xFU << 12) | (0xFU << 16));/* Clear AF for PA11, PA12 */
    GPIOA_AFRH |=  ((9U << 12) | (9U << 16)); /* Set AF9 for CAN1 on PA11, PA12 */
    GPIOA_PUPDR &= ~((3U << 22)); /* Clear pull-up/down for PA11 */
    GPIOA_PUPDR |=  ((1U << 22)); /* Set pull-up for PA11 (CAN RX) */

    /* 3. Configure CAN peripheral */
    CAN1->MCR |= (1 << 0); /* INRQ = 1: Enter initialization mode */
    while (!((CAN1->MSR >> 0) & 1)); /* Wait for INAK=1 */

    CAN1->MCR &= ~(1 << 1); /* SLEEP = 0: Exit sleep mode */

    /* Set CAN bit timing for 500kbps with 42MHz APB1 clock */
    uint32_t brp = 5; /* (5+1)=6 -> Prescaler=6. 42MHz/6=7MHz. 7MHz/14Tq=500kbps */
    CAN1->BTR = (((baudrateCfg->SyncJumpWidth - 1) & 0x03) << 24) |
                (((baudrateCfg->Seg2 - 1) & 0x07) << 20) |
                (((baudrateCfg->Seg1 - 1) & 0x0F) << 16) |
                (brp & 0x3FF);

    CAN1->BTR |= (1 << 30); /* LBKM = 1: Enable loopback mode for this example */

    CAN1->MCR &= ~(1 << 2); /* TTCM = 0 (Time Triggered Mode disabled) */
    CAN1->MCR &= ~(1 << 3); /* ABOM = 0 (Bus-Off Management disabled per SWS_Can_00274) */
    CAN1->MCR &= ~(1 << 4); /* AWUM = 0 (Automatic Wakeup disabled) */
    CAN1->MCR &= ~(1 << 5); /* NART = 0 (Automatic Retransmission enabled) */
    CAN1->MCR &= ~(1 << 6); /* RFLM = 0 (Receive FIFO not locked on overrun) */
    CAN1->MCR |=  (1 << 7); /* TXFP = 1 (Transmit FIFO Priority by request order) */

    /* 4. Configure CAN filters (Accept all messages) */
    CAN1->FMR |= (1 << 0);  /* FINIT = 1: Filter initialization mode */
    CAN1->FA1R &= ~(1 << 0); /* Deactivate filter 0 */
    CAN1->FS1R |= (1 << 0);  /* Set filter 0 to 32-bit scale */
    CAN1->FM1R &= ~(1 << 0); /* Set filter 0 to mask mode */
    CAN1->sFilterRegister[0].FR1 = 0x00000000; /* ID bits */
    CAN1->sFilterRegister[0].FR2 = 0x00000000; /* Mask bits (0 = don't care) */
    CAN1->FFA1R &= ~(1 << 0);/* Assign filter 0 to FIFO 0 */
    CAN1->FA1R |= (1 << 0);  /* Activate filter 0 */
    CAN1->FMR &= ~(1 << 0); /* FINIT = 0: Leave filter initialization mode */

    /* 5. Enable Interrupts at peripheral level */
    CAN1->IER |= (1 << 1); /* FMPIE0 = 1 (FIFO 0 Message Pending Interrupt) */
    CAN1->IER |= (1 << 0); /* TMEIE = 1 (Transmit Mailbox Empty Interrupt) */
    
    /* 6. Enable Interrupts at NVIC level */
    NVIC_ISER_BASE[CAN1_RX0_IRQn / 32] = (1 << (CAN1_RX0_IRQn % 32));
    NVIC_ISER_BASE[CAN1_TX_IRQn / 32]  = (1 << (CAN1_TX_IRQn % 32));

    /* Initialize timestamp counter */
    Can_SystemTimestamp = 0;

    Can_ControllerState[controllerCfg->CanControllerId] = CAN_CS_STOPPED;
}

void Can_DeInit(void) {
    if (Can_GlobalConfig == NULL) {
        /* Per SWS_Can_91011, DET: Report CAN_E_UNINIT */
        return;
    }
    /* This check should iterate over all controllers */
    if (Can_ControllerState[0] == CAN_CS_STARTED) {
        /* Per SWS_Can_91012, DET: Report CAN_E_TRANSITION */
        return;
    }
    
    /* Reset CAN peripheral registers */
    CAN1->MCR |= (1 << 15); /* RESET = 1 */
    
    /* Disable clocks */
    RCC_APB1ENR &= ~(1 << 25);
    
    /* Reset global variables */
    Can_GlobalConfig = NULL;
    Can_ControllerState[0] = CAN_CS_UNINIT;
}

Std_ReturnType Can_SetControllerMode(uint8_t Controller, Can_ControllerStateType Transition) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_00198, DET: CAN_E_UNINIT */ return E_NOT_OK; }
    if (Controller >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_00199, DET: CAN_E_PARAM_CONTROLLER */ return E_NOT_OK; }

    switch (Transition) {
        case CAN_CS_STARTED:
            if (Can_ControllerState[Controller] == CAN_CS_STOPPED) {
                CAN1->MCR &= ~(1 << 0); /* INRQ = 0: Leave initialization mode */
                while (((CAN1->MSR >> 0) & 1)); /* Wait for INAK=0 */
                Can_ControllerState[Controller] = CAN_CS_STARTED;
                return E_OK;
            }
            break;
        case CAN_CS_STOPPED:
            if (Can_ControllerState[Controller] == CAN_CS_STARTED || Can_ControllerState[Controller] == CAN_CS_SLEEP) {
                CAN1->MCR |= (1 << 0); /* INRQ = 1: Enter initialization mode */
                while (!((CAN1->MSR >> 0) & 1)); /* Wait for INAK=1 */
                Can_ControllerState[Controller] = CAN_CS_STOPPED;
                return E_OK;
            }
            break;
        case CAN_CS_SLEEP:
            if (Can_ControllerState[Controller] == CAN_CS_STOPPED) {
                CAN1->MCR &= ~(1 << 0); /* Ensure not in init mode */
                CAN1->MCR |= (1 << 1); /* SLEEP = 1: Enter sleep mode */
                while (!((CAN1->MSR >> 1) & 1)); /* Wait for SLAK=1 */
                Can_ControllerState[Controller] = CAN_CS_SLEEP;
                return E_OK;
            }
            break;
        default:
            /* Per SWS_Can_00200, DET: Report CAN_E_TRANSITION */
            return E_NOT_OK;
    }
    /* Per SWS_Can_00200, DET: Report CAN_E_TRANSITION */
    return E_NOT_OK;
}

void Can_DisableControllerInterrupts(uint8_t Controller) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_00205, DET: CAN_E_UNINIT */ return; }
    if (Controller >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_00206, DET: CAN_E_PARAM_CONTROLLER */ return; }
    
    /* Per SWS_Can_00202 for nesting */
    if (Can_InterruptDisableCount[Controller] == 0) {
        NVIC_ICER_BASE[CAN1_TX_IRQn / 32]  = (1 << (CAN1_TX_IRQn % 32));
        NVIC_ICER_BASE[CAN1_RX0_IRQn / 32] = (1 << (CAN1_RX0_IRQn % 32));
    }
    Can_InterruptDisableCount[Controller]++;
}

void Can_EnableControllerInterrupts(uint8_t Controller) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_00209, DET: CAN_E_UNINIT */ return; }
    if (Controller >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_00210, DET: CAN_E_PARAM_CONTROLLER */ return; }

    /* Per SWS_Can_00202 for nesting */
    if (Can_InterruptDisableCount[Controller] > 0) {
        Can_InterruptDisableCount[Controller]--;
        if (Can_InterruptDisableCount[Controller] == 0) {
            NVIC_ISER_BASE[CAN1_TX_IRQn / 32]  = (1 << (CAN1_TX_IRQn % 32));
            NVIC_ISER_BASE[CAN1_RX0_IRQn / 32] = (1 << (CAN1_RX0_IRQn % 32));
        }
    }
}

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_00216, DET: CAN_E_UNINIT */ return E_NOT_OK; }
    if (PduInfo == NULL) { /* Per SWS_Can_00219, DET: CAN_E_PARAM_POINTER */ return E_NOT_OK; }
    if (Hth >= Can_GlobalConfig->Controllers[0].HohCount) { /* Per SWS_Can_00217, DET: CAN_E_PARAM_HANDLE */ return E_NOT_OK; }
    if (PduInfo->length > 8) { /* Per SWS_Can_00218, DET: CAN_E_PARAM_DATA_LENGTH */ return E_NOT_OK; }

    uint8_t free_mailbox;
    if ((CAN1->TSR >> 26) & 1) { free_mailbox = 0; }
    else if ((CAN1->TSR >> 27) & 1) { free_mailbox = 1; }
    else if ((CAN1->TSR >> 28) & 1) { free_mailbox = 2; }
    else { return CAN_BUSY; } /* Per SWS_Can_00213 */

    /* Per SWS_Can_00212 */
    CAN1->sTxMailBox[free_mailbox].TIR = (PduInfo->id << 21); /* Assuming Standard ID */
    CAN1->sTxMailBox[free_mailbox].TDTR = (PduInfo->length & 0xF);
    CAN1->sTxMailBox[free_mailbox].TDLR = ((uint32_t)PduInfo->sdu[3] << 24) | ((uint32_t)PduInfo->sdu[2] << 16) | ((uint32_t)PduInfo->sdu[1] << 8) | ((uint32_t)PduInfo->sdu[0]);
    CAN1->sTxMailBox[free_mailbox].TDHR = ((uint32_t)PduInfo->sdu[7] << 24) | ((uint32_t)PduInfo->sdu[6] << 16) | ((uint32_t)PduInfo->sdu[5] << 8) | ((uint32_t)PduInfo->sdu[4]);
    CAN1->sTxMailBox[free_mailbox].TIR |= (1 << 0); /* TXRQ = 1 */

    return E_OK;
}

#if (CAN_SET_BAUDRATE_API == TRUE)
Std_ReturnType Can_SetBaudrate(uint8_t Controller, uint16_t BaudRateConfigID) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_00492, DET: CAN_E_UNINIT */ return E_NOT_OK; }
    if (Controller >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_00494, DET: CAN_E_PARAM_CONTROLLER */ return E_NOT_OK; }
    if (Can_ControllerState[Controller]!= CAN_CS_STOPPED) { /* Per SWS_Can_00256 */ return E_NOT_OK; }
    
    /* This is a simplified implementation. A full implementation would search a table of baudrate configs. */
    const Can_ControllerBaudrateConfigType* baudrateCfg = Can_GlobalConfig->Controllers[Controller].DefaultBaudrate;
    uint32_t brp = 5;
    CAN1->BTR = (((baudrateCfg->SyncJumpWidth - 1) & 0x03) << 24) |
                (((baudrateCfg->Seg2 - 1) & 0x07) << 20) |
                (((baudrateCfg->Seg1 - 1) & 0x0F) << 16) |
                (brp & 0x3FF);
    return E_OK;
}
#endif

Std_ReturnType Can_GetControllerMode(uint8_t Controller, Can_ControllerStateType* ControllerModePtr) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_91016, DET: CAN_E_UNINIT */ return E_NOT_OK; }
    if (Controller >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_91017, DET: CAN_E_PARAM_CONTROLLER */ return E_NOT_OK; }
    if (ControllerModePtr == NULL) { /* Per SWS_Can_91018, DET: CAN_E_PARAM_POINTER */ return E_NOT_OK; }
    
    *ControllerModePtr = Can_ControllerState[Controller];
    return E_OK;
}

Std_ReturnType Can_GetControllerErrorState(uint8_t ControllerId, Can_ErrorStateType* ErrorStatePtr) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_91005, DET: CAN_E_UNINIT */ return E_NOT_OK; }
    if (ControllerId >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_91006, DET: CAN_E_PARAM_CONTROLLER */ return E_NOT_OK; }
    if (ErrorStatePtr == NULL) { /* Per SWS_Can_91007, DET: CAN_E_PARAM_POINTER */ return E_NOT_OK; }

    uint32_t esr = CAN1->ESR;
    if (esr & (1 << 2)) { /* BOFF bit */
        *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF;
    } else if (esr & (1 << 1)) { /* EPVF bit */
        *ErrorStatePtr = CAN_ERRORSTATE_PASSIVE;
    } else {
        *ErrorStatePtr = CAN_ERRORSTATE_ACTIVE;
    }
    return E_OK;
}

/* Added missing function implementations */

Std_ReturnType Can_GetControllerRxErrorCounter(uint8_t ControllerId, uint8_t* RxErrorCounterPtr) {
    if (Can_GlobalConfig == NULL) { return E_NOT_OK; }
    if (ControllerId >= Can_GlobalConfig->ControllerCount) { return E_NOT_OK; }
    if (RxErrorCounterPtr == NULL) { return E_NOT_OK; }
    
    /* Extract RX error counter from ESR register (bits 31-24) */
    uint32_t esr = CAN1->ESR;
    *RxErrorCounterPtr = (uint8_t)((esr >> 24) & 0xFF);
    return E_OK;
}

Std_ReturnType Can_GetControllerTxErrorCounter(uint8_t ControllerId, uint8_t* TxErrorCounterPtr) {
    if (Can_GlobalConfig == NULL) { return E_NOT_OK; }
    if (ControllerId >= Can_GlobalConfig->ControllerCount) { return E_NOT_OK; }
    if (TxErrorCounterPtr == NULL) { return E_NOT_OK; }
    
    /* Extract TX error counter from ESR register (bits 23-16) */
    uint32_t esr = CAN1->ESR;
    *TxErrorCounterPtr = (uint8_t)((esr >> 16) & 0xFF);
    return E_OK;
}

#if (CAN_GET_CURRENT_TIME_API == TRUE)
Std_ReturnType Can_GetCurrentTime(uint8_t ControllerId, Can_TimeStampType* TimeStampPtr) {
    if (Can_GlobalConfig == NULL) { return E_NOT_OK; }
    if (ControllerId >= Can_GlobalConfig->ControllerCount) { return E_NOT_OK; }
    if (TimeStampPtr == NULL) { return E_NOT_OK; }
    
    /* Simple timestamp implementation - increment on each call */
    Can_SystemTimestamp++;
    *TimeStampPtr = Can_SystemTimestamp;
    return E_OK;
}
#endif

#if (CAN_SET_BAUDRATE_API == TRUE)
Std_ReturnType Can_EnableEgressTimeStamp(Can_HwHandleType Hth) {
    if (Can_GlobalConfig == NULL) { return E_NOT_OK; }
    if (Hth >= Can_GlobalConfig->Controllers[0].HohCount) { return E_NOT_OK; }
    
    /* Stub implementation - would enable timestamp for TX messages */
    /* In real implementation, this would configure hardware timestamp capture */
    return E_OK;
}

Std_ReturnType Can_GetEgressTimeStamp(PduIdType TxPduId, Can_HwHandleType Hth, Can_TimeStampType* TimeStampPtr) {
    if (Can_GlobalConfig == NULL) { return E_NOT_OK; }
    if (TimeStampPtr == NULL) { return E_NOT_OK; }
    if (Hth >= Can_GlobalConfig->Controllers[0].HohCount) { return E_NOT_OK; }
    
    /* Stub implementation - would return actual TX timestamp */
    *TimeStampPtr = Can_SystemTimestamp;
    return E_OK;
}

Std_ReturnType Can_GetIngressTimeStamp(Can_HwHandleType Hrh, Can_TimeStampType* TimeStampPtr) {
    if (Can_GlobalConfig == NULL) { return E_NOT_OK; }
    if (TimeStampPtr == NULL) { return E_NOT_OK; }
    if (Hrh >= Can_GlobalConfig->Controllers[0].HohCount) { return E_NOT_OK; }
    
    /* Stub implementation - would return actual RX timestamp */
    *TimeStampPtr = Can_SystemTimestamp;
    return E_OK;
}
#endif

Std_ReturnType Can_CheckWakeup(uint8_t Controller) {
    if (Can_GlobalConfig == NULL) { /* Per SWS_Can_00362, DET: CAN_E_UNINIT */ return E_NOT_OK; }
    if (Controller >= Can_GlobalConfig->ControllerCount) { /* Per SWS_Can_00363, DET: CAN_E_PARAM_CONTROLLER */ return E_NOT_OK; }
    
    if (Can_ControllerState[Controller] == CAN_CS_SLEEP && !((CAN1->MSR >> 1) & 1)) {
        /* Per SWS_Can_00361, one would call EcuM_SetWakeupEvent here */
        return E_OK;
    }
    return E_NOT_OK;
}

/* Polling functions (stubs for this interrupt-driven example) */
void Can_MainFunction_Write(void) { 
    /* Per SWS_Can_00031, polls for TX confirmation if configured */
    /* In polling mode, this function would check TX status and call CanIf_TxConfirmation */
}

void Can_MainFunction_Read(void) { 
    /* Per SWS_Can_00108, polls for RX indication if configured */
    /* In polling mode, this function would check RX FIFO and call CanIf_RxIndication */
}

void Can_MainFunction_BusOff(void) { 
    /* Per SWS_Can_00109, polls for BusOff events if configured */
    /* Check if controller is in bus-off state and handle recovery */
    if (Can_GlobalConfig != NULL) {
        uint32_t esr = CAN1->ESR;
        if (esr & (1 << 2)) { /* BOFF bit set */
            CanIf_ControllerBusOff(0);
        }
    }
}

void Can_MainFunction_Wakeup(void) { 
    /* Per SWS_Can_00112, polls for Wakeup events if configured */
    /* Check for wakeup conditions in polling mode */
}

void Can_MainFunction_Mode(void) { 
    /* Per SWS_Can_00369, polls for mode transitions if configured */
    /* Handle pending mode transition requests in polling mode */
}

/*
 * =================================================================================================
 * Section 5: Interrupt Service Routines
 * =================================================================================================
 */

void CAN1_TX_IRQHandler(void) {
    if ((CAN1->TSR >> 0) & 1) { /* RQCP0 */
        CAN1->TSR |= (1 << 0); /* Clear RQCP0 flag */
        CanIf_TxConfirmation(0); /* PduId is mocked here */
    }
    if ((CAN1->TSR >> 8) & 1) { /* RQCP1 */
        CAN1->TSR |= (1 << 8); /* Clear RQCP1 flag */
        CanIf_TxConfirmation(1);
    }
    if ((CAN1->TSR >> 16) & 1) { /* RQCP2 */
        CAN1->TSR |= (1 << 16); /* Clear RQCP2 flag */
        CanIf_TxConfirmation(2);
    }
}

void CAN1_RX0_IRQHandler(void) {
    if ((CAN1->RF0R & 0x3) > 0) { /* Check if message is pending in FIFO 0 */
        Can_HwType mailbox;
        PduInfoType pduInfo;
        uint8_t rx_data[8];

        mailbox.ControllerId = 0;
        mailbox.Hoh = CanHardwareObject_Rx_Hrh;
        mailbox.CanId = (CAN1->sFIFOMailBox[0].RIR >> 21);

        pduInfo.SduLength = (CAN1->sFIFOMailBox[0].RDTR & 0xF);
        pduInfo.SduDataPtr = rx_data;

        uint32_t data_low = CAN1->sFIFOMailBox[0].RDLR;
        uint32_t data_high = CAN1->sFIFOMailBox[0].RDHR;
        rx_data[0] = (data_low >> 0) & 0xFF;
        rx_data[1] = (data_low >> 8) & 0xFF;
        rx_data[2] = (data_low >> 16) & 0xFF;
        rx_data[3] = (data_low >> 24) & 0xFF;
        rx_data[4] = (data_high >> 0) & 0xFF;
        rx_data[5] = (data_high >> 8) & 0xFF;
        rx_data[6] = (data_high >> 16) & 0xFF;
        rx_data[7] = (data_high >> 24) & 0xFF;

        CAN1->RF0R |= (1 << 5); /* RFOM0 = 1: Release FIFO 0 output mailbox */

        CanIf_RxIndication(&mailbox, &pduInfo);
    }
}
