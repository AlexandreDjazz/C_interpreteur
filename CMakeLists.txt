cmake_minimum_required(VERSION 3.29)
project(interpreteur C)

set(CMAKE_C_STANDARD 99)

add_executable(interpreteur main.c
<<<<<<< Updated upstream
        file.c)
=======
        file.c
        lexer.c
        header/include.h
        header/structures.h
        header/prototypes.h
        header/ast.h
        string.c
        token.c
        main.c
        error_handling.c
        shunting_yard.c
        ast.c
        string.c
        Print.c

)
>>>>>>> Stashed changes
