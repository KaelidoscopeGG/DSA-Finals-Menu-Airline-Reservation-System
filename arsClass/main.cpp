#include <iostream>
#include "arsClass.h"
using namespace std;

int main()
{   
    Airline ars;
    int choice;

    do {
        ars.MainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            // add available flights
            break;
        case 2:
            // view available flights
            break;
        case 3:
            // search flights
            break;
        case 4:
            // save flight transactions
            break;
        case 5:
            // book flight (remove available flights/add reservation)
            break;
        case 6:
            // search reservation
            break;
        case 7:
            // cancel reservation
            break;
        case 8:
            // view current tickets
            break;
        case 9:
            //save reservation transactions
            break;
        case 10:
            cout << "Exiting program, thank you!";
            return 0;
            break;
        default:
            cout << "Please enter a number available in the list.\n\n";  
        }
    } while (true);
}
