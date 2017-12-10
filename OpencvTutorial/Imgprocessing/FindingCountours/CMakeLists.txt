
cmake_minimum_required(VERSION 2.8)
project( finding_contours  )
find_package( OpenCV REQUIRED )
add_executable( finding_contours finding_contours.cpp )
target_link_libraries( finding_contours ${OpenCV_LIBS} )

