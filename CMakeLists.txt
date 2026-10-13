cmake_minimum_required(VERSION 3.28)
project(TungTung C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(TungTung STATIC sahur.c tung.c cappuccina.c)

add_executable(test_tung test_tung.c)

target_link_libraries(test_tung PRIVATE TungTung)

# libs
add_subdirectory(lib/glfw-3.5.1)
target_link_libraries(TungTung PUBLIC glfw opengl32)