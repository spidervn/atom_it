
cmake_minimum_required(VERSION 2.8)
project( hough_circle  )
find_package( OpenCV REQUIRED )
add_executable( hough_circle hough_circle.cpp )
target_link_libraries( hough_circle ${OpenCV_LIBS} )

