cmake_minimum_required(VERSION 3.10)
project(YOLOv5_Detector)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp")

add_executable(YOLOv5_Detector ${SOURCES})

target_link_libraries(YOLOv5_Detector ${OpenCV_LIBS})