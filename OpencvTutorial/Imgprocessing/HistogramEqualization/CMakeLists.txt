cmake_minimum_required(VERSION 2.8)
project( histogram_eq  )
find_package( OpenCV REQUIRED )
add_executable( histogram_eq histogram_eq.cpp )
target_link_libraries( histogram_eq ${OpenCV_LIBS} )

