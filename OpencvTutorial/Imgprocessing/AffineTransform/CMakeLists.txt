cmake_minimum_required(VERSION 2.8)
project( affine_transform  )
find_package( OpenCV REQUIRED )
add_executable( affine_transform affine_transform.cpp )
target_link_libraries( affine_transform ${OpenCV_LIBS} )

