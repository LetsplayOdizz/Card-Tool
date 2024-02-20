cmake_minimum_required(VERSION 3.0)
project(YourProjectName)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Add your source files
add_executable(YourExecutable main.cpp)

# Link against OpenCV libraries
target_link_libraries(YourExecutable ${OpenCV_LIBS})
