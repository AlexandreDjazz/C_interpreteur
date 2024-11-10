#include "header/include.h"

void file_interpret(const char *file_name) {
    FILE * commands;
    commands = fopen(file_name, "r");;
    char size[256];

    if (commands == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    while (fgets(size, sizeof(size), commands) != NULL) {
        size[strcspn(size, "\n")] = '\0';
        if (strlen(size) > 0) {
            shunting_yard(size);
        }
    }
    fclose(commands);
}