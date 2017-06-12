
cmake_minimum_required(VERSION 2.8)

project(BlendingImage)
find_package(OpenCV REQUIRED)
add_executable(BlendingImage blending_image.cpp)
target_link_libraries(BlendingImage ${OpenCV_LIBS})
