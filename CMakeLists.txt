cmake_minimum_required(VERSION 3.10)
project(hyperlib C)

add_library(hyperlib SHARED
        src/algorithm/sort.c
)

target_include_directories(hyperlib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/platform>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/algorithm>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/math>
)

if(MSVC)
    target_compile_options(hyperlib PRIVATE /arch:SSE2)
else()
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86|x86_64|amd64|AMD64")
        target_compile_options(hyperlib PRIVATE -msse4.1)
    endif()
endif()

enable_testing()

file(GLOB TEST_SOURCES "test/*.c")

set(C_STANDARDS 90 99 11 17)
if(NOT MSVC)
    list(APPEND C_STANDARDS 23)
endif()

foreach(SOURCE_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME_BASE ${SOURCE_FILE} NAME_WE)

    foreach(STD ${C_STANDARDS})
        set(TARGET_NAME "test_${TEST_NAME_BASE}_c${STD}")

        add_executable(${TARGET_NAME} ${SOURCE_FILE}
                test/test.c
                src/alias/hypralias.h
                src/platform/compiler.h
                src/platform/cpu.h
                src/platform/os.h
                src/platform/cstdver.h
                src/platform/types.h
                src/platform/hyprplatform.h)

        set_target_properties(${TARGET_NAME} PROPERTIES
                C_STANDARD ${STD}
                C_STANDARD_REQUIRED ON
                C_EXTENSIONS OFF
        )

        if(MSVC)
            target_compile_options(${TARGET_NAME} PRIVATE /arch:SSE2)
        else()
            if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86|x86_64|amd64|AMD64")
                target_compile_options(${TARGET_NAME} PRIVATE -msse4.1)
            endif()
        endif()

        target_link_libraries(${TARGET_NAME} PRIVATE hyperlib)

        add_test(NAME "Check_${TEST_NAME_BASE}_C${STD}" COMMAND ${TARGET_NAME})
    endforeach()
endforeach()