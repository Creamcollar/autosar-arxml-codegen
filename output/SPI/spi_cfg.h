#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/*
 * Developer Aruvi B and Auroshaa from CreamCollar
 * Generated SPI Configuration Header
 * Generated from ARXML: spi_config.arxml
 * Generated on: 2026-05-23 15:45:32
 */

/* Module identification */
#define SPI_VENDOR_ID                    (1810U)
#define SPI_MODULE_ID                    (83U)
#define SPI_INSTANCE_ID                  (0U)

/* Module version information */
#define SPI_SW_MAJOR_VERSION             (1U)
#define SPI_SW_MINOR_VERSION             (0U)
#define SPI_SW_PATCH_VERSION             (0U)

/* SPI General Configuration */
#define SPI_CANCEL_API                   STD_ON
#define SPI_CHANNEL_BUFFERS_ALLOWED      (1U)
#define SPI_DEV_ERROR_DETECT             STD_ON
#define SPI_HW_STATUS_API                STD_ON
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED    STD_OFF
#define SPI_LEVEL_DELIVERED              (0U)
#define SPI_MAIN_FUNCTION_PERIOD         (10f)
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT STD_OFF
#define SPI_VERSION_INFO_API             STD_ON

/* User callback header file */

/* SPI Driver Configuration */
#define SPI_MAX_CHANNEL                  (0U)
#define SPI_MAX_JOB                      (0U)
#define SPI_MAX_SEQUENCE                 (0U)

/* SPI Published Information */
#define SPI_MAX_HW_UNIT                  (0U)

/* SPI Error Codes */
#define SPI_E_PARAM_CHANNEL              (0x0AU)
#define SPI_E_PARAM_JOB                  (0x0BU)
#define SPI_E_PARAM_SEQ                  (0x0CU)
#define SPI_E_PARAM_LENGTH               (0x0DU)
#define SPI_E_PARAM_UNIT                 (0x0EU)
#define SPI_E_PARAM_POINTER              (0x10U)
#define SPI_E_UNINIT                     (0x1AU)
#define SPI_E_SEQ_PENDING                (0x2AU)
#define SPI_E_SEQ_IN_PROCESS             (0x3AU)
#define SPI_E_ALREADY_INITIALIZED        (0x4AU)

/* Service IDs */
#define SPI_INIT_SID                     (0x00U)
#define SPI_DEINIT_SID                   (0x01U)
#define SPI_WRITEIB_SID                  (0x02U)
#define SPI_ASYNCTRANSMIT_SID            (0x03U)
#define SPI_READIB_SID                   (0x04U)
#define SPI_SETUPEB_SID                  (0x05U)
#define SPI_GETSTATUS_SID                (0x06U)
#define SPI_GETJOBRESULT_SID             (0x07U)
#define SPI_GETSEQUENCERESULT_SID        (0x08U)
#define SPI_GETVERSIONINFO_SID           (0x09U)
#define SPI_SYNCTRANSMIT_SID             (0x0AU)
#define SPI_GETHWUNITSTATUS_SID          (0x0BU)
#define SPI_CANCEL_SID                   (0x0CU)
#define SPI_SETASYNCMODE_SID             (0x0DU)
#define SPI_MAINFUNCTION_HANDLING_SID    (0x10U)

/* SPI Job Result */
#define SPI_JOB_OK                       (0x00U)
#define SPI_JOB_PENDING                  (0x01U)
#define SPI_JOB_FAILED                   (0x02U)
#define SPI_JOB_QUEUED                   (0x03U)

/* SPI Sequence Result */
#define SPI_SEQ_OK                       (0x00U)
#define SPI_SEQ_PENDING                  (0x01U)
#define SPI_SEQ_FAILED                   (0x02U)
#define SPI_SEQ_CANCELLED                (0x03U)

/* SPI Status */
#define SPI_UNINIT                       (0x00U)
#define SPI_IDLE                         (0x01U)
#define SPI_BUSY                         (0x02U)

/* SPI Hardware Unit Status */
#define SPI_IDLE                         (0x00U)
#define SPI_BUSY                         (0x01U)

/* SPI Asynchronous Mode */
#define SPI_POLLING_MODE                 (0x00U)
#define SPI_INTERRUPT_MODE               (0x01U)

/* SPI Channel Symbolic Names */
#define SpiConf_SpiChannel_Channel_0     (0U)

/* SPI Channel Configuration */
#define SPI_CHANNEL_0_DATA_WIDTH          (8U)
#define SPI_CHANNEL_0_DEFAULT_DATA        (0x0000U)
#define SPI_CHANNEL_0_EB_MAX_LENGTH       (1U)
#define SPI_CHANNEL_0_IB_N_BUFFERS        (1U)
#define SPI_CHANNEL_0_TYPE                (SPI_EB)

/* SPI Job Symbolic Names */
#define SpiConf_SpiJob_Job_0                (0U)

/* SPI Job Configuration */
#define SPI_JOB_0_PRIORITY                    (0U)
#define SPI_JOB_0_HW_UNIT_SYNC                (SPI_ASYNCHRONOUS)
#define SPI_JOB_0_END_NOTIFICATION            (STD_ON)

/* SPI Sequence Symbolic Names */
#define SpiConf_SpiSequence_Sequence_0   (0U)

/* SPI Sequence Configuration */
#define SPI_SEQUENCE_0_INTERRUPTIBLE          (STD_OFF)

/* SPI External Device Configuration */
#define SPI_EXTERNAL_DEVICE_0_BAUDRATE            (1000000U)
#define SPI_EXTERNAL_DEVICE_0_CS_BEHAVIOR         (SPI_CS_KEEP_ASSERTED)
#define SPI_EXTERNAL_DEVICE_0_CS_POLARITY         (SPI_CS_HIGH)
#define SPI_EXTERNAL_DEVICE_0_CS_SELECTION        (SPI_CS_VIA_GPIO)
#define SPI_EXTERNAL_DEVICE_0_DATA_SHIFT_EDGE     (SPI_LEADING)
#define SPI_EXTERNAL_DEVICE_0_HW_UNIT             (SPI_CSIB0)
#define SPI_EXTERNAL_DEVICE_0_SHIFT_CLOCK_IDLE    (SPI_HIGH)
#define SPI_EXTERNAL_DEVICE_0_TIME_CLK2CS         (10U)
#define SPI_EXTERNAL_DEVICE_0_TIME_CS2CLK         (10U)
#define SPI_EXTERNAL_DEVICE_0_TIME_CS2CS          (10U)
#define SPI_EXTERNAL_DEVICE_0_CS_IDENTIFIER       "CS0"

/* SPI Hardware Unit Definitions */
#define SPI_CSIB0                        (0x00U)
#define SPI_CSIB1                        (0x01U)
#define SPI_CSIB2                        (0x02U)
#define SPI_CSIB3                        (0x03U)

/* SPI CS Behavior Definitions */
#define SPI_CS_KEEP_ASSERTED             (0x00U)
#define SPI_CS_TOGGLE                    (0x01U)

/* SPI CS Polarity Definitions */
#define SPI_CS_HIGH                      (0x01U)
#define SPI_CS_LOW                       (0x00U)

/* SPI CS Selection Definitions */
#define SPI_CS_VIA_GPIO                  (0x00U)
#define SPI_CS_VIA_PERIPHERAL_ENGINE     (0x01U)

/* SPI Data Shift Edge Definitions */
#define SPI_LEADING                      (0x00U)
#define SPI_TRAILING                     (0x01U)

/* SPI Synchronous Mode Definitions */
#define SPI_ASYNCHRONOUS                 (0x00U)
#define SPI_SYNCHRONOUS                  (0x01U)

/* SPI Buffer Type Definitions */
#define SPI_IB                           (0x00U)
#define SPI_EB                           (0x01U)

/* Configuration Counts */
#define SPI_CONFIG_CHANNELS_COUNT        (1U)
#define SPI_CONFIG_JOBS_COUNT            (1U)
#define SPI_CONFIG_SEQUENCES_COUNT       (1U)
#define SPI_CONFIG_EXTERNAL_DEVICES_COUNT (1U)

/* DEM Event Configuration */
#define SPI_DEM_SPI_E_HARDWARE_ERROR_ENABLED      (STD_ON)

#endif /* SPI_CFG_H_ */

