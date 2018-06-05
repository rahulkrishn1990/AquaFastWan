cmake_minimum_required (VERSION 2.6)

project (AquaFastWan)

if (BUILD_STAG MATCHES libafwdatabase)
add_subdirectory(libafwdatabase)
endif()
