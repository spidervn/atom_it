

cmake_minimum_required(VERSION 2.8)
project( gdal_image  )
find_package( OpenCV REQUIRED )
add_executable( gdal_image gdal_image.cpp )
target_link_libraries( gdal_image ${OpenCV_LIBS} )

