

cmake_minimum_required(VERSION 2.8)
project( psnr_ssim  )
find_package( OpenCV REQUIRED )
add_executable( psnr_ssim psnr_ssim.cpp )
target_link_libraries( psnr_ssim ${OpenCV_LIBS} )

