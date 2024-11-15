NAME            =    c_interpreter

DIR_IO          =    src/io/
DIR_LEXER       =    src/lexer/
DIR_MAIN        =    src/main/
DIR_PARSER      =    src/parser/
DIR_UTILS       =    src/utils/
DIR_OBJ         =    obj/

SRC				=	$(DIR_MAIN)main.c \
					$(DIR_IO)file.c \
					$(DIR_IO)string.c \
					$(DIR_LEXER)lexer.c \
					$(DIR_LEXER)token.c \
					$(DIR_PARSER)ast.c \
					$(DIR_PARSER)shunting_yard.c \
					$(DIR_UTILS)error_handling.c \
					$(DIR_UTILS)print.c

OBJ				=	$(SRC:%.c=$(DIR_OBJ)%.o)

CC				=	gcc
CFLAGS			=	-g3 -Wall -Werror -Wextra -IC:/MinGW/include

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(DIR_OBJ)%.o:	%.c
				@if not exist "$(dir $@)" mkdir "$(dir $@)"
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				@echo "Removing .o files ..."
				@for /R $(DIR_OBJ) %%f in (*.o) do del "%%f"
				@if exist c_interpreter.exe del c_interpreter.exe

fclean:
				@echo "Removing obj directory ..."
				@if exist "$(DIR_OBJ)" rmdir /S /Q "$(DIR_OBJ)"
				@if exist c_interpreter.exe del c_interpreter.exe