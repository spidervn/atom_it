cmake_minimum_required(VERSION 2.8)
project( distance_transform  )
find_package( OpenCV REQUIRED )
add_executable( distance_transform distance_transform.cpp )
target_link_libraries( distance_transform ${OpenCV_LIBS} )

