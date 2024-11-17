#include "../../header/include.h"

void file_interpret(const char *file_name) {
<<<<<<< Updated upstream
    FILE * commands;
    commands = fopen(file_name, "r");;
    char size[256];

    if (commands == NULL) {
=======
    FILE * file_reading;
    file_reading = fopen(file_name, "r");;
    char commands[256];

    if (file_reading == NULL) {
>>>>>>> Stashed changes
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

<<<<<<< Updated upstream
    while (fgets(size, sizeof(size), commands) != NULL) {
        size[strcspn(size, "\n")] = '\0';
        if (strlen(size) > 0) {
            shunting_yard(size);
        }
    }
    fclose(commands);
=======
    while (fgets(commands, sizeof(commands), file_reading) != NULL) {
        commands[strcspn(commands, "\n")] = '\0';

        if (strlen(commands) > 0) {
            shunting_yard(commands);
        }
    }
    fclose(file_reading);
>>>>>>> Stashed changes
}