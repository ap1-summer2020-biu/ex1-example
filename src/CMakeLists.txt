project(Ex1)
cmake_minimum_required(VERSION 3.0.0)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

#compile libmatrix.so
add_library(matrix SHARED Matrix.c ErrorCode.c )

#compile tester
add_executable(tester Test.c)
target_link_libraries(tester matrix)
