# SPDX-FileCopyrightText: 2023 wzyforgit
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

#for qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QtModule Core Gui Widgets)
find_package(Qt5 REQUIRED ${QtModule})

#for sources
include_directories(.)
include_directories(../)

aux_source_directory(./ allSource)
aux_source_directory(./widget allSource)

add_executable(${BIN_NAME} ${allSource})

#for links
target_include_directories(${BIN_NAME} PUBLIC
    Qt5::Core Qt5::Gui Qt5::Widgets
    ${PROJECT_INCLUDE}
)

target_link_libraries(${BIN_NAME} PRIVATE
    Qt5::Core Qt5::Gui Qt5::Widgets ${LIB_NAME}
    ${TARGET_LIBS}
)
