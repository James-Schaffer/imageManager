cmake_minimum_required(VERSION 4.0)
project(imgManager)

set(CMAKE_CXX_STANDARD 20)

include_directories("C:/cpp_libs/CImg-3.6.3")

add_executable(imgManager main.cpp
        Colors/Color_RGB.cpp
        Colors/Color_RGB.h
        Noise/Perlin.cpp
        Noise/Perlin.h
        Images/ImgLayer.h
)

