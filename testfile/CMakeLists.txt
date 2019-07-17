
cmake_minimum_required(VERSION 2.8)
project(test)
#find_package(OpenCV REQUIRED)
add_executable(linear_modeling linear_modeling.c)
add_definitions(-std=c11)


#target_link_libraries(opencv ${OpenCV_LIBS})
