#include <stdio.h>
#include <string.h>

struct Flight {
    char flightNumber[10];
    char departure[30];
    char destination[30];
    char date[15];
    int availableSeats;
};

void displayFlight(struct Flight f) {
    printf("\n----- Flight Details -----\n");
    printf("Flight Number   : %s\n", f.flightNumber);
    printf("Departure City  : %s\n", f.departure);
    printf("Destination City: %s\n", f.destination);
    printf("Date            : %s\n", f.date);
    printf("Available Seats : %d\n", f.availableSeats);
    printf("---------------------------\n");
}

void bookSeat(struct Flight *f) {
    if (f->availableSeats > 0) {
        f->availableSeats--;
        printf("\nSeat booked successfully! Remaining seats: %d\n", f->availableSeats);
    } else {
        printf("\nBooking failed! No seats available.\n");
    }
}

int main() {
    struct Flight flight1;

    strcpy(flight1.flightNumber, "AI202");
    strcpy(flight1.departure, "New York");
    strcpy(flight1.destination, "London");
    strcpy(flight1.date, "20-12-2025");
    flight1.availableSeats = 5;

    int choice;

    do {
        printf("\n===== Flight Management System =====\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlight(flight1);
                break;
            case 2:
                bookSeat(&flight1);
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}

