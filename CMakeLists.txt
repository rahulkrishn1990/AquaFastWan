cmake_minimum_required (VERSION 3.1)

project(AquaTracerApp)

set(PARENT_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core CONFIG REQUIRED)

if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    message("less than 3.1")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 11)
  message("equal to 3.1")
endif ()

file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/SensorDataManager)

include_directories( ${PROJECT_SOURCE_DIR}/SensorDataManager)

link_directories(${PROJECT_SOURCE_DIR}/SensorDataManager)

add_executable(${PROJECT_NAME} ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core sensordatamanager)
