#include <iostream>
#include <vector>
#include "Travel_Desk_Management_System.cpp" // Include your main project file here

using namespace std;

int main() {
    // Sample initialization of TravelDesk and adding some trips
    TravelDesk travelDesk;

    // Adding sample trips
    travelDesk.addTrip("ABC123", 4, "LocationA", "LocationB", 123456);
    travelDesk.addTrip("XYZ789", 5, "LocationB", "LocationC", 234567);
    travelDesk.addTrip("DEF456", 3, "LocationA", "LocationC", 345678);
    travelDesk.addTrip("ABC123", 4, "LocationA", "LocationB", 1000);
    travelDesk.addTrip("XYZ789", 3, "LocationX", "LocationY", 1500);
    travelDesk.addTrip("ABC123", 4, "LocationA", "LocationB", 900);
    travelDesk.addTrip("ABC123", 4, "LocationA", "LocationX", 950);
    travelDesk.addTrip("ABC123", 4, "LocationA", "LocationB", 1400);
    travelDesk.addTrip("ABC123", 4, "LocationZ", "LocationB", 900);
    travelDesk.addTrip("ABC123", 4, "LocationY", "LocationX", 1000);

    // Displaying current booked trips
    cout << "Current Added Trips:" << endl;
    Location* location = travelDesk.getLocation("LocationA");
    if (location) {
        vector<Trip*> trips = location->gettrips();
        for (auto trip : trips) {
            cout << "Vehicle: " << trip->getVehicle()->getVehicleNumber() << ", "
                 << "Pickup: " << trip->getPickUpLocation() << ", "
                 << "Drop: " << trip->getDropLocation() << ", "
                 << "Departure Time: " << trip->getDepartureTime() << ", "
                 << "Booked Seats: " << trip->getBookedSeats() << endl;
        }
    } else {
        cout << "Location 'LocationA' not found." << endl;
    }

    // Book trips example
    string pickUpLocation = "LocationA";
    string dropLocation = "LocationB";
    
    string vehicleNumber1 = "ABC123";
    int departureTime1 = 123456;
    
    string vehicleNumber2 = "XYZ789";
    int departureTime2 = 234567;
    
    string vehicleNumber3 = "DEF456";
    int departureTime3 = 345678;

    // Book multiple seats for each trip
    int seatsToBook = 3;

    for (int i = 0; i < seatsToBook; ++i) {
        travelDesk.bookTrip(pickUpLocation, dropLocation, vehicleNumber1, departureTime1);
        travelDesk.bookTrip("LocationB", "LocationC", vehicleNumber2, departureTime2);
        travelDesk.bookTrip(pickUpLocation, "LocationC", vehicleNumber3, departureTime3);
    }

    // Display booked trips
    vector<Trip*> bookedTrips = {
        travelDesk.bookTrip(pickUpLocation, dropLocation, vehicleNumber1, departureTime1),
        travelDesk.bookTrip("LocationB", "LocationC", vehicleNumber2, departureTime2),
        travelDesk.bookTrip(pickUpLocation, "LocationC", vehicleNumber3, departureTime3)
    };

    cout << "\nBooked Trips:" << endl;
    for (auto trip : bookedTrips) {
        if (trip) {
            cout << "Vehicle: " << trip->getVehicle()->getVehicleNumber() << ", "
                 << "Pickup: " << trip->getPickUpLocation() << ", "
                 << "Drop: " << trip->getDropLocation() << ", "
                 << "Departure Time: " << trip->getDepartureTime() << ", "
                 << endl;
        } else {
            cout << "\nFailed to book trip. Please check availability." << endl;
        }
    }

    return 0;
}
