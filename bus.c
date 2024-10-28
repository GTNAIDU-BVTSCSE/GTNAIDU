#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 10

typedef struct {
    char name[50];
    int seatNumber;
} Reservation;

Reservation reservations[MAX_SEATS];
int reservationCount = 0;

void displaySeats() {
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (reservations[i].seatNumber == 0) {
            printf("Seat %d: Available\n", i + 1);
        } else {
            printf("Seat %d: Booked by %s\n", i + 1, reservations[i].name);
        }
    }
}

void bookSeat() {
    if (reservationCount >= MAX_SEATS) {
        printf("All seats are booked!\n");
        return;
    }

    int seatNumber;
    char name[50];
   
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);
   
    if (seatNumber < 1 || seatNumber > MAX_SEATS || reservations[seatNumber - 1].seatNumber != 0) {
        printf("Invalid seat number or seat already booked!\n");
    } else {
        reservations[seatNumber - 1].seatNumber = seatNumber;
        strcpy(reservations[seatNumber - 1].name, name);
        reservationCount++;
        printf("Seat %d booked successfully for %s!\n", seatNumber, name);
    }
}

void cancelReservation() {
    int seatNumber;

    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);
   
    if (seatNumber < 1 || seatNumber > MAX_SEATS || reservations[seatNumber - 1].seatNumber == 0) {
        printf("Invalid seat number or no booking found!\n");
    } else {
        printf("Booking for %s in seat %d has been canceled.\n", reservations[seatNumber - 1].name, seatNumber);
        reservations[seatNumber - 1].seatNumber = 0; // Cancel the booking
        strcpy(reservations[seatNumber - 1].name, ""); // Clear name
        reservationCount--;
    }
}

int main() {
    int choice;
   
    while (1) {
        printf("\nBus Reservation System\n");
        printf("1. Display Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
   
    return 0;
}
