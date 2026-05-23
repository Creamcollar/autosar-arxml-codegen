

/**
 * Developer: Aruvi B & Auroshaa A from CreamCollar
 * @file Dio.c
 * @brief DIO Implementation File
 * @details Generated DIO Implementation from ARXML
 * Generated from ARXML: dio_config.arxml
 */

#include "Dio.h"
#include "Dio_cfg.h"

/* Hardware initialization for STM32F407VGT6 Discovery Board */
void Dio_InitHardware(void)
{
    /* Enable GPIOD clock (bit 3 in RCC_AHB1ENR) */
    RCC_AHB1ENR |= (1U << 3);

    /* Configure PD12, PD13, PD14, PD15 as outputs (LEDs on F407 Discovery) */
    /* Clear MODER bits 24-31 (2 bits per pin) */
    GPIOD->MODER &= ~(0xFFU << 24);
    /* Set as outputs (01 for each pin) */
    GPIOD->MODER |= (0x55U << 24);

    /* Set pins as push-pull output (default) */
    GPIOD->OTYPER &= ~(0xFU << 12);

    /* Set medium speed */
    GPIOD->OSPEEDR |= (0xAAU << 24);

    /* No pull-up/pull-down */
    GPIOD->PUPDR &= ~(0xFFU << 24);

    /* Initialize all LEDs OFF */
    GPIOD->ODR &= ~(0xFU << 12);
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    GPIO_TypeDef *GPIOx;
    uint8_t pin;

    /* Map channel ID to GPIO port and pin for F407VGT6 Discovery */
    switch(ChannelId) {
        case 0: GPIOx = GPIOD; pin = 12; break;  /* Green LED */
        case 1: GPIOx = GPIOD; pin = 13; break;  /* Orange LED */
        case 2: GPIOx = GPIOD; pin = 14; break;  /* Red LED */
        case 3: GPIOx = GPIOD; pin = 15; break;  /* Blue LED */
        default: return STD_LOW;
    }

    /* Read pin state */
    if (GPIOx->IDR & (1U << pin)) {
        return STD_HIGH;
    } else {
        return STD_LOW;
    }
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    GPIO_TypeDef *GPIOx;
    uint8_t pin;

    /* Map channel ID to GPIO port and pin for F407VGT6 Discovery */
    switch(ChannelId) {
        case 0: GPIOx = GPIOD; pin = 12; break;  /* Green LED */
        case 1: GPIOx = GPIOD; pin = 13; break;  /* Orange LED */
        case 2: GPIOx = GPIOD; pin = 14; break;  /* Red LED */
        case 3: GPIOx = GPIOD; pin = 15; break;  /* Blue LED */
        default: return;
    }

    /* Write pin state using BSRR register for atomic operation */
    if (Level == STD_HIGH) {
        GPIOx->BSRR = (1U << pin);          /* Set bit */
    } else {
        GPIOx->BSRR = (1U << (pin + 16));   /* Reset bit */
    }
}

/* Keep your other functions as they were, but replace the GPIO function calls */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    GPIO_TypeDef *GPIOx;

    switch (PortId) {
        case 0: GPIOx = GPIOA; break;
        case 1: GPIOx = GPIOB; break;
        case 2: GPIOx = GPIOC; break;
        case 3: GPIOx = GPIOD; break;
        default: return 0;
    }

    return (Dio_PortLevelType)(GPIOx->IDR & 0xFFFF);
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    GPIO_TypeDef *GPIOx;

    switch (PortId) {
        case 0: GPIOx = GPIOA; break;
        case 1: GPIOx = GPIOB; break;
        case 2: GPIOx = GPIOC; break;
        case 3: GPIOx = GPIOD; break;
        default: return;
    }

    GPIOx->ODR = (uint32_t)Level;
}

/* Add other functions following the same pattern... */
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    if (versioninfo != NULL) {
        versioninfo->vendorID = 1810U;
        versioninfo->moduleID = 202U;
        versioninfo->sw_major_version = 1U;
        versioninfo->sw_minor_version = 0U;
        versioninfo->sw_patch_version = 0U;
    }
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType currentLevel = Dio_ReadChannel(ChannelId);
    Dio_LevelType newLevel = (currentLevel == STD_HIGH) ? STD_LOW : STD_HIGH;
    Dio_WriteChannel(ChannelId, newLevel);
    return newLevel;
}

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    GPIO_TypeDef *GPIOx;
    Dio_PortLevelType portValue;
    Dio_PortLevelType maskedValue;

    /* Check for null pointer */
    if (ChannelGroupIdPtr == NULL) {
        return 0;
    }

    /* Map port ID to GPIO port */
    switch (ChannelGroupIdPtr->port) {
        case 0: GPIOx = GPIOA; break;
        case 1: GPIOx = GPIOB; break;
        case 2: GPIOx = GPIOC; break;
        case 3: GPIOx = GPIOD; break;
        default: return 0;
    }

    /* Read entire port */
    portValue = (Dio_PortLevelType)(GPIOx->IDR & 0xFFFF);

    /* Apply mask to get only the channel group bits */
    maskedValue = portValue & ChannelGroupIdPtr->mask;

    /* Shift right to align to LSB based on offset */
    maskedValue = maskedValue >> ChannelGroupIdPtr->offset;

    return maskedValue;
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    GPIO_TypeDef *GPIOx;
    Dio_PortLevelType currentPortValue;
    Dio_PortLevelType newPortValue;
    Dio_PortLevelType shiftedLevel;

    /* Check for null pointer */
    if (ChannelGroupIdPtr == NULL) {
        return;
    }

    /* Map port ID to GPIO port */
    switch (ChannelGroupIdPtr->port) {
        case 0: GPIOx = GPIOA; break;
        case 1: GPIOx = GPIOB; break;
        case 2: GPIOx = GPIOC; break;
        case 3: GPIOx = GPIOD; break;
        default: return;
    }

    /* Read current port value */
    currentPortValue = (Dio_PortLevelType)(GPIOx->ODR & 0xFFFF);

    /* Shift the level to the correct position */
    shiftedLevel = Level << ChannelGroupIdPtr->offset;

    /* Clear the bits that will be written (using inverted mask) */
    newPortValue = currentPortValue & (~ChannelGroupIdPtr->mask);

    /* Set the new bits (mask the shifted level to ensure we don't set bits outside the group) */
    newPortValue |= (shiftedLevel & ChannelGroupIdPtr->mask);

    /* Write the new port value */
    GPIOx->ODR = (uint32_t)newPortValue;
}

void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
    GPIO_TypeDef *GPIOx;
    Dio_PortLevelType currentPortValue;
    Dio_PortLevelType newPortValue;

    /* Map port ID to GPIO port */
    switch (PortId) {
        case 0: GPIOx = GPIOA; break;
        case 1: GPIOx = GPIOB; break;
        case 2: GPIOx = GPIOC; break;
        case 3: GPIOx = GPIOD; break;
        default: return;
    }

    /* Read current port value */
    currentPortValue = (Dio_PortLevelType)(GPIOx->ODR & 0xFFFF);

    /* Clear the bits that will be written (using inverted mask) */
    newPortValue = currentPortValue & (~Mask);

    /* Set the new bits (mask the level to ensure we don't set bits outside the mask) */
    newPortValue |= (Level & Mask);

    /* Write the new port value */
    GPIOx->ODR = (uint32_t)newPortValue;
}

