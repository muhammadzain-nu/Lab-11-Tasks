#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2, *merged;
    char ch;

    // Open first file for reading
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Error: Cannot open file1.txt\n");
        return 1;
    }

    // Open second file for reading
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Error: Cannot open file2.txt\n");
        fclose(file1);
        return 1;
    }

    // Open merged file for writing
    merged = fopen("merged.txt", "w");
    if (merged == NULL) {
        printf("Error: Cannot create merged.txt\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    // Copy contents of first file
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, merged);
    }

    // Optionally, add a newline between files
    fputc('\n', merged);

    // Copy contents of second file
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, merged);
    }

    printf("Files merged successfully into merged.txt\n");

    fclose(file1);
    fclose(file2);
    fclose(merged);

    return 0;
}

