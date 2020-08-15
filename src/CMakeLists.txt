<<<<<<< HEAD
project(Ex1)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(matrix SHARED Matrix.c ErrorCode.c)
=======
cmake_minimum_required(VERSION 3.0.0)
project(matrix VERSION 0.1.0)

set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(matrix SHARED ErrorCode.c Matrix.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
>>>>>>> aee745b52d52ae6154f8bd82e5c95bb93675b207
