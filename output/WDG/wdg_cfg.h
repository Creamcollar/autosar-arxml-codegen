#ifndef WDG_CFG_H_
#define WDG_CFG_H_

/*
 * Developer Aruvi B and Auroshaa from CreamCollar
 * Generated WDG Configuration Header
 * Generated from ARXML: wdg_config.arxml
 * Generated on: 2026-05-23 15:45:09
 */

/* Module identification */
#define WDG_VENDOR_ID                    (1810U)
#define WDG_MODULE_ID                    (102U)
#define WDG_INSTANCE_ID                  (0U)

/* Module version information */
#define WDG_SW_MAJOR_VERSION             (1U)
#define WDG_SW_MINOR_VERSION             (0U)
#define WDG_SW_PATCH_VERSION             (0U)

/* WDG General Configuration */
#define WDG_DEV_ERROR_DETECT             STD_ON
#define WDG_DISABLE_ALLOWED              STD_ON
#define WDG_INDEX                        (0U)
#define WDG_INITIAL_TIMEOUT              (100U)
#define WDG_MAX_TIMEOUT                  (1000U)
#define WDG_VERSION_INFO_API             STD_ON

/* WDG Run Area Configuration */
#define WDG_RUN_AREA                     (WDG_ROM)
#define WDG_RAM                          (0x00U)
#define WDG_ROM                          (0x01U)

/* WDG Settings Configuration */
#define WDG_DEFAULT_MODE                 (WDGIF_SLOW_MODE)

#define WDG_TRIGGER_MODE                 (WDG_TOGGLE)

/* WDG Mode Definitions */
#define WDGIF_OFF_MODE                   (0x00U)
#define WDGIF_SLOW_MODE                  (0x01U)
#define WDGIF_FAST_MODE                  (0x02U)

/* WDG Trigger Mode Definitions */
#define WDG_TOGGLE                       (0x00U)
#define WDG_WINDOW                       (0x01U)
#define WDG_BOTH                         (0x02U)

#endif /* WDG_CFG_H_ */

