
cmake_minimum_required(VERSION 2.8)

project( text_recognition  )
find_package( OpenCV REQUIRED )

include_directories(src/)
file(GLOB SOURCES "src/*.cpp" 
                    "src/app/impl/*.cpp"
                    "src/app/impl/fundamental/opencv/*.cpp" )

add_executable( text_recognition ${SOURCES} )
target_link_libraries( text_recognition ${OpenCV_LIBS} )