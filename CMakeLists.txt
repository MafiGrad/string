cmake_minimum_required(VERSION 3.5)

project(String)
add_executable(string main.cpp string.cpp)
set_target_properties(string PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)