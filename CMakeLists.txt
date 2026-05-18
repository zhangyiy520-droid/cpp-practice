cmake_minimum_required(VERSION 3.16)
project(OpenCVIntro LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
add_executable(show_image main.cpp)
target_link_libraries(show_image ${OpenCV_LIBS})
