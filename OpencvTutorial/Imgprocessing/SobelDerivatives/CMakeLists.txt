


cmake_minimum_required(VERSION 2.8)
project( sobel  )
find_package( OpenCV REQUIRED )
add_executable( sobel sobel.cpp )
target_link_libraries( sobel ${OpenCV_LIBS} )

