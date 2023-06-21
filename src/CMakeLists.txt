# SPDX-FileCopyrightText: 2023 wzyforgit
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

add_subdirectory(cutevideo)

if(CuteVideo_BUILD_APP)
    add_subdirectory(app)
endif()
