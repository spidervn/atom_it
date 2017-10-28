cmake_minimum_required(VERSION 2.8)
project( interoperability_opencv1  )
find_package( OpenCV REQUIRED )
add_executable( interoperability_opencv1 interoperability_opencv1.cpp )
target_link_libraries( interoperability_opencv1 ${OpenCV_LIBS} )

