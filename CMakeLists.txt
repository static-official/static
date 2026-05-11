cmake_minimum_required(VERSION 3.10)

project(static)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(dobby STATIC IMPORTED)
set_target_properties(dobby PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/libdobby.a)

add_library(static-linux SHARED src/main.cpp)

target_link_libraries(static-linux dobby log android)

set_target_properties(static-linux PROPERTIES OUTPUT_NAME "static-linux")
