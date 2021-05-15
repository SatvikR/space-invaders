cmake_minimum_required(VERSION 3.10)
project(space_invaders)

set(TARGET ${PROJECT_NAME} C_STANDARD 99)
add_executable(${PROJECT_NAME} invaders.c)

add_subdirectory("lib/LCGE")

target_include_directories(${PROJECT_NAME} PRIVATE "lib/LCGE/include")
target_link_libraries(${PROJECT_NAME} LCGE "${CMAKE_DL_LIBS}")