#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

const int NUM_CHARITIES = 3;

struct Charity {
    std::string name;
    double totalDonation;

    // Constructor to initialize member variables
    Charity() : totalDonation(0.0) {}
};

void setupDonationSystem(std::vector<Charity>& charities) {
    std::cout << "Welcome to the Donation System Setup!\n";

    for (int i = 0; i < NUM_CHARITIES; ++i) {
        std::cout << "Enter the name of Charity " << i + 1 << ": ";
        std::cin >> charities[i].name;
    }

    std::cout << "\nCharities available:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        std::cout << i + 1 << ". " << charities[i].name << "\n";
    }
}

void recordAndTotalDonation(std::vector<Charity>& charities) {
    int choice;
    double shoppingBill;

    std::cout << "\nEnter your charity choice (1, 2, or 3), or -1 to show totals: ";
    std::cin >> choice;

    while (choice != -1) {
        if (choice >= 1 && choice <= NUM_CHARITIES) {
            std::cout << "Enter the value of your shopping bill: $";
            std::cin >> shoppingBill;

            double donation = shoppingBill * 0.01;
            charities[choice - 1].totalDonation += donation;

            std::cout << "Donation to " << charities[choice - 1].name << ": $" << std::fixed << std::setprecision(2) << donation << "\n";
        }
        else {
            std::cout << "Invalid choice. Please enter 1, 2, 3, or -1.\n";
        }

        std::cout << "\nEnter your charity choice (1, 2, or 3), or -1 to show totals: ";
        std::cin >> choice;
    }
}

void showTotals(const std::vector<Charity>& charities) {
    std::cout << "\nCharity Totals:\n";

    std::vector<Charity> sortedCharities(charities.begin(), charities.end());
    std::sort(sortedCharities.begin(), sortedCharities.end(), [](const Charity& a, const Charity& b) {
        return a.totalDonation > b.totalDonation;
        });

    for (const auto& charity : sortedCharities) {
        std::cout << charity.name << ": $" << std::fixed << std::setprecision(2) << charity.totalDonation << "\n";
    }

    double grandTotal = 0.0;
    for (const auto& charity : charities) {
        grandTotal += charity.totalDonation;
    }

    std::cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << std::fixed << std::setprecision(2) << grandTotal << "\n";
}

int main() {
    std::vector<Charity> charities(NUM_CHARITIES);

    // Task 1: Set up the donation system
    setupDonationSystem(charities);

    // Task 2: Record and total each donation
    recordAndTotalDonation(charities);

    // Task 3: Show the totals so far
    showTotals(charities);

    return 0;
}
