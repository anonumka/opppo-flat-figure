cmake_minimum_required(VERSION 3.5)

project(opppo-flat-figure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(opppo-flat-figure main.cpp geometrys.h geometrys.cpp list.h list.cpp)

install(TARGETS opppo-flat-figure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
