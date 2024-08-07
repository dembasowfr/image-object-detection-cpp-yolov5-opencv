cmake_minimum_required(VERSION 3.10)
project(YOLOv5_Detector)

set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories
include_directories(include ${OpenCV_INCLUDE_DIRS})

# Find all source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(YOLOv5_Detector ${SOURCES})

# Link OpenCV libraries
target_link_libraries(YOLOv5_Detector ${OpenCV_LIBS})
