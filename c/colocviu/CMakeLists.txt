cmake_minimum_required(VERSION 3.5.0)
project(colocviu VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_executable(colocviu main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
