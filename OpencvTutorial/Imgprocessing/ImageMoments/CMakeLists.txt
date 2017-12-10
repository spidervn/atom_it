
cmake_minimum_required(VERSION 2.8)
project( image_moments  )
find_package( OpenCV REQUIRED )
add_executable( image_moments image_moments.cpp )
target_link_libraries( image_moments ${OpenCV_LIBS} )
