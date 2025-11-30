#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 20

int main() {
    char words[ROWS][COLS] = {
        "apple",
        "banana",
        "orange",
        "mango",
        "grape"
    };

    char input[20];
    int found = 0;

    printf("Enter a word to search: ");
    scanf("%s", input);
int i=0;
    for (i = 0; i < ROWS; i++) {
        if (strcmp(input, words[i]) == 0) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}

