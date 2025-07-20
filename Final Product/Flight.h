#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Flight {
public:
    int flightNumber;
    string departureCity;
    string destinationCity;
    string departureTime;
    string arrivalTime;
    string date;
    double price;

    Flight();
    Flight(int fn, string dc, string destc, string dept,
        string arrt, string dt, double p);
    void displayFlightInfo() const;
};

#endif 
