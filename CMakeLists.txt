set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.20)

project(MinCPU LANGUAGES C)

file(GLOB_RECURSE mincpu_src "src/*.c")

add_executable(mincpu ${mincpu_src})

find_package(raylib REQUIRED)

target_link_libraries(mincpu PRIVATE raylib)
target_include_directories(mincpu PRIVATE "include/")
target_compile_features(mincpu PRIVATE c_std_99)
target_compile_options(mincpu PRIVATE -Wall -Wextra -Wpedantic -O2)
