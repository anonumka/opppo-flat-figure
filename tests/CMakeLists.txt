include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(test_program main_test.cpp)

target_link_libraries(test_program
  GTest::GTest
  LibsModule
)

add_test(GeneralWork test_program)
add_test(AddTests test_program)
add_test(DelTests test_program)
add_test(ListTests test_program)