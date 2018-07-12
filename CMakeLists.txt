cmake_minimum_required(VERSION 3.0.0)
project(bkmaxflow)

add_library(bkmaxflow SHARED bk.cpp graph.cpp maxflow.cpp)
target_compile_options(bkmaxflow PRIVATE -std=c++14)
