#include <stdio.h>
#include <stdlib.h>

int isWhitespace(char ch) {
    return (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r');
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(size + 1);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);

    int characters = 0, words = 0, lines = 0;
    int inWord = 0;
int i=0;
    for (i = 0; i < size; i++) {
        char ch = buffer[i];
        characters++;

        if (ch == '\n')
            lines++;

        if (isWhitespace(ch)) {
            inWord = 0;
        } else {
            if (!inWord) {
                inWord = 1;
                words++;
            }
        }
    }

    printf("Total Characters: %d\n", characters);
    printf("Total Words: %d\n", words);
    printf("Total Lines: %d\n", lines);

    free(buffer);
    return 0;
}

