#ifndef FLIGHT_MANAGER_H
#define FLIGHT_MANAGER_H

#include "Flight.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FlightManager {
private:
    struct FlightNode {
        Flight data;
        FlightNode* next = nullptr;

        FlightNode(const Flight& flight) : data(flight), next(nullptr) {}
    };

    FlightNode* head = nullptr;

public:
    FlightManager();
    ~FlightManager();
    void addFlightFromInput(int& id);
    void addFlight(const Flight& newFlight);
    void viewAllFlights() const;
    void searchFlightFromInput();
    Flight* searchFlight(int flightNum);
    bool removeFlight(int flightNum);
    void saveFlightsToFile(const string& filename) const;
    void loadFlightsFromFile(const string& filename);
};

#endif 
