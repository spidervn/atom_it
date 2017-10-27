cmake_minimum_required(VERSION 2.8)
project( discrete_fourier )
find_package( OpenCV REQUIRED )
add_executable( discrete_fourier discrete_fourier.cpp )
target_link_libraries( discrete_fourier ${OpenCV_LIBS} )

