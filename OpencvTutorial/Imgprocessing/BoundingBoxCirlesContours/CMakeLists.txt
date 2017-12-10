
cmake_minimum_required(VERSION 2.8)
project( bounding_box_circle_contours  )
find_package( OpenCV REQUIRED )
add_executable( bounding_box_circle_contours bounding_box_circle_contours.cpp )
target_link_libraries( bounding_box_circle_contours ${OpenCV_LIBS} )
