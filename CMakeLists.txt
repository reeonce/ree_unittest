cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ree_unittest CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(REE_UNITTEST_SRC
    src/ree/unittest.h
    src/ree/unittest.cc
)
add_library(ree_unittest ${REE_UNITTEST_SRC})
target_include_directories(ree_unittest PRIVATE src/ree)