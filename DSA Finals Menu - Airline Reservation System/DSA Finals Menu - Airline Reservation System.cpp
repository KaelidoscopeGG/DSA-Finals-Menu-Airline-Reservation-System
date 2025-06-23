#include <iostream>
using namespace std;

void MainMenu() {
    cout << "[Airline Reservation System]\n"
        << "----------------------------\n"
        << "Main Menu\n"
        << "1. View Available Flights\n"
        << "2. Search Flights\n"
        << "3. Book Flight\n"
        << "4. Search Reservation\n"
        << "5. Cancel Reservation\n"
        << "6. View Current Tickets\n"
        << "7. Exit\n"
        << "Enter your choice: ";
}

int main() {
    int choice = 0;

    do {
        MainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            //AvailableFlights();
            break;
        case 2:
            //SearchFlight();
            break;
        case 3:
            //BookFlight();
            break;
        case 4:
            //SearchReservations();
            break;
        case 5:
            //CancelReservation();
            break;
        case 6:
            //ViewCurrentTickets();
            break;
        case 7:
            cout << "Exiting program, goodbye!";
            return 0;
        default:
            cout << "Please enter a valid choice.\n";
        }

    } while (true);
}

