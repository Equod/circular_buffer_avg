project(test_circular_buffer_avg)

add_executable(${PROJECT_NAME} test_circular_buffer_avg.cpp)
target_link_libraries(${PROJECT_NAME} circular_buffer_avg)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
