cmake_minimum_required(VERSION 3.10)
project(space_invaders)

set(TARGET ${PROJECT_NAME} CXX_STANDARD 17)
set(SOURCES
    "main.cpp"
    "Game.cpp"
    "Game.h"
    "Screen.cpp"
    "Screen.h"
    "MainMenu.cpp"
    "MainMenu.h"
    "Util.h"
    "Util.cpp"
)
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory("lib/LCGE")

target_include_directories(${PROJECT_NAME} PRIVATE "lib/LCGE/include")
target_link_libraries(${PROJECT_NAME} LCGE "${CMAKE_DL_LIBS}")

if (WIN32)
    if (MSVC)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory(../dist)
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ../dist/${PROJECT_NAME}.exe
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LCGE> ../dist/LCGE.dll
            COMMAND ${CMAKE_COMMAND} -E copy_directory ../assets ../dist/assets
            COMMAND ${CMAKE_COMMAND} -E copy_directory ../lib/LCGE/res ../dist/assets/LCGE
            COMMENT "Created ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.exe"
        )
    else()
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.exe
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LCGE> ${PROJECT_BINARY_DIR}/libLCGE.dll
            COMMAND ${CMAKE_COMMAND} -E copy_directory ../assets ${PROJECT_BINARY_DIR}/assets
            COMMENT "Created ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.exe"
        )
    endif()
endif()