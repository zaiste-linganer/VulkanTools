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
 * - Richard S. Wright Jr. <richard@lunarg.com>
 * - Christophe Riccio <christophe@lunarg.com>
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

extern const char *VKCONFIG_NAME;
extern const char *VKCONFIG_SHORT_NAME;

class Version {
    enum type { WITH_MAJOR = 0, WITH_MINOR, WITH_PATCH, WITH_REVISION };

   public:
    static const Version VKCONFIG;
    static const Version VKHEADER;
    static const Version NONE;
    static const Version LATEST;
    static const Version REQUIRED_LOADER_VERSION;

    explicit Version() : _major(0), _minor(0), _patch(0), _revision(0) {}
    explicit Version(uint32_t version_complete);
    explicit Version(uint32_t version_major, uint32_t version_minor);
    explicit Version(uint32_t version_major, uint32_t version_minor, uint32_t version_patch);
    explicit Version(uint32_t version_major, uint32_t version_minor, uint32_t version_patch, uint32_t version_revision);
    explicit Version(const char *version);
    explicit Version(const std::string &version);

    std::string str() const;

    bool operator!=(const Version &other_version) const;
    bool operator==(const Version &other_version) const;
    bool operator<(const Version &other_version) const;
    bool operator>=(const Version &other_version) const;
    bool operator>(const Version &other_version) const;
    bool operator<=(const Version &other_version) const;

    uint32_t GetMajor() const { return _major; };
    uint32_t GetMinor() const { return _minor; };
    uint32_t GetPatch() const { return _patch; };
    uint32_t GetRevision() const { return _revision; };

   private:
    uint32_t _major = 0;
    uint32_t _minor = 0;
    uint32_t _patch = 0;
    uint32_t _revision = 0;
    type type = WITH_PATCH;
};

#define VKC_ASSERT_VERSION(expression, required_version, current_version) \
    (assert(((expression) && (current_version >= required_version)) || (current_version < required_version)))
