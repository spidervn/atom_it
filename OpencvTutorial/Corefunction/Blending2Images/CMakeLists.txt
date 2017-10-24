cmake_minimum_required(VERSION 2.8)
project( AddingImages )
find_package( OpenCV REQUIRED )
add_executable( addingImages addingImages.cpp )
target_link_libraries( addingImages ${OpenCV_LIBS} )

