cmake_minimum_required(VERSION 3.10)
project(YOLOv5_Detector)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(include)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Add source files
set(SOURCES
    src/Detector.cpp
    src/main.cpp
    src/Utils.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link OpenCV libraries
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
