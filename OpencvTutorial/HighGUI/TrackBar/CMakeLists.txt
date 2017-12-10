

cmake_minimum_required(VERSION 2.8)
project( adding_trackbar  )
find_package( OpenCV REQUIRED )
add_executable( adding_trackbar adding_trackbar.cpp )
target_link_libraries( adding_trackbar ${OpenCV_LIBS} )

