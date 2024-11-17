#include "../../header/include.h"

void file_interpret(const char *file_name) {
    FILE * file_reading;
    file_reading = fopen(file_name, "r");;
    char commands[256];

    if (file_reading == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    while (fgets(commands, sizeof(commands), file_reading) != NULL) {
        commands[strcspn(commands, "\n")] = '\0';
        if (strlen(commands) > 0) {
            shunting_yard(commands);
        }
    }
    fclose(file_reading);
}