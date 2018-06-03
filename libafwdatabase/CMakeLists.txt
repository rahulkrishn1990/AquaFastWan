cmake_minimum_required (VERSION 2.8)

project(libafwdatabase)

include_directories(/usr/include)

link_directories(/usr/lib)

target_link_libraries(sqlite3)

file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/src/*.h)

add_library(${PROJECT_NAME} SHARED ${CPP_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_FILES})