cmake_minimum_required (VERSION 3.0)

if(BUILD_STAGE MATCHES atdbwriterclient)
add_subdirectory(atdbwriterclient)
elseif(BUILD_STAGE MATCHES atdbwritertimerd)
add_subdirectory(atdbwritertimerd)
elseif(BUILD_STAGE MATCHES atphclient)
add_subdirectory(atphclient)
endif()