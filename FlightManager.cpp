#include "FlightManager.h"
#include <sstream>
#include <limits> 

using namespace std;

FlightManager::FlightManager() : head(nullptr) {}

FlightManager::~FlightManager() {
    FlightNode* current = head;
    while (current != nullptr) {
        FlightNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void FlightManager::addFlightFromInput() {
    cout << "--- Add New Flight ---\n";
    string fn, dc, destc, dept, arrt, dt;
    int seats;
    double price;


    cout << "Enter Flight Number: "; getline(cin, fn);
    cout << "Enter Departure City: "; getline(cin, dc);
    cout << "Enter Destination City: "; getline(cin, destc);
    cout << "Enter Date (YYYY-MM-DD): "; getline(cin, dt);
    cout << "Enter Departure Time (HH:MM): "; getline(cin, dept);
    cout << "Enter Arrival Time (HH:MM): "; getline(cin, arrt);
    cout << "Enter Available Seats: ";
    while (!(cin >> seats)) { 
        cout << "Invalid input. Please enter a number for seats: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cout << "Enter Price: $";
    while (!(cin >> price)) { 
        cout << "Invalid input. Please enter a number for price: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    Flight newFlight(fn, dc, destc, dept, arrt, dt, seats, price);
    addFlight(newFlight); 
}


void FlightManager::addFlight(const Flight& newFlight) {
    FlightNode* newNode = new FlightNode(newFlight);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        FlightNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Flight " << newFlight.flightNumber << " added successfully.\n";
}

void FlightManager::viewAllFlights() const {
    if (head == nullptr) {
        cout << "No available flights to display.\n";
        return;
    }
    cout << "\n--- Available Flights ---\n";
    FlightNode* current = head;
    while (current != nullptr) {
        current->data.displayFlightInfo();
        current = current->next;
    }
    cout << "-------------------------\n";
}

void FlightManager::searchFlightFromInput() const {
    cout << "--- Search Flights ---\n";
    string searchFlightNum;
    cout << "Enter Flight Number to search: ";
    getline(cin, searchFlightNum);

    Flight* foundFlight = searchFlight(searchFlightNum); 
    if (foundFlight != nullptr) {
        cout << "Flight found:\n";
        foundFlight->displayFlightInfo();
    }
    else {
        cout << "Flight " << searchFlightNum << " not found.\n";
    }
}

Flight* FlightManager::searchFlight(const string& flightNum) {
    FlightNode* current = head;
    while (current != nullptr) {
        if (current->data.flightNumber == flightNum) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

bool FlightManager::removeFlightFromInput() {
    cout << "--- Remove Flight ---\n";
    string flightNum;
    cout << "Enter Flight Number to remove: ";
    getline(cin, flightNum);

    return removeFlight(flightNum); 
}


bool FlightManager::removeFlight(const string& flightNum) {
    if (head == nullptr) {
        return false;
    }
    FlightNode* current = head;
    FlightNode* prev = nullptr;
    if (current != nullptr && current->data.flightNumber == flightNum) {
        head = current->next;
        delete current;
        return true;
    }
    while (current != nullptr && current->data.flightNumber != flightNum) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        return false;
    }
    prev->next = current->next;
    delete current;
    return true;
}

void FlightManager::saveFlightsToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing flights.\n";
        return;
    }
    FlightNode* current = head;
    while (current != nullptr) {
        outFile << current->data.flightNumber << ","
            << current->data.departureCity << ","
            << current->data.destinationCity << ","
            << current->data.departureTime << ","
            << current->data.arrivalTime << ","
            << current->data.date << ","
            << current->data.availableSeats << ","
            << current->data.price << "\n";
        current = current->next;
    }
    outFile.close();
    cout << "Flight data saved to " << filename << ".\n";
}

void FlightManager::loadFlightsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Warning: Could not open file " << filename << " for reading flights. Starting with empty flight list.\n";
        return;
    }
    FlightNode* current = head;
    while (current != nullptr) {
        FlightNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;

    string line;
    while (getline(inFile, line)) {
        string fn, dc, destc, dept, arrt, dt, seatsStr, priceStr;
        stringstream ss(line);
        getline(ss, fn, ',');
        getline(ss, dc, ',');
        getline(ss, destc, ',');
        getline(ss, dept, ',');
        getline(ss, arrt, ',');
        getline(ss, dt, ',');
        getline(ss, seatsStr, ',');
        getline(ss, priceStr);

        int seats = stoi(seatsStr);
        double price = stod(priceStr);

        Flight newFlight(fn, dc, destc, dept, arrt, dt, seats, price);
        addFlight(newFlight);
    }
    inFile.close();
    cout << "Flight data loaded from " << filename << ".\n";
}
