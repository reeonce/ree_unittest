cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ree_unittest CXX)

set(REE_UNITTEST_SRC
    src/ree/unittest.h
    src/ree/unittest.cc
)
add_library(ree_unittest ${REE_UNITTEST_SRC})
target_include_directories(ree_unittest PUBLIC src)

set_target_properties(ree_unittest PROPERTIES
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
    CMAKE_CXX_EXTENSIONS OFF
)