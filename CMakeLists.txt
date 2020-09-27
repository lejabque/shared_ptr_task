cmake_minimum_required(VERSION 3.15)

project(shared_ptr_testing)
include_directories(.)
add_subdirectory(gtest)

add_executable(shared_ptr_testing
        main.cpp
        shared_ptr.h
        test_object.cpp
        test_object.h
        control_block.cpp
        control_block.h)

set_property(TARGET shared_ptr_testing PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=undefined,address,leak -fno-sanitize-recover=all -D_GLIBCXX_DEBUG")
target_link_libraries(shared_ptr_testing gtest)
