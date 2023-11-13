// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_CASES = 2;
const int NUM_RAM = 3;
const int NUM_HDD = 3;

// Function to display menu and get user choice
int getUserChoice(const string items[], const double prices[], int numItems) {
    cout << "Available options:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
    }

    int choice;
    cout << "Enter the number corresponding to your choice (0 for none): ";
    cin >> choice;

    // Validate user input
    while (choice < 0 || choice > numItems) {
        cout << "Invalid choice. Please enter a number between 0 and " << numItems << ": ";
        cin >> choice;
    }

    return choice - 1; // Adjust for zero-based indexing
}

int main() {
    // Arrays to store item codes, descriptions, and prices
    string caseCodes[NUM_CASES] = { "t-A1", "t-A2" };
    string caseDescriptions[NUM_CASES] = { "Compact", "Tower" };
    double casePrices[NUM_CASES] = { 75.00, 150.00 };

    string ramCodes[NUM_RAM] = { "t-B1", "t-B2", "t-B3" };
    string ramDescriptions[NUM_RAM] = { "8 GB", "16 GB", "32 GB" };
    double ramPrices[NUM_RAM] = { 79.99, 149.99, 299.99 };

    string hddCodes[NUM_HDD] = { "t-C1", "t-C2", "t-C3" };
    string hddDescriptions[NUM_HDD] = { "1 TB HDD", "2 TB HDD", "4 TB HDD" };
    double hddPrices[NUM_HDD] = { 49.99, 89.99, 129.99 };

    // Prompt user to choose one case, one RAM, and one HDD
    int chosenCase = getUserChoice(caseDescriptions, casePrices, NUM_CASES);
    int chosenRAM = getUserChoice(ramDescriptions, ramPrices, NUM_RAM);
    int chosenHDD = getUserChoice(hddDescriptions, hddPrices, NUM_HDD);

    // Calculate total cost
    double basicCost = 200.00;
    double totalCost = basicCost + casePrices[chosenCase] + ramPrices[chosenRAM] + hddPrices[chosenHDD];

    // Output chosen items and initial total cost
    cout << "\nChosen items:\n";
    cout << "Case: " << caseDescriptions[chosenCase] << " - $" << casePrices[chosenCase] << endl;
    cout << "RAM: " << ramDescriptions[chosenRAM] << " - $" << ramPrices[chosenRAM] << endl;
    cout << "Main HDD: " << hddDescriptions[chosenHDD] << " - $" << hddPrices[chosenHDD] << endl;
    cout << fixed << setprecision(2);
    cout << "\nInitial total cost of the computer: $" << totalCost << endl;

    // Task 2 - Ordering additional items
    cout << "\nDo you want to purchase additional items? (1 for yes, 0 for no): ";
    int purchaseAdditional;
    cin >> purchaseAdditional;

    double additionalItemsCost = 0.0;
    if (purchaseAdditional == 1) {
        // Arrays for additional items and their prices
        const int NUM_ADDITIONAL_ITEMS = 11;
        string additionalItemCodes[NUM_ADDITIONAL_ITEMS] = { "t-D1", "t-D2", "t-E1", "t-E2", "t-E3", "t-F1", "t-F2", "t-G1", "t-G2" };
        string additionalItemDescriptions[NUM_ADDITIONAL_ITEMS] = { "240 GB SSD", "480 GB SSD", "1 TB HDD", "2 TB HDD", "4 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard OS", "Professional OS" };
        double additionalItemPrices[NUM_ADDITIONAL_ITEMS] = { 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00 };

        // Prompt user to choose additional items
        int chosenAdditionalItem;
        do {
            chosenAdditionalItem = getUserChoice(additionalItemDescriptions, additionalItemPrices, NUM_ADDITIONAL_ITEMS);
            additionalItemsCost += additionalItemPrices[chosenAdditionalItem];

            cout << "Additional item added: " << additionalItemDescriptions[chosenAdditionalItem] << " - $" << additionalItemPrices[chosenAdditionalItem] << endl;
            cout << "Do you want to add more additional items? (1 for yes, 0 for no): ";
            cin >> purchaseAdditional;
        } while (purchaseAdditional == 1);

        // Update total cost with additional items
        totalCost += additionalItemsCost;
    }

    // Task 3 - Offering discounts
    double discountRate = 0.0;
    if (purchaseAdditional == 0) {
        discountRate = 0.05; // 5% discount for one additional item
    }
    else if (additionalItemsCost > 0.0) {
        discountRate = 0.10; // 10% discount for two or more additional items
    }

    double discountAmount = totalCost * discountRate;
    double discountedTotal = totalCost - discountAmount;

    // Output additional items and final total cost after discounts
    cout << "\nAdditional items cost: $" << additionalItemsCost << endl;
    cout << "Discount rate: " << fixed << setprecision(2) << discountRate * 100 << "%" << endl;
    cout << "Amount saved with discount: $" << discountAmount << endl;
    cout << "Final total cost of the computer after discounts: $" << discountedTotal << endl;

    return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
