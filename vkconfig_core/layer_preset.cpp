/*
 * Copyright (c) 2020-2025 Valve Corporation
 * Copyright (c) 2020-2025 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Authors:
 * - Christophe Riccio <christophe@lunarg.com>
 */

#include "layer_preset.h"

#include "util.h"

#include <cstring>

bool HasPreset(const SettingDataSet& layer_settings, const SettingDataSetConst& preset_settings) {
    if (preset_settings.empty()) {
        return false;
    }

    for (std::size_t preset_index = 0, preset_count = preset_settings.size(); preset_index < preset_count; ++preset_index) {
        const SettingData* layer_setting = ::FindSetting(layer_settings, preset_settings[preset_index]->key.c_str());
        if (layer_setting == nullptr) {
            return false;
        }

        if (*preset_settings[preset_index] != *layer_setting) {
            return false;
        }
    }

    return true;
}
