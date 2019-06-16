# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

set(BOARD_ROOT ${CMAKE_SOURCE_DIR})

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(Bait)

list(APPEND HEADERS
    "${PROJECT_BINARY_DIR}/include/generated"
    "${PROJECT_BINARY_DIR}/zephyr/include/generated"
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/st"
    "${PROJECT_SOURCE_DIR}/boards/arm/tc_bait_p2/support/bait"
    )

list(APPEND SOURCES
    "${PROJECT_SOURCE_DIR}/src/main.c"
    "${PROJECT_SOURCE_DIR}/src/uart_driver.c"
    "${PROJECT_SOURCE_DIR}/boards/arm/tc_bait_p2/support/bait/Src/usart.c"
    )

include_directories(${HEADERS})
target_sources(app PRIVATE ${SOURCES})
