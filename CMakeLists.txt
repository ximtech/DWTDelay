cmake_minimum_required(VERSION 3.20)
project(DWT_DELAY VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)

set(DWT_DELAY_DIRECTORY
        ${DWT_DELAY_SOURCE_DIR}
        ${DWT_DELAY_SOURCE_DIR}/include
        CACHE STRING "DWT delay directories include to the main project")

set(DWT_DELAY_SOURCES
        ${DWT_DELAY_SOURCE_DIR}/DWT_Delay.c
        ${DWT_DELAY_SOURCE_DIR}/include/DWT_Delay.h
        CACHE STRING "DWT delay sources include to the main project")