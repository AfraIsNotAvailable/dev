cmake_minimum_required(VERSION 3.5.0)
project(cmd_args VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(cmd_args  main.c)

add_test(NAME cmd_args_test COMMAND cmd_args "12" "24" "+")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
