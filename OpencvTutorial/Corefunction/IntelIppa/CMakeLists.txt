
cmake_minimum_required(VERSION 2.8)
project( intel_ippa  )
find_package( OpenCV REQUIRED )
add_executable( intel_ippa intel_ippa.cpp )
target_link_libraries( intel_ippa ${OpenCV_LIBS} )

