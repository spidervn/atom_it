
cmake_minimum_required(VERSION 2.8)
project( opening_closing_hats  )
find_package( OpenCV REQUIRED )
add_executable( opening_closing_hats opening_closing_hats.cpp )
target_link_libraries( opening_closing_hats ${OpenCV_LIBS} )

