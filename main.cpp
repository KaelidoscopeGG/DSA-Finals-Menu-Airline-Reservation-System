#include <iostream>
#include <string>
#include <iomanip>

#include "Flight.h"
#include "FlightManager.h"

using namespace std;

void MainMenu() {
    cout << "\n[Airline Reservation System]\n"
        << "----------------------------\n"
        << "Main Menu (Admin Side)\n"
        << "1. Add Available Flights (Linked List)\n"
        << "2. View Available Flights (Linked List)\n"
        << "3. Search Flights (Linked List)\n"
        << "4. Save Flight Transactions (File handling)\n"
        << "5. Book Flight / Remove Available Flights (Linked List) / Add Reservation (Queue) (Not Implemented)\n"
        << "6. Search Reservation (Queue) (Not Implemented)\n"
        << "7. Cancel Reservation (Queue) (Not Implemented)\n"
        << "8. View Current Tickets (Queue) (Not Implemented)\n"
        << "9. Save Reservation Transactions (File handling) (Not Implemented)\n"
        << "10. Exit\n"
        << "Enter your choice: ";
}

int main() {
    int choice = 0;

    FlightManager flightManager;

    flightManager.loadFlightsFromFile("flights.txt");

    do {
        MainMenu();
        cin >> choice;
        cin.ignore(); 
        cout << "\n";

        switch (choice) {
        case 1:
            flightManager.addFlightFromInput(); 
            break;
        case 2:
            flightManager.viewAllFlights(); 
            break;
        case 3:
            flightManager.searchFlightFromInput(); 
            break;
        case 4:
            flightManager.saveFlightsToFile("flights.txt"); 
            break;
        case 5:
            flightManager.removeFlightFromInput(); 
            cout << "The rest of this feature (Book Flight / Add Reservation etc.) is not implemented in the current admin-side version.\n";
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            cout << "This feature is not implemented in the current admin-side version.\n";
            break;
        case 10:
            cout << "Exiting program, goodbye!\n";
            flightManager.saveFlightsToFile("flights.txt");
            return 0;
        default:
            cout << "Please enter a valid choice (1-10).\n";
        }

        if (choice != 10) {
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

    } while (true);
}
