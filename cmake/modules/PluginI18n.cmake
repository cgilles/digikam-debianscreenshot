#
# Copyright (c) 2020 by Gilles Caulier, <caulier dot gilles at gmail dot com>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

# --- Translations rules (i18n)

set(plugin_translation_files
    ${CMAKE_SOURCE_DIR}/i18n/de.ts
    ${CMAKE_SOURCE_DIR}/i18n/es.ts
    ${CMAKE_SOURCE_DIR}/i18n/fr.ts
    ${CMAKE_SOURCE_DIR}/i18n/it.ts
)

set_source_files_properties(${plugin_translation_files} PROPERTIES OUTPUT_LOCATION  ${CMAKE_BINARY_DIR}/i18n)

#qt5_create_translation(
#    dsplgin_i18n_QM
#    ${CMAKE_SOURCE_DIR}/src
#    ${plugin_translation_files}
#)

qt5_add_translation(plugin_i18n_QM
                    ${plugin_translation_files}
)

configure_file(${CMAKE_SOURCE_DIR}/i18n/i18n.qrc ${CMAKE_BINARY_DIR} COPYONLY)
