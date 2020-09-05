#
# Copyright (c) 2020 by Gilles Caulier, <caulier dot gilles at gmail dot com>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

project(DebianScreenshots)

cmake_minimum_required(VERSION "3.1.0")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(ECM "1.7.0" CONFIG REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules ${ECM_MODULE_PATH})

# Cmake macros
include(CMakePackageConfigHelpers)
include(FeatureSummary)

# ECM macros
include(ECMOptionalAddSubdirectory)
include(ECMMarkNonGuiExecutable)
include(ECMGenerateHeaders)
include(ECMGeneratePriFile)
include(ECMSetupVersion)
include(ECMInstallIcons)
include(ECMAddAppIcon)

# Local macros
include(MacroInstall)

find_package(Qt5 "5.6.0" REQUIRED
             NO_MODULE COMPONENTS
             Core
             Widgets
)

find_package(Threads)

find_package(DigikamCore
             CONFIG REQUIRED)

set_package_properties(DigikamCore PROPERTIES
                       URL "http://www.digikam.org"
                       DESCRIPTION "digiKam core library"
)

find_package(KF5 "5.5.0" REQUIRED
             COMPONENTS
             Config
             KIO
)

include_directories($<TARGET_PROPERTY:Qt5::Widgets,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:Qt5::Core,INTERFACE_INCLUDE_DIRECTORIES>

                    $<TARGET_PROPERTY:KF5::ConfigCore,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:KF5::KIOCore,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:KF5::KIOWidgets,INTERFACE_INCLUDE_DIRECTORIES>

                    $<TARGET_PROPERTY:Digikam::digikamcore,INTERFACE_INCLUDE_DIRECTORIES>/digikam

                    ${CMAKE_CURRENT_SOURCE_DIR}
)

qt5_add_resources(debianscreenshotsplugin_QRC_SRCS dsplugin.qrc)

set(debianscreenshotsplugin_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/dsmpform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dspackagedelegate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dstalker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dswindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dsplugin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dswidget.cpp
    ${debianscreenshotsplugin_QRC_SRCS}
)

add_library(Generic_DebianScreenshots_Plugin
            MODULE ${debianscreenshotsplugin_SRCS}
)

set_target_properties(Generic_DebianScreenshots_Plugin PROPERTIES PREFIX "")

target_link_libraries(Generic_DebianScreenshots_Plugin

                      Digikam::digikamcore

                      Qt5::Core
                      Qt5::Widgets

                      KF5::KIOCore
                      KF5::KIOWidgets
)

MACRO_ADD_PLUGIN_INSTALL_TARGET(Generic_DebianScreenshots_Plugin generic)

add_subdirectory(icons)

# ---

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
