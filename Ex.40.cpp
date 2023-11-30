#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    if (access(filename, R_OK) == 0) {
        printf("%s is readable\n", filename);
    } else {
        printf("%s is not readable\n", filename);
    }

    if (access(filename, W_OK) == 0) {
        printf("%s is writable\n", filename);
    } else {
        printf("%s is not writable\n", filename);
    }

    if (access(filename, X_OK) == 0) {
        printf("%s is executable\n", filename);
    } else {
        printf("%s is not executable\n", filename);
    }

    return 0;
}

