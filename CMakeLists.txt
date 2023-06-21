# SPDX-FileCopyrightText: 2023 wzyforgit
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

project(cute-video-toolkits)

set(BIN_NAME cute-video-app)
set(LIB_NAME CuteVideo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(PkgConfig REQUIRED)

option(CuteVideo_BUILD_APP "build cute-video-app" ON)
option(CuteVideo_SHARED_LIB "shared library support" ON)

add_subdirectory(src)
