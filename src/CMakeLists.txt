project(Ex1)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(errorCode SHARED ErrorCode.c)
add_library(matrix SHARED Matrix.c )
add_executable(main main.c)
target_link_libraries(main matrix errorCode)
