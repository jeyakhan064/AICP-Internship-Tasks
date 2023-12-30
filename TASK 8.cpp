#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <algorithm>

const int NUM_BOATS = 10;
const int OPENING_HOUR = 10;
const int CLOSING_HOUR = 17;
const double HOURLY_RATE = 20.0;
const double HALF_HOUR_RATE = 12.0;

struct Boat {
    bool isAvailable;
    double moneyTaken;
    double totalHoursHired;
    int returnTime;
};

void initializeBoats(std::vector<Boat>& boats) {
    for (int i = 0; i < NUM_BOATS; ++i) {
        boats[i].isAvailable = true;
        boats[i].moneyTaken = 0.0;
        boats[i].totalHoursHired = 0.0;
        boats[i].returnTime = OPENING_HOUR;
    }
}

bool isBoatAvailable(const Boat& boat, int currentTime) {
    return boat.isAvailable && currentTime >= boat.returnTime && currentTime <= CLOSING_HOUR;
}

int findNextAvailableBoat(const std::vector<Boat>& boats, int currentTime) {
    for (int i = 0; i < NUM_BOATS; ++i) {
        if (isBoatAvailable(boats[i], currentTime)) {
            return i + 1; // Boat numbers start from 1
        }
    }

    // If no boat is available, find the earliest return time
    int earliestReturnTime = CLOSING_HOUR + 1;
    for (const auto& boat : boats) {
        if (boat.returnTime < earliestReturnTime) {
            earliestReturnTime = boat.returnTime;
        }
    }

    return earliestReturnTime;
}

void hireBoat(std::vector<Boat>& boats, int boatNumber, int currentTime, double duration) {
    Boat& boat = boats[boatNumber - 1]; // Adjust for 0-based indexing
    boat.isAvailable = false;
    boat.moneyTaken += (duration <= 0.5) ? HALF_HOUR_RATE : HOURLY_RATE * duration;
    boat.totalHoursHired += duration;
    boat.returnTime = currentTime + duration;
}

void endOfDayReport(const std::vector<Boat>& boats) {
    double totalMoneyTaken = 0.0;
    double totalHoursHired = 0.0;
    int unusedBoats = 0;
    int mostUsedBoat = -1;
    double maxHoursHired = 0.0;

    for (int i = 0; i < NUM_BOATS; ++i) {
        totalMoneyTaken += boats[i].moneyTaken;
        totalHoursHired += boats[i].totalHoursHired;

        if (boats[i].isAvailable) {
            unusedBoats++;
        }

        if (boats[i].totalHoursHired > maxHoursHired) {
            mostUsedBoat = i + 1; // Boat numbers start from 1
            maxHoursHired = boats[i].totalHoursHired;
        }
    }

    std::cout << "\nEnd of Day Report:\n";
    std::cout << "Total money taken: $" << std::fixed << std::setprecision(2) << totalMoneyTaken << "\n";
    std::cout << "Total hours boats were hired: " << std::fixed << std::setprecision(2) << totalHoursHired << " hours\n";
    std::cout << "Number of unused boats: " << unusedBoats << "\n";

    if (mostUsedBoat != -1) {
        std::cout << "Boat #" << mostUsedBoat << " was used the most, with a total of " << maxHoursHired << " hours.\n";
    }
    else {
        std::cout << "No boats were used.\n";
    }
}

int main() {
    std::vector<Boat> boats(NUM_BOATS);
    initializeBoats(boats);

    // Current time (for testing purposes, you can replace this with the current time)
    int currentTime = 12;

    // Task 1: Calculate the money taken in a day for one boat
    int selectedBoat;
    double duration;

    std::cout << "Enter the boat number (1 to 10): ";
    std::cin >> selectedBoat;

    if (selectedBoat < 1 || selectedBoat > 10) {
        std::cout << "Invalid boat number. Exiting program.\n";
        return 0;
    }

    std::cout << "Enter the duration of boat hire (in hours): ";
    std::cin >> duration;

    if (duration <= 0 || currentTime < OPENING_HOUR || currentTime + duration > CLOSING_HOUR) {
        std::cout << "Invalid hire duration or time. Exiting program.\n";
        return 0;
    }

    hireBoat(boats, selectedBoat, currentTime, duration);

    std::cout << "\nMoney taken for boat #" << selectedBoat << ": $" << std::fixed << std::setprecision(2) << boats[selectedBoat - 1].moneyTaken << "\n";
    std::cout << "Total hours hired for boat #" << selectedBoat << ": " << std::fixed << std::setprecision(2) << boats[selectedBoat - 1].totalHoursHired << " hours\n";

    // Task 2: Find the next boat available
    int nextAvailableBoat = findNextAvailableBoat(boats, currentTime);

    if (nextAvailableBoat > 0 && nextAvailableBoat <= 10) {
        std::cout << "\nNext available boat: Boat #" << nextAvailableBoat << "\n";
    }
    else {
        std::cout << "\nNo boats available. Earliest available time: " << nextAvailableBoat << ":00\n";
    }

    // Task 3: Calculate the money taken for all the boats at the end of the day
    endOfDayReport(boats);

    return 0;
}
