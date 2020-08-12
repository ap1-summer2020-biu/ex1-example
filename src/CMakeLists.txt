project(Ex1)
set(C_STANDARD C99)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_library(ErrorCode SHARED ErrorCode.c)
add_library(Matrix SHARED Matrix.c )
add_executable(Main main.c)
target_link_libraries(Main Matrix ErrorCode)
