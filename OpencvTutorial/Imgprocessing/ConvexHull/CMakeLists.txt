
cmake_minimum_required(VERSION 2.8)
project( convex_hull  )
find_package( OpenCV REQUIRED )
add_executable( convex_hull convex_hull.cpp )
target_link_libraries( convex_hull ${OpenCV_LIBS} )
