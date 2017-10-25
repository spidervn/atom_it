cmake_minimum_required(VERSION 2.8)
project( draw_text )
find_package( OpenCV REQUIRED )
add_executable( draw_text draw_text.cpp )
target_link_libraries( draw_text ${OpenCV_LIBS} )

