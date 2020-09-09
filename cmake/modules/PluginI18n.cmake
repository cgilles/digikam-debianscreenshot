#
# Copyright (c) 2020 by Gilles Caulier, <caulier dot gilles at gmail dot com>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

# --- Translations rules (i18n)

include(${CMAKE_SOURCE_DIR}/i18n/i18n_list.cmake)

set_source_files_properties(${plugin_translation_files} PROPERTIES OUTPUT_LOCATION  ${CMAKE_BINARY_DIR}/i18n)

#qt5_create_translation(
#    plgin_i18n_QM
#    ${CMAKE_SOURCE_DIR}/src
#    ${plugin_translation_files}
#)

qt5_add_translation(plugin_i18n_QM
                    ${plugin_translation_files}
)

foreach(file ${plugin_i18n_QM})

    get_filename_component(directory ${file} DIRECTORY)
    get_filename_component(basename  ${file} NAME)

    set(PLUGIN_QM_XML "${PLUGIN_QM_XML}<file>${directory}/${basename}</file>")

endforeach()

configure_file(${CMAKE_SOURCE_DIR}/cmake/templates/i18n.qrc.in_cmake ${CMAKE_BINARY_DIR}/i18n.qrc)

