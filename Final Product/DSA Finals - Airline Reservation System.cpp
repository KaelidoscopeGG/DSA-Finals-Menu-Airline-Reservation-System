#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <fstream>

#include "Flight.h"
#include "FlightManager.h"
#include "reservationClass.h"

using namespace std;

int main()
{   
    FlightManager flightManager;
    ReservationClass reserve;
    int choice, id = 1;

    flightManager.loadFlightsFromFile("flights.txt");
    reserve.loadQueueFromFile();
    reserve.loadIdFromFile(id);

    do {
        reserve.MainMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            flightManager.addFlightFromInput(id);
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
            reserve.ReserveFlight(flightManager, id);
            break;
        case 6:
            reserve.SearchReservation();
            break;
        case 7:
            reserve.CancelReservation();
            break;
        case 8:
            reserve.ViewCurrentTickets();
            break;
        case 9:
            reserve.saveQueueToFile();
            cout << "Saved reservations to file!\n\n";
            break;
        case 10:
            cout << "Exiting program, thank you!\n";
            reserve.saveQueueToFile(); 
            reserve.saveIdToFile(id);
            flightManager.saveFlightsToFile("flights.txt");
            return 0;
            break;
        default:
            cout << "Please enter a valid choice (1-10).\n\n";
        }
    } while (true);
}