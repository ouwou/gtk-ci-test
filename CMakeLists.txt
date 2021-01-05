cmake_minimum_required (VERSION 3.8)

project ("gtk-ci-test")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(gtkmm REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_libraries(${GTKMM_LIBRARIES})

add_executable(gtk-ci-test main.cpp)
