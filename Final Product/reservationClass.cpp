#include "reservationClass.h"
#include "Flight.h"
#include "FlightManager.h"
#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

void ReservationClass::MainMenu() {
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

void ReservationClass::ReserveFlight(FlightManager& fm, int& id) {
    ReservationData temp;
    Flight* tempFlight;
    int tempId;

    cout << "Enter Flight Number to reserve: ";
    cin >> tempId;
    cin.ignore();

    tempFlight = fm.searchFlight(tempId);

    if (tempFlight != nullptr) {
        temp.id = tempId;
        cout << "Enter your name: ";
        getline(cin, temp.name);
        cout << "Enter your passport number: ";
        getline(cin, temp.passportNumber);

        temp.dateOfFlight = tempFlight->date;
        temp.departureTime = tempFlight->departureTime;
        temp.price = tempFlight->price;
    
        fm.removeFlight(temp.id);

        reservationQueue.push(temp);

        cout << "Successfully booked a flight!\n\n";
    }

    else {
        cout << "Flight " << temp.id << " not found.\n\n";
    }
}

void ReservationClass::SearchReservation() {
    queue<ReservationData> tempQueue = reservationQueue;
    int search;

    if (reservationQueue.empty()) {
        cout << "There are no reservations to search.\n\n";
        return;
    }

    cout << "Enter Flight Number to search: ";
    cin >> search;

    while (!tempQueue.empty()) {
        ReservationData temp = tempQueue.front();

        if (temp.id == search) {
            cout << "Flight " << temp.id << " found:\n"
                << "Booked under: " << temp.name << endl
                << "Passport Number: " << temp.passportNumber << endl
                << "Date of Flight: " << temp.dateOfFlight << endl
                << "Departure Time: " << temp.departureTime << endl
                << "Price: $" << temp.price << endl << endl;
            return;
        }

        tempQueue.pop();
    }
    
    cout << "Could not find Flight Number: " << search << endl << endl;
}

void ReservationClass::CancelReservation() {
    queue<ReservationData> tempQueue = reservationQueue;
    int search;

    if (reservationQueue.empty()) {
        cout << "There are no reservations to cancel.\n\n";
        return;
    }

    cout << "Enter Flight Number to cancel: ";
    cin >> search;

    while (!tempQueue.empty()) {
        ReservationData temp = tempQueue.front();

        if (temp.id == search) {
            cout << "Cancelling Flight Number: " << search << endl << endl;
            deleteReservationById(search);
            return;
        }

        tempQueue.pop();
    }

    cout << "Could not find Flight Number: " << search << endl << endl;
}

void ReservationClass::ViewCurrentTickets() {
    queue<ReservationData> tempQueue = reservationQueue;

    if (reservationQueue.empty()) {
        cout << "There are no reservations to view.\n\n";
        return;
    }

    while (!tempQueue.empty()) {
        ReservationData temp = tempQueue.front();

        cout << "Flight " << temp.id << " found:\n"
            << "Booked under: " << temp.name << endl
            << "Passport Number: " << temp.passportNumber << endl
            << "Date of Flight: " << temp.dateOfFlight << endl
            << "Departure Time: " << temp.departureTime << endl
            << "Price: $" << temp.price << endl
            << "----------------------------------\n\n";

        tempQueue.pop();
    }
}

void ReservationClass::loadQueueFromFile() {
    ifstream infile(reservationFile.c_str());

    if (infile.is_open()) {
        ReservationData r;

        while (
            getline(infile, r.name) &&
            getline(infile, r.passportNumber) &&
            getline(infile, r.dateOfFlight) &&
            getline(infile, r.departureTime) &&
            (infile >> r.id) &&
            (infile >> r.price)
        ) {
            infile.ignore();
            reservationQueue.push(r);
        }

        infile.close();
    }
}

void ReservationClass::saveQueueToFile() {
    ofstream outfile(reservationFile.c_str());

    if (outfile.is_open()) {
        queue<ReservationData> tempQueue = reservationQueue;

        while (!tempQueue.empty()) {
            ReservationData& r = tempQueue.front();

            outfile << r.name << endl;
            outfile << r.passportNumber << endl;
            outfile << r.dateOfFlight << endl;
            outfile << r.departureTime << endl;
            outfile << r.id << endl;
            outfile << r.price << endl;
            tempQueue.pop();
        }

        outfile.close();
    }
}

void ReservationClass::deleteReservationById(int targetId) {
    queue<ReservationData> tempQueue;

    while (!reservationQueue.empty()) {
        ReservationData r = reservationQueue.front();

        if (r.id != targetId) {
            tempQueue.push(r);
        }

        reservationQueue.pop();
    }

    reservationQueue = tempQueue;
}

void ReservationClass::loadIdFromFile(int& id) {
    ifstream infile("idRecord.txt");
    if (infile.is_open()) {
        infile >> id;
        infile.close();
    }
}

void ReservationClass::saveIdToFile(const int& id) {
    ofstream outfile("idRecord.txt");
    if (outfile.is_open()) {
        outfile << id;
        outfile.close();
    }
}