cmake_minimum_required(VERSION 2.8)
project( erosion_dilation  )
find_package( OpenCV REQUIRED )
add_executable( erosion_dilation erosion_dilation.cpp )
target_link_libraries( erosion_dilation ${OpenCV_LIBS} )

