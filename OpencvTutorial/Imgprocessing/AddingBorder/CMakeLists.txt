

cmake_minimum_required(VERSION 2.8)
project( addborder  )
find_package( OpenCV REQUIRED )
add_executable( addborder addborder.cpp )
target_link_libraries( addborder ${OpenCV_LIBS} )

