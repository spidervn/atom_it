cmake_minimum_required(VERSION 2.8)
project( MaskOp )
find_package( OpenCV REQUIRED )
add_executable( mask_op mask_op.cpp )
target_link_libraries( mask_op ${OpenCV_LIBS} )

