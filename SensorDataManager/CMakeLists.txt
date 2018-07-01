cmake_minimum_required (VERSION 2.6)

project (sensordatamanager)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core CONFIG REQUIRED)

file(GLOB SOURCES "*.[c,h]pp")

add_subdirectory(${PROJECT_SOURCE_DIR}/AquaSensorsApi)
add_subdirectory(${PROJECT_SOURCE_DIR}/AquaSensors)

#include_directories(${PROJECT_SOURCE_DIR}/AquaSensorsApi
#                                             ${PROJECT_SOURCE_DIR}/AquaSensors)

#link_directories(${PROJECT_SOURCE_DIR}/AquaSensorsApi
#                 §{PROJECT_SOURCE_DIR}/AquaSensors)

add_library(${PROJECT_NAME} SHARED ${SOURCES} )
target_link_libraries(${PROJECT_NAME} Qt5::Core aquasensorsapi aquasensors)
