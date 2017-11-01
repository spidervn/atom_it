
cmake_minimum_required(VERSION 2.8)
project( basic_threshold  )
find_package( OpenCV REQUIRED )
add_executable( basic_threshold basic_threshold.cpp )
target_link_libraries( basic_threshold ${OpenCV_LIBS} )

