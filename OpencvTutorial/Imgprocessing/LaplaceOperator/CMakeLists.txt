cmake_minimum_required(VERSION 2.8)
project( laplace_operator  )
find_package( OpenCV REQUIRED )
add_executable( laplace_operator laplace_operator.cpp )
target_link_libraries( laplace_operator ${OpenCV_LIBS} )

