
cmake_minimum_required(VERSION 2.8)
project( pyramid  )
find_package( OpenCV REQUIRED )
add_executable( pyramid pyramid.cpp )
target_link_libraries( pyramid ${OpenCV_LIBS} )

