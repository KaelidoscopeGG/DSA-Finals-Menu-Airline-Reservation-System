#include "Flight.h"

using namespace std;

Flight::Flight() : flightNumber(0), departureCity(""), destinationCity(""),
departureTime(""), arrivalTime(""), date(""), price(0.0) {
}

Flight::Flight(int fn, string dc, string destc, string dept,
    string arrt, string dt, double p)
    : flightNumber(fn), departureCity(dc), destinationCity(destc),
    departureTime(dept), arrivalTime(arrt), date(dt), price(p) {
}

void Flight::displayFlightInfo() const {
    cout << "Flight No: " << flightNumber
        << ", From: " << departureCity
        << ", To: " << destinationCity
        << ", Date: " << date
        << ", Departure: " << departureTime
        << ", Arrival: " << arrivalTime
        << ", Price: $" << fixed << setprecision(2) << price << endl << endl;
}