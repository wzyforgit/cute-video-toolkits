# SPDX-FileCopyrightText: 2023 wzyforgit
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

#for qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(QtModule Core Gui)
find_package(Qt5 REQUIRED ${QtModule})

#for opencv
find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED IMPORTED_TARGET opencv4)

#for sources
include_directories(.)

aux_source_directory(./ allSource)

if(CuteVideo_SHARED_LIB)
    add_library(${LIB_NAME} SHARED ${allSource})
else()
    add_library(${LIB_NAME} STATIC ${allSource})
endif()

target_include_directories(${LIB_NAME} PUBLIC
    Qt5::Core Qt5::Gui
    ${PROJECT_INCLUDE}
)

target_link_libraries(${LIB_NAME} PRIVATE
    Qt5::Core Qt5::Gui
    ${TARGET_LIBS}
    PkgConfig::OPENCV
)
