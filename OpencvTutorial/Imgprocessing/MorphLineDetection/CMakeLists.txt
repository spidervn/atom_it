

cmake_minimum_required(VERSION 2.8)
project( morph_line_detection  )
find_package( OpenCV REQUIRED )
add_executable( morph_line_detection morph_line_detection.cpp )
target_link_libraries( morph_line_detection ${OpenCV_LIBS} )

