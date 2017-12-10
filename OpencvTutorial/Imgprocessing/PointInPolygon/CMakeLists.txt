
cmake_minimum_required(VERSION 2.8)
project( point_in_polygon  )
find_package( OpenCV REQUIRED )
add_executable( point_in_polygon point_in_polygon.cpp )
target_link_libraries( point_in_polygon ${OpenCV_LIBS} )

