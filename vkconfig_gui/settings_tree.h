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

#include "widget_setting_flags.h"
#include "widget_setting_filesystem.h"
#include "widget_layer_version.h"
#include "ui_mainwindow.h"

#include "../vkconfig_core/configuration.h"

#include <QObject>
#include <QComboBox>
#include <QTreeWidget>

#include <vector>
#include <memory>

class SettingsTreeManager : public QObject {
    Q_OBJECT

   public:
    SettingsTreeManager(std::shared_ptr<Ui::MainWindow> ui);

    void CreateGUI();
    void CleanupGUI();

    void RefreshPresetLabel();
    // void RefreshVersion();
    void Refresh(RefreshAreas refresh_areas);

   public Q_SLOTS:
    void OnLayerVersionChanged(int layer_version_index);
    void OnSettingChanged();
    void OnPresetChanged(int combox_preset_index);

    void on_item_collapsed(QTreeWidgetItem *item);
    void on_item_expanded(QTreeWidgetItem *item);

   Q_SIGNALS:
    void signalLayerVersionChanged();

   private:
    SettingsTreeManager(const SettingsTreeManager &) = delete;
    SettingsTreeManager &operator=(const SettingsTreeManager &) = delete;

    void SetSettingExpanded(const std::string &key, const std::string &flag, bool expanded);

    void BuildTree();
    void BuildTreeItem(QTreeWidgetItem *parent, const SettingMeta &meta);

    void RefreshItem(RefreshAreas refresh_areas, QTreeWidgetItem *parent);

    std::shared_ptr<Ui::MainWindow> ui;
    // LayerVersionComboBox *layer_version = nullptr;
    std::vector<Path> layer_version_path;
};
