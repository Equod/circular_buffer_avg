cmake_minimum_required(VERSION 3.13)
project(circular_buffer_avg)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(test)
