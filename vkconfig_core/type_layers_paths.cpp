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

#include "type_layers_paths.h"

#include <array>

const char* GetLabel(LayersPaths Layers_paths_type) {
    static const char* TABLE[] = {
        "System Implicit Path",           // LAYERS_PATHS_IMPLICIT_SYSTEM
        "${VK_IMPLICIT_LAYER_PATH}",      // LAYERS_PATHS_IMPLICIT_ENV_SET
        "${VK_ADD_IMPLICIT_LAYER_PATH}",  // LAYERS_PATHS_IMPLICIT_ENV_ADD
        "System Explicit Path",           // LAYERS_PATHS_EXPLICIT_SYSTEM
        "${VK_LAYER_PATH}",               // LAYERS_PATHS_EXPLICIT_ENV_SET
        "${VK_ADD_LAYER_PATH}",           // LAYERS_PATHS_EXPLICIT_ENV_ADD
        "Vulkan Configurator",            // LAYERS_PATHS_GUI
        "${VULKAN_SDK}",                  // LAYERS_PATHS_SDK
    };
    static_assert(std::size(TABLE) == LAYERS_PATHS_COUNT, "The tranlation table size doesn't match the enum number of elements");

    return TABLE[Layers_paths_type];
}
