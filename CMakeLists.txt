cmake_minimum_required(VERSION 3.8.0)
project(bkmaxflow)

add_library(bkmaxflow SHARED bk.cpp)
set_target_properties(bkmaxflow PROPERTIES CXX_STANDARD 14)
target_compile_features(bkmaxflow PUBLIC cxx_std_14)

install(TARGETS bkmaxflow
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

install(FILES bk.h DESTINATION include)
