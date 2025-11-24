#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open data.txt\n");
        return 1;
    }

    fclose(file);

    
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open data.txt\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        printf("File is empty. Contents successfully deleted.\n");
    } else {
        printf("File is not empty. Size = %ld bytes\n", size);
    }

    fclose(file);
    return 0;
}

