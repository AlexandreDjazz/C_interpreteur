#ifndef interpreter_h
#define interpreter_h

#include <stdio.h>
#include <stdlib.h>

// file.c
long get_Size_File(FILE *str);
char *copy_file(char *commands, FILE *file_commands);
char *check_and_copy_file(char *commands, char **av);

#endif
