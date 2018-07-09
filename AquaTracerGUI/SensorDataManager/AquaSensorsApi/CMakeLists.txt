cmake_minimum_required (VERSION 2.6)

project (aquasensorsapi)

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "*.[c,h]pp")

add_library(${PROJECT_NAME} ${SOURCES})
