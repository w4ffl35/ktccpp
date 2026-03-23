cmake_minimum_required(VERSION 3.23)
project(ktccpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
    ktccpp
    src/main.cpp
    src/Cipher.h
    src/Cipher.cpp
)