#ifndef RESERVATIONCLASS_H
#define RESERVATIONCLASS_H

#include <iostream>
#include <queue>
#include "FlightManager.h"
using namespace std;

class ReservationClass {
private:
	struct ReservationData{
		string name = "", passportNumber = "", dateOfFlight = "", departureTime = "";
		int id = 0;
		double price = 0.0;
	};

	const string reservationFile = "reservations.txt";
	queue <ReservationData> reservationQueue;

public:
	void MainMenu();

	void ReserveFlight(FlightManager& fm, int& id);
	void SearchReservation();
	void CancelReservation();
	void ViewCurrentTickets();

	void loadQueueFromFile();
	void saveQueueToFile();

	void loadIdFromFile(int& id);
	void saveIdToFile(const int& id);

	void deleteReservationById(int targetId);
	
};

#endif