cmake_minimum_required(VERSION 3.29)
project(interpreteur C)

set(CMAKE_C_STANDARD 99)

add_executable(interpreteur src/main/main.c
        header/include.h
        header/structures.h
        header/prototypes.h
        src/io/file.c
        src/io/string.c
        src/lexer/lexer.c
        src/lexer/token.c
        src/parser/ast.c
        src/parser/shunting_yard.c
        src/utils/error_handling.c
        src/utils/print.c
)
