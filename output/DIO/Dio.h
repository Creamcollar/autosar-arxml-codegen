
#ifndef DIO_H
#define DIO_H

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Dio.h
 * @brief DIO Configuration Header File
 * @details Generated DIO Configuration Header from ARXML
 * Generated from ARXML: dio_config.arxml
 */


#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

#define STD_HIGH   (0x01U)
#define STD_LOW    (0x00U)
#define NULL       ((void*)0)

/* AUTOSAR type definitions */
typedef uint8_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef uint16_t Dio_PortLevelType;

typedef struct {
    uint16_t vendorID;
    uint16_t moduleID;
    uint8_t sw_major_version;
    uint8_t sw_minor_version;
    uint8_t sw_patch_version;
} Std_VersionInfoType;

typedef struct {
    uint32_t mask;
    uint8_t offset;
    Dio_PortType port;
} Dio_ChannelGroupType;

/* STM32F407VGT6 GPIO register definitions */
typedef struct {
    volatile uint32_t MODER;    /* GPIO port mode register */
    volatile uint32_t OTYPER;   /* GPIO port output type register */
    volatile uint32_t OSPEEDR;  /* GPIO port output speed register */
    volatile uint32_t PUPDR;    /* GPIO port pull-up/pull-down register */
    volatile uint32_t IDR;      /* GPIO port input data register */
    volatile uint32_t ODR;      /* GPIO port output data register */
    volatile uint32_t BSRR;     /* GPIO port bit set/reset register */
    volatile uint32_t LCKR;     /* GPIO port configuration lock register */
    volatile uint32_t AFR[2];   /* GPIO alternate function registers */
} GPIO_TypeDef;

/* STM32F407VGT6 base addresses */
#define GPIOA_BASE    0x40020000U
#define GPIOB_BASE    0x40020400U
#define GPIOC_BASE    0x40020800U
#define GPIOD_BASE    0x40020C00U
#define RCC_BASE      0x40023800U

#define GPIOA         ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB         ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC         ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD         ((GPIO_TypeDef *) GPIOD_BASE)

#define RCC_AHB1ENR   (*(volatile uint32_t *)(RCC_BASE + 0x30U))

/* Function prototypes */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
void Dio_MaskedWritePort (Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);
void Dio_InitHardware(void);

#ifdef __cplusplus
}
#endif

#endif // DIO_H

