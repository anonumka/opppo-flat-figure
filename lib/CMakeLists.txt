set(libs_files
    geometrys.cpp geometrys.h
    list.cpp  list.h
    mainprocess.cpp mainprocess.h
)

add_library(LibsModule ${libs_files})

target_include_directories(LibsModule PUBLIC include)