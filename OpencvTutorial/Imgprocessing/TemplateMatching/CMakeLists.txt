
cmake_minimum_required(VERSION 2.8)
project( template_matching  )
find_package( OpenCV REQUIRED )
add_executable( template_matching template_matching.cpp )
target_link_libraries( template_matching ${OpenCV_LIBS} )
