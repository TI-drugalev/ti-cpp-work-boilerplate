cmake_minimum_required(VERSION 3.12)

project(ti-cpp-work-boilerplate VERSION 0.0.0.1 LANGUAGES CXX)

add_subdirectory(libs)
add_subdirectory(src)

# add_subdirectory(tests) TODO: Unit tests

file(COPY ${CMAKE_SOURCE_DIR}/web DESTINATION ${CMAKE_BINARY_DIR})