cmake_minimum_required (VERSION 3.1)

project (aquatracergui)

find_package(Qt5Widgets)

set (CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}" )

# Specify the files which are processed by qt's pre-compiler
QT5_WRAP_CPP( MOC_FILES_CPP
   "mainwindow.h"
   "sensordatamonitor.h"
)

QT5_WRAP_UI(MOC_FILES_UI "mainwindow.ui")

FILE( GLOB_RECURSE SOURCES "*.[c,h]pp" )

SET( SOURCES ${SOURCES} ${MOC_FILES_UI} )
SET( SOURCES ${SOURCES} ${MOC_FILES_CPP} )

add_subdirectory(${PROJECT_SOURCE_DIR}/SensorDataManager)

include_directories( ${PROJECT_SOURCE_DIR}/SensorDataManager)

link_directories(${PROJECT_SOURCE_DIR}/SensorDataManager)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets sensordatamanager)

