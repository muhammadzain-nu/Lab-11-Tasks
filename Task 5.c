#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 20

struct Player {
    char name[30];
    int age;
    char position[20];
};

struct Team {
    char name[30];
    char sport[20];
    struct Player players[MAX_PLAYERS];
    int playerCount;
};

void addPlayer(struct Team *team, char name[], int age, char position[]) {
    if (team->playerCount >= MAX_PLAYERS) {
        printf("Team is full. Cannot add more players.\n");
        return;
    }
    strcpy(team->players[team->playerCount].name, name);
    team->players[team->playerCount].age = age;
    strcpy(team->players[team->playerCount].position, position);
    team->playerCount++;
}

void searchByPosition(struct Team team, char position[]) {
    int found = 0;
    printf("\nPlayers in position '%s':\n", position);
    for (int i = 0; i < team.playerCount; i++) {
        if (strcmp(team.players[i].position, position) == 0) {
            printf("Name: %s, Age: %d\n", team.players[i].name, team.players[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("No players found in this position.\n");
    }
}

void displayTeam(struct Team team) {
    printf("\n=== Team Details ===\n");
    printf("Team Name: %s\n", team.name);
    printf("Sport: %s\n", team.sport);
    printf("Players:\n");
    for (int i = 0; i < team.playerCount; i++) {
        printf("%d. Name: %s, Age: %d, Position: %s\n",
               i + 1,
               team.players[i].name,
               team.players[i].age,
               team.players[i].position);
    }
}

int main() {
    struct Team myTeam;
    myTeam.playerCount = 0;

    printf("Enter team name: ");
    fgets(myTeam.name, sizeof(myTeam.name), stdin);
    myTeam.name[strcspn(myTeam.name, "\n")] = 0; 

    printf("Enter sport: ");
    fgets(myTeam.sport, sizeof(myTeam.sport), stdin);
    myTeam.sport[strcspn(myTeam.sport, "\n")] = 0;

    int n;
    printf("How many players to add? ");
    scanf("%d", &n);
    getchar(); 
    for (int i = 0; i < n; i++) {
        char name[30], position[20];
        int age;
        printf("\nEnter details for player %d:\n", i + 1);

        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Age: ");
        scanf("%d", &age);
        getchar();

        printf("Position: ");
        fgets(position, sizeof(position), stdin);
        position[strcspn(position, "\n")] = 0;

        addPlayer(&myTeam, name, age, position);
    }

    displayTeam(myTeam);

    char searchPos[20];
    printf("\nEnter position to search: ");
    fgets(searchPos, sizeof(searchPos), stdin);
    searchPos[strcspn(searchPos, "\n")] = 0;

    searchByPosition(myTeam, searchPos);

    return 0;
}

