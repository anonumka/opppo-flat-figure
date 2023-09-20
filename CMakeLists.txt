cmake_minimum_required(VERSION 3.5)

project(opppo-flat-figure LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES
    src/*.h
    src/*.cpp
)

add_executable(opppo-flat-figure ${SOURCES})

install(TARGETS opppo-flat-figure
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
