
cmake_minimum_required(VERSION 2.8)
project(opencv)
find_package(OpenCV REQUIRED)
add_executable(opencv readimg.cpp)
add_definitions(-std=c++11)


target_link_libraries(opencv ${OpenCV_LIBS})
