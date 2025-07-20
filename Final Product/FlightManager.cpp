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

void FlightManager::addFlightFromInput(int& id) {
    cout << "--- Add New Flight ---\n";
    string dc, destc, dept, arrt, dt;
    int fn;
    double price;

    fn = id;
    cout << "Enter Departure City: "; getline(cin, dc);
    cout << "Enter Destination City: "; getline(cin, destc);
    cout << "Enter Date (YYYY-MM-DD): "; getline(cin, dt);
    cout << "Enter Departure Time (HH:MM): "; getline(cin, dept);
    cout << "Enter Arrival Time (HH:MM): "; getline(cin, arrt);
    cout << "Enter Price: $";
    while (!(cin >> price)) {
        cout << "Invalid input. Please enter a number for price: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    id++;

    Flight newFlight(fn, dc, destc, dept, arrt, dt, price);
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
    cout << "Flight " << newFlight.flightNumber << " added successfully.\n\n";
}

void FlightManager::viewAllFlights() const {
    if (head == nullptr) {
        cout << "No available flights to display.\n\n";
        return;
    }
    cout << "\n--- Available Flights ---\n";
    FlightNode* current = head;
    while (current != nullptr) {
        current->data.displayFlightInfo();
        current = current->next;
    }
    cout << "-------------------------\n\n";
}

void FlightManager::searchFlightFromInput() {
    int searchFlightNum;

    cout << "--- Search Flights ---\n";
    cout << "Enter Flight Number to search: ";
    cin >> searchFlightNum;

    Flight* foundFlight = searchFlight(searchFlightNum);

    if (!foundFlight){
        cout << "Flight " << searchFlightNum << " not found.\n\n";
    }
    else {
        cout << "Flight found:\n\n";
        foundFlight->displayFlightInfo();
    }
}

Flight* FlightManager::searchFlight(int flightNum) {
    FlightNode* current = head;
    while (current != nullptr) {
        if (current->data.flightNumber == flightNum) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

bool FlightManager::removeFlight(int flightNum) {
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
        cerr << "Error: Could not open file " << filename << " for writing flights.\n\n";
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
            << current->data.price << "\n";
        current = current->next;
    }
    outFile.close();
    cout << "Flight data saved to " << filename << ".\n\n";
}

void FlightManager::loadFlightsFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Warning: Could not open file " << filename << " for reading flights. Starting with empty flight list.\n\n";
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
        string fnStr, dc, destc, dept, arrt, dt, priceStr;
        stringstream ss(line);
        getline(ss, fnStr, ',');
        getline(ss, dc, ',');
        getline(ss, destc, ',');
        getline(ss, dept, ',');
        getline(ss, arrt, ',');
        getline(ss, dt, ',');
        getline(ss, priceStr);

        int fn = stoi(fnStr);
        double price = stod(priceStr);

        Flight newFlight(fn, dc, destc, dept, arrt, dt, price);
        addFlight(newFlight);
    }
    inFile.close();
    cout << "Flight data loaded from " << filename << ".\n\n";
}