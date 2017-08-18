cmake_minimum_required (VERSION 3.0.2)
project (myProject)

add_compile_options(-std=c++11)

include_directories(include)

add_executable (myProgram src/main.cxx)
target_link_libraries(myProgram PUBLIC)
