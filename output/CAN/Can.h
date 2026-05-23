
#ifndef CAN_H
#define CAN_H

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Can.h
 * @brief CAN Configuration Header File
 * @details Generated CAN Configuration Header from ARXML
 * Generated from ARXML: can_config.arxml
 */

/*
 * =================================================================================================
 * Section 1: AUTOSAR R24-11 Type Definitions
 * =================================================================================================
 */

#include <stdint.h>
#include "Can_Cfg.h"

/* Standard AUTOSAR Types (Std_Types.h) */
#ifndef TRUE
#define TRUE  1U
#endif
#ifndef FALSE
#define FALSE 0U
#endif

typedef uint8_t Std_ReturnType;
#define E_OK      ((Std_ReturnType)0x00U)
#define E_NOT_OK  ((Std_ReturnType)0x01U)

typedef struct {
    uint16_t vendorID;
    uint16_t moduleID;
    uint8_t  sw_major_version;
    uint8_t  sw_minor_version;
    uint8_t  sw_patch_version;
} Std_VersionInfoType;

/* ComStack Types (ComStack_Types.h) */
typedef uint16_t PduIdType;
typedef uint16_t PduLengthType;
typedef struct {
    uint8_t*      SduDataPtr;
    PduLengthType SduLength;
} PduInfoType;

/* CAN Driver Types (Can_GeneralTypes.h) as per AUTOSAR R24-11 */
typedef uint32_t Can_IdType;
typedef uint16_t Can_HwHandleType;
typedef uint64_t Can_TimeStampType;  /* Added missing timestamp type */

typedef enum {
    CAN_HANDLE_TYPE_BASIC,
    CAN_HANDLE_TYPE_FULL
} Can_HandleType;

typedef enum {
    CAN_ID_TYPE_STANDARD,
    CAN_ID_TYPE_EXTENDED,
    CAN_ID_TYPE_MIXED
} Can_IdTypeType;

typedef enum {
    CAN_OBJECT_TYPE_RECEIVE,
    CAN_OBJECT_TYPE_TRANSMIT
} Can_ObjectTypeType;

typedef enum {
    CAN_PROCESSING_INTERRUPT,
    CAN_PROCESSING_POLLING
} Can_ProcessingType;

typedef struct {
    PduIdType     swPduHandle;
    PduLengthType length;
    Can_IdType    id;
    uint8_t*      sdu;
} Can_PduType;

typedef enum {
    CAN_CS_UNINIT  = 0x00,
    CAN_CS_STARTED = 0x01,
    CAN_CS_STOPPED = 0x02,
    CAN_CS_SLEEP   = 0x03
} Can_ControllerStateType;

typedef enum {
    CAN_ERRORSTATE_ACTIVE,
    CAN_ERRORSTATE_PASSIVE,
    CAN_ERRORSTATE_BUSOFF
} Can_ErrorStateType;

/* Added missing Can_ErrorType with all required error codes */
typedef enum {
    CAN_ERROR_BIT_MONITORING1,
    CAN_ERROR_BIT_MONITORING0, 
    CAN_ERROR_BIT,
    CAN_ERROR_CHECK_ACK_FAILED,
    CAN_ERROR_ACK_DELIMITER,
    CAN_ERROR_ARBITRATION_LOST,
    CAN_ERROR_OVERLOAD,
    CAN_ERROR_CHECK_FORM_FAILED,
    CAN_ERROR_CHECK_STUFFING_FAILED,
    CAN_ERROR_CHECK_CRC_FAILED,
    CAN_ERROR_BUS_LOCK
} Can_ErrorType;

#define CAN_BUSY ((Std_ReturnType)0x02U)

typedef struct {
    uint16_t BaudRate;
    uint16_t BaudRateConfigID;
    uint8_t  PropSeg;
    uint8_t  Seg1;
    uint8_t  Seg2;
    uint8_t  SyncJumpWidth;
} Can_ControllerBaudrateConfigType;

typedef struct Can_ControllerConfig_s {
    uint8_t                            CanControllerId;
    uint8_t                            CanControllerActivation;
    Can_ProcessingType                 CanTxProcessing;
    Can_ProcessingType                 CanRxProcessing;
    Can_ProcessingType                 CanBusoffProcessing;
    Can_ProcessingType                 CanWakeupProcessing;
    const Can_ControllerBaudrateConfigType* DefaultBaudrate;
    const struct Can_HardwareObject_s* Hoh;
    uint8_t                            HohCount;
} Can_ControllerConfigType;

typedef struct Can_HardwareObject_s {
    uint16_t             CanObjectId;
    Can_HandleType       CanHandleType;
    Can_IdTypeType       CanIdType;
    Can_ObjectTypeType   CanObjectType;
    const Can_ControllerConfigType* CanControllerRef;
} Can_HardwareObjectType;

typedef struct {
    const Can_ControllerConfigType* Controllers;
    uint8_t ControllerCount;
} Can_ConfigType;

typedef struct {
    Can_IdType       CanId;
    Can_HwHandleType Hoh;
    uint8_t          ControllerId;
} Can_HwType;

/*
 * =================================================================================================
 * Section 2: AUTOSAR CAN Driver API Function Prototypes
 * =================================================================================================
 */

/* Service for module initialization */
void Can_Init(const Can_ConfigType* Config);

/* Service for module de-initialization */
void Can_DeInit(void);

/* Service to get version information */
#if (CAN_VERSION_INFO_API == TRUE)
void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/* Service to control the CAN controller mode */
Std_ReturnType Can_SetControllerMode(uint8_t Controller, Can_ControllerStateType Transition);

/* Service to get the current controller mode */
Std_ReturnType Can_GetControllerMode(uint8_t Controller, Can_ControllerStateType* ControllerModePtr);

/* Service to disable controller interrupts */
void Can_DisableControllerInterrupts(uint8_t Controller);

/* Service to enable controller interrupts */
void Can_EnableControllerInterrupts(uint8_t Controller);

/* Service to transmit a CAN PDU */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo);

/* Service to change the controller baud rate */
#if (CAN_SET_BAUDRATE_API == TRUE)
Std_ReturnType Can_SetBaudrate(uint8_t Controller, uint16_t BaudRateConfigID);
#endif

/* Service to check for a wakeup event */
Std_ReturnType Can_CheckWakeup(uint8_t Controller);

/* Service to get the controller error state */
Std_ReturnType Can_GetControllerErrorState(uint8_t ControllerId, Can_ErrorStateType* ErrorStatePtr);

/* Added missing functions */

/* Service to get the RX error counter */
Std_ReturnType Can_GetControllerRxErrorCounter(uint8_t ControllerId, uint8_t* RxErrorCounterPtr);

/* Service to get the TX error counter */
Std_ReturnType Can_GetControllerTxErrorCounter(uint8_t ControllerId, uint8_t* TxErrorCounterPtr);

/* Service to get the current time */
#if (CAN_GET_CURRENT_TIME_API == TRUE)
Std_ReturnType Can_GetCurrentTime(uint8_t ControllerId, Can_TimeStampType* TimeStampPtr);
#endif

/* Service to enable egress time stamp */
#if (CAN_SET_BAUDRATE_API == TRUE)
Std_ReturnType Can_EnableEgressTimeStamp(Can_HwHandleType Hth);
#endif

/* Service to get egress time stamp */
#if (CAN_SET_BAUDRATE_API == TRUE)
Std_ReturnType Can_GetEgressTimeStamp(PduIdType TxPduId, Can_HwHandleType Hth, Can_TimeStampType* TimeStampPtr);
#endif

/* Service to get ingress time stamp */
#if (CAN_SET_BAUDRATE_API == TRUE)
Std_ReturnType Can_GetIngressTimeStamp(Can_HwHandleType Hrh, Can_TimeStampType* TimeStampPtr);
#endif

/* Scheduled functions for polling mode */
void Can_MainFunction_Write(void);
void Can_MainFunction_Read(void);
void Can_MainFunction_BusOff(void);
void Can_MainFunction_Wakeup(void);
void Can_MainFunction_Mode(void);

#endif /* CAN_H */


