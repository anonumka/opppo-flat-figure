cmake_minimum_required(VERSION 3.14)
project(flat_figure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(LibsModule)
link_directories(LibsModule)
include_directories(main_program)
link_directories(main_program)
include_directories(test_program)
link_directories(test_program)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)