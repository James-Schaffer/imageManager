cmake_minimum_required(VERSION 4.0)
project(imgManager)

set(CMAKE_CXX_STANDARD 20)

include_directories("C:/cpp_libs/CImg-3.6.3")

add_executable(imgManager main.cpp
        Colors/Spaces/RGB/sRGB.cpp
        Colors/Spaces/Lab/LAB_Base.h
        Colors/Spaces/Lab/okLab.cpp
        Colors/Spaces/Lab/okLab.h
        Colors/Spaces/Other/XYZ.cpp
        Colors/Spaces/Other/XYZ.h
        Colors/Spaces/Other/LMS.cpp
        Colors/Spaces/Other/LMS.h
)

