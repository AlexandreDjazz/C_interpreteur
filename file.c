#include "header/include.h"

void fileInterpret(const char *nameFile) {
    FILE * commands;
    commands = fopen(nameFile, "r");;
    char taille[256];

    if (commands == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    while (fgets(taille, sizeof(taille), commands) != NULL) {
        shunting_yard(taille);
    }
    fclose(commands);
}