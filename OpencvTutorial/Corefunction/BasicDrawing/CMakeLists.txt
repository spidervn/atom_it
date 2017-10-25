cmake_minimum_required(VERSION 2.8)
project( basic_draw )
find_package( OpenCV REQUIRED )
add_executable( basic_draw basic_draw.cpp )
target_link_libraries( basic_draw ${OpenCV_LIBS} )

