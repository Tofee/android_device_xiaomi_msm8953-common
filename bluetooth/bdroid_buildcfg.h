/*
 * Copyright (C) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#include <cutils/properties.h>
#include <string.h>

static inline const char* BtmGetDefaultName()
{
    char product_device[PROPERTY_VALUE_MAX];
    property_get("ro.product.device", product_device, "");

    if (strstr(product_device, "tissot"))
        return "Xiaomi Mi A1";
    if (strstr(product_device, "mido"))
        return "Xiaomi Redmi Note 4";

    // Fallback to ro.product.model
    return "";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()
// Disables read remote device feature
#define BTA_SKIP_BLE_READ_REMOTE_FEAT FALSE
#define MAX_ACL_CONNECTIONS    7
#define MAX_L2CAP_CHANNELS    16
#define BLE_VND_INCLUDED   TRUE
// skips conn update at conn completion
#define BTA_BLE_SKIP_CONN_UPD  FALSE
#define BLE_PERIPHERAL_ADV_NAME  FALSE
#define BT_CLEAN_TURN_ON_DISABLED 1
#define BTM_SCO_ENHANCED_SYNC_ENABLED FALSE

#define BTA_DISABLE_DELAY 1000 /* in milliseconds */
#define BTM_WBS_INCLUDED TRUE
#define BTIF_HF_WBS_PREFERRED TRUE

/* Increasing SEPs to 12 from 6 to support SHO/MCast i.e. two streams per codec */
#define AVDT_NUM_SEPS 12

#undef PROPERTY_VALUE_MAX
#endif
