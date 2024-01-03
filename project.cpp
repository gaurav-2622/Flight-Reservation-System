#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a flight
class Flight {
public:
    string flightNumber;
    string source;
    string destination;
    int availableSeats;

    Flight(string fNumber, string src, string dest, int seats) : flightNumber(fNumber), source(src), destination(dest), availableSeats(seats) {}

    void displayFlightDetails() {
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }
};

// Class representing the Flight Reservation System
class FlightReservationSystem {
public:
    vector<Flight> flights;

    // Function to add a new flight to the system
    void addFlight(string fNumber, string src, string dest, int seats) {
        Flight newFlight(fNumber, src, dest, seats);
        flights.push_back(newFlight);
        cout << "Flight " << fNumber << " added successfully." << endl;
    }

    // Function to display available flights
    void displayAvailableFlights() {
        cout << "Available Flights:" << endl;
        for (Flight flight : flights) {
            flight.displayFlightDetails();
            cout << "---------------------------" << endl;
        }
    }

    // Function to book a seat in a flight
    void bookSeat(string fNumber) {
        for (Flight& flight : flights) {
            if (flight.flightNumber == fNumber) {
                if (flight.availableSeats > 0) {
                    flight.availableSeats--;
                    cout << "Seat booked successfully for Flight " << fNumber << "." << endl;
                } else {
                    cout << "No available seats for Flight " << fNumber << "." << endl;
                }
                return;
            }
        }
        cout << "Flight " << fNumber << " not found." << endl;
    }
};

int main() {
    FlightReservationSystem reservationSystem;

    // Adding sample flights to the system
    reservationSystem.addFlight("F001", "New York", "London", 50);
    reservationSystem.addFlight("F002", "Paris", "Tokyo", 40);
    reservationSystem.addFlight("F003", "Los Angeles", "Sydney", 60);

    int choice;
    do {
        cout << "\nFlight Reservation System Menu:\n";
        cout << "1. Display Available Flights\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reservationSystem.displayAvailableFlights();
                break;
            case 2:
                string flightNumber;
                cout << "Enter the Flight Number to book a seat: ";
                cin >> flightNumber;
                reservationSystem.bookSeat(flightNumber);
                break;
            case 3:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
