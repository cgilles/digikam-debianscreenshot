#
# Copyright (c) 2020 by Gilles Caulier, <caulier dot gilles at gmail dot com>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

project(DebianScreenshots)

cmake_minimum_required(VERSION "3.1.0")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

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

# --- Dependencies

find_package(Qt5 "5.6.0" REQUIRED
             NO_MODULE COMPONENTS
             Core
             Widgets
             Xml
             LinguistTools              # for i18n
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
             KIO
)

# ---

include_directories($<TARGET_PROPERTY:Qt5::Widgets,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:Qt5::Core,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:Qt5::Xml,INTERFACE_INCLUDE_DIRECTORIES>

                    $<TARGET_PROPERTY:KF5::ConfigCore,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:KF5::KIOCore,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:KF5::KIOWidgets,INTERFACE_INCLUDE_DIRECTORIES>

                    $<TARGET_PROPERTY:Digikam::digikamcore,INTERFACE_INCLUDE_DIRECTORIES>/digikam

                    ${CMAKE_SOURCE_DIR}/src
)

# --- Translations rules (i18n)

set(dsplugin_translation_files
    ${CMAKE_SOURCE_DIR}/i18n/de.ts
    ${CMAKE_SOURCE_DIR}/i18n/es.ts
    ${CMAKE_SOURCE_DIR}/i18n/fr.ts
    ${CMAKE_SOURCE_DIR}/i18n/it.ts
)

set_source_files_properties(${dsplugin_translation_files} PROPERTIES OUTPUT_LOCATION i18n)

#qt5_create_translation(
#    dsplgin_QM
#    ${CMAKE_SOURCE_DIR}/src
#    ${dsplugin_translation_files}
#)

qt5_add_translation(dsplugin_QM
                    ${dsplugin_translation_files}
)

configure_file(${CMAKE_SOURCE_DIR}/i18n/i18n.qrc ${CMAKE_BINARY_DIR} COPYONLY)

# ---

qt5_add_resources(dsplugin_QRC_SRCS
                  ${CMAKE_SOURCE_DIR}/res/dsplugin.qrc
                  ${CMAKE_BINARY_DIR}/i18n.qrc
)

set(dsplugin_SRCS
    ${CMAKE_SOURCE_DIR}/src/dsmpform.cpp
    ${CMAKE_SOURCE_DIR}/src/dspackagedelegate.cpp
    ${CMAKE_SOURCE_DIR}/src/dstalker.cpp
    ${CMAKE_SOURCE_DIR}/src/dswindow.cpp
    ${CMAKE_SOURCE_DIR}/src/dsplugin.cpp
    ${CMAKE_SOURCE_DIR}/src/dswidget.cpp
    ${dsplugin_QRC_SRCS}
    ${dsplugin_QM}
)

add_library(Generic_DebianScreenshots_Plugin
            MODULE ${dsplugin_SRCS}
)

set_target_properties(Generic_DebianScreenshots_Plugin PROPERTIES PREFIX "")

target_link_libraries(Generic_DebianScreenshots_Plugin

                      Digikam::digikamcore

                      Qt5::Core
                      Qt5::Widgets
                      Qt5::Xml

                      KF5::KIOCore
                      KF5::KIOWidgets
)

MACRO_ADD_PLUGIN_INSTALL_TARGET(Generic_DebianScreenshots_Plugin generic)

# ---

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
