cmake_minimum_required (VERSION 2.6)

project (aquasensors)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core CONFIG REQUIRED)

file(GLOB SOURCES "*.[c,h]pp")

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core)
