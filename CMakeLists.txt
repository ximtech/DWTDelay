cmake_minimum_required(VERSION 3.20)
project(DWT_Delay VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)

set(DWT_DELAY_DIRECTORY
        ${DWT_Delay_SOURCE_DIR}
        ${DWT_Delay_SOURCE_DIR}/include
        CACHE STRING "DWT delay directories include to the main project")

set(DWT_DELAY_SOURCES
        ${DWT_Delay_SOURCE_DIR}/DWT_Delay.c
        ${DWT_Delay_SOURCE_DIR}/include/DWT_Delay.h
        CACHE STRING "DWT delay sources include to the main project")

set(SOURCE_FILES ${PROJECT_NAME}.c include/${PROJECT_NAME}.h)
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PUBLIC
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}.h
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Export
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}Export
        FILE ${PROJECT_NAME}-config.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME})