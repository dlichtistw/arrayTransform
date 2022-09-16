cmake_minimum_required(VERSION 3.0.0)
project(array_transform VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(array_test array_test.cpp)
add_test(NAME array_test COMMAND array_test)

add_executable(tuple_test tuple_test.cpp)
add_test(NAME tuple_test COMMAND tuple_test)

add_executable(pair_test pair_test.cpp)
add_test(NAME pair_test COMMAND pair_test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
