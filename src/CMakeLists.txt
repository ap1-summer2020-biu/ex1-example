project(Ex1)
cmake_minimum_required(VERSION 3.0.0)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(matrix SHARED Matrix.c ErrorCode.c )
