cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ztest_regex_issue)

SET(CMAKE_C_FLAGS "-O0")
SET(CMAKE_CPP_FLAGS "-O0")
set(CMAKE_BUILD_TYPE Debug)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
