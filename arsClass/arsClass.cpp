#include "arsClass.h"
#include <iostream>
using namespace std;

void Airline::MainMenu() {
    cout << "[Airline Reservation System]\n"
        << "----------------------------\n"
        << "Main Menu\n"
        << "1. Add Available Flights (Linked List)\n"
        << "2. View Available Flights (Linked List)\n"
        << "3. Search Flights (Linked List)\n"
        << "4. Save Flight Transactions (File handling)\n"
        << "5. Book Flight / Remove Available Flights (Linked List) / Add Reservation (Queue)\n"
        << "6. Search Reservation (Queue)\n"
        << "7. Cancel Reservation (Queue)\n"
        << "8. View Current Tickets (Queue)\n"
        << "9. Save Reservation Transactions (File handling)\n"
        << "10. Exit\n"
        << "Enter your choice: ";
}
