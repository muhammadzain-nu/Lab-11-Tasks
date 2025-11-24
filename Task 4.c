#include <stdio.h>
#include <string.h>

#define MAX 100

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie movies[], int *count) {
    if (*count >= MAX) {
        printf("\nMovie list is full! Cannot add more.\n");
        return;
    }

    printf("\nEnter Movie Title: ");
    getchar(); 
    fgets(movies[*count].title, 50, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0';

    printf("Enter Genre: ");
    fgets(movies[*count].genre, 30, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0';

    printf("Enter Director: ");
    fgets(movies[*count].director, 50, stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0';

    printf("Enter Release Year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter Rating (0–10): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("\nMovie added successfully!\n");
}

void searchByGenre(struct Movie movies[], int count) {
    char searchGenre[30];
    int found = 0;

    printf("\nEnter genre to search: ");
    getchar();  
    fgets(searchGenre, 30, stdin);
    searchGenre[strcspn(searchGenre, "\n")] = '\0';

    printf("\n--- Movies Matching Genre: %s ---\n", searchGenre);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, searchGenre) == 0) {
            printf("\nTitle       : %s\n", movies[i].title);
            printf("Genre       : %s\n", movies[i].genre);
            printf("Director    : %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating      : %.1f/10\n", movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo movies found in this genre.\n");
    }
}

void displayAll(struct Movie movies[], int count) {
    if (count == 0) {
        printf("\nNo movies available to display.\n");
        return;
    }

    printf("\n========= All Movies =========\n");
    for (int i = 0; i < count; i++) {
        printf("\nMovie %d:\n", i + 1);
        printf("Title       : %s\n", movies[i].title);
        printf("Genre       : %s\n", movies[i].genre);
        printf("Director    : %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating      : %.1f/10\n", movies[i].rating);
    }
}

int main() {
    struct Movie movies[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== Movie Management System =====\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                searchByGenre(movies, count);
                break;
            case 3:
                displayAll(movies, count);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

