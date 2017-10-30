cmake_minimum_required(VERSION 2.8)
project( gausian_median  )
find_package( OpenCV REQUIRED )
add_executable( gausian_median gausian_median.cpp )
target_link_libraries( gausian_median ${OpenCV_LIBS} )

