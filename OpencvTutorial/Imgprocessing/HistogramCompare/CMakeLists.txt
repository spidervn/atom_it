cmake_minimum_required(VERSION 2.8)
project( histogram_compare  )
find_package( OpenCV REQUIRED )
add_executable( histogram_compare histogram_compare.cpp )
target_link_libraries( histogram_compare ${OpenCV_LIBS} )

