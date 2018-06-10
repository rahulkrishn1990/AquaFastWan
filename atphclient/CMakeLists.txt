cmake_minimum_required (VERSION 2.8)

project(atphclient)

include_directories(/usr/include)

link_directories(/usr/lib)

find_package(Qt5Core CONFIG REQUIRED)

file(GLOB CPP_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

file(GLOB HEADER_FILES 	${PROJECT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${CPP_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
					  
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "/usr/bin")

include(cpack.cmake)					  
					  