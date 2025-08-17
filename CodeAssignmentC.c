#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void goodbye() {
    printf("\n**************************\n");
    printf("Environment Variable Display Program by Dorlens Janvier\n");
}

int main(int argc, char *argv[]) {
    atexit(goodbye);

    if (argc > 2) {
        printf("Usage: a.exe [environment_variable_name | -a]\n");
        return 0;
    }

    if (argc == 1) {
        printf("Theres no environment variable given.\n");
        return 0;
    }

    if (strcmp(argv[1], "-a") == 0) {
        for (char **env = environ; *env != NULL; env++) {
            printf("%s\n", *env);
        }
        return 0;
    }

    char *value = getenv(argv[1]);
    if (value != NULL) {
        printf("%s=%s\n", argv[1], value);
    } else {
        printf("Environment variable '%s' not found.\n", argv[1]);
    }
    return 0;
}