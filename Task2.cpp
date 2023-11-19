#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class ElectricMountainRailway {
public:
    ElectricMountainRailway();

    void startOfDayDisplay();
    void purchaseTickets(const string& tripType, const string& departureTime, int numTickets);
    void endOfDayDisplay();

private:
    vector<int> passengersUp;
    vector<int> passengersDown;
    vector<int> moneyUp;
    vector<int> moneyDown;
    vector<int> availableSeatsUp;
    vector<int> availableSeatsDown;
    vector<int> groupDiscountCount;

    int getTripIndex(const string& departureTime);
    int calculateTotalPrice(const string& tripType, int numTickets);
    void updateGroupDiscount(const string& tripType, int numTickets);
};

ElectricMountainRailway::ElectricMountainRailway() {
    passengersUp = { 0, 0, 0, 0 };
    passengersDown = { 0, 0, 0, 0 };
    moneyUp = { 0, 0, 0, 0 };
    moneyDown = { 0, 0, 0, 0 };
    availableSeatsUp = { 80, 80, 80, 80 };
    availableSeatsDown = { 80, 80, 80, 80 };
    groupDiscountCount = { 0, 0, 0, 0 };
}

void ElectricMountainRailway::startOfDayDisplay() {
    cout << "Welcome to the Electric Mountain Railway Booking System\n";
    // Display initial train schedule and available seats
}

void ElectricMountainRailway::purchaseTickets(const string& tripType, const string& departureTime, int numTickets) {
    int tripIndex = getTripIndex(departureTime);

    vector<int>& availableSeats = (tripType == "up") ? availableSeatsUp : availableSeatsDown;
    vector<int>& moneyTotals = (tripType == "up") ? moneyUp : moneyDown;
    vector<int>& passengersTotals = (tripType == "up") ? passengersUp : passengersDown;

    if (availableSeats[tripIndex] >= numTickets) {
        int totalPrice = calculateTotalPrice(tripType, numTickets);

        moneyTotals[tripIndex] += totalPrice;
        passengersTotals[tripIndex] += numTickets;
        availableSeats[tripIndex] -= numTickets;
        updateGroupDiscount(tripType, numTickets);

        cout << "Tickets purchased successfully for " << departureTime
            << ". Total cost: $" << totalPrice << "\n";
    }
    else {
        cout << "Sorry, not enough seats available for " << departureTime << " trip.\n";
    }
}

void ElectricMountainRailway::endOfDayDisplay() {
    cout << "\nEnd of the day summary:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Trip " << i + 1 << " - Passengers: " << passengersUp[i] + passengersDown[i]
            << ", Revenue: $" << moneyUp[i] + moneyDown[i] << "\n";
    }

    int totalPassengers = passengersUp[0] + passengersUp[1] + passengersDown[2] + passengersDown[3];
    int totalMoney = moneyUp[0] + moneyUp[1] + moneyDown[2] + moneyDown[3];

    cout << "\nTotal Passengers: " << totalPassengers << ", Total Revenue: $" << totalMoney << "\n";

    auto maxPassengersIndex = distance(passengersUp.begin(), max_element(passengersUp.begin(), passengersUp.end()));
    cout << "\nThe train journey with the most passengers today is Up Trip " << maxPassengersIndex + 1 << ".\n";
}

int ElectricMountainRailway::getTripIndex(const string& departureTime) {
    if (departureTime == "09:00" || departureTime == "11:00") {
        return 0;
    }
    else if (departureTime == "13:00" || departureTime == "15:00") {
        return 1;
    }
    else if (departureTime == "10:00" || departureTime == "12:00") {
        return 2;
    }
    else if (departureTime == "14:00" || departureTime == "16:00") {
        return 3;
    }
    else {
        return -1;
    }
}

int ElectricMountainRailway::calculateTotalPrice(const string& tripType, int numTickets) {
    int pricePerTicket = 25;
    int totalPrice = numTickets * pricePerTicket;

    int groupDiscount = groupDiscountCount[getTripIndex(tripType)];
    int freeTickets = (groupDiscount / 10) * 25;
    totalPrice -= freeTickets;

    return totalPrice;
}

void ElectricMountainRailway::updateGroupDiscount(const string& tripType, int numTickets) {
    groupDiscountCount[getTripIndex(tripType)] += numTickets;
}

int main() {
    ElectricMountainRailway railway;
    railway.startOfDayDisplay();

    // Example ticket purchases (you can replace these with user inputs)
    railway.purchaseTickets("up", "09:00", 5);
    railway.purchaseTickets("down", "10:00", 10);
    railway.purchaseTickets("up", "11:00", 15);
    railway.purchaseTickets("down", "14:00", 8);

    railway.endOfDayDisplay();

    return 0;
}

