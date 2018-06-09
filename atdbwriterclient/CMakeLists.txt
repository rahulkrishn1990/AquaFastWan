cmake_minimum_required (VERSION 2.8)

project(atdbwriterclient)

include_directories(/usr/include)

link_directories(/usr/lib)

target_link_libraries(sqlite3)

find_package(Qt5Core CONFIG REQUIRED)

file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

file(GLOB HEADER_FILES 	${PROJECT_SOURCE_DIR}/*.h
						${PROJECT_SOURCE_DIR}/../common/Globel.h)

include_directories(${PROJECT_SOURCE_DIR}/../common)

#add_library(${PROJECT_NAME} SHARED ${CPP_FILES})

add_executable(${PROJECT_NAME} ${CPP_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} 
					  sqlite3
					  Qt5::Core)
					  
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "/usr/bin")

include(cpack.cmake)					  
					  