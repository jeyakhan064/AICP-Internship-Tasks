#include <iostream>
#include <limits>  // Include <limits> for clearing input buffer

using namespace std;

// Function to calculate and display cost for slab 1
void costSlab1(int units) {
    int slab1_rate = 10;
    int slab1_units = min(units, 100);
    int cost = slab1_units * slab1_rate;
    cout << "Cost for slab 1: Rs." << cost << endl;
}

// Function to calculate and display cost for slab 2
void costSlab2(int units) {
    int slab2_rate = 15;
    int slab2_units = max(min(units, 200) - 100, 0);
    int cost = slab2_units * slab2_rate;
    cout << "Cost for slab 2: Rs." << cost << endl;
}

// Function to calculate and display cost for slab 3
void costSlab3(int units) {
    int slab3_rate = 20;
    int slab3_units = max(units - 200, 0);
    int cost = slab3_units * slab3_rate;
    cout << "Cost for slab 3: Rs." << cost << endl;
}

int main() {
    // Source data
    int electricity_consumption[3][3] = {
        {50, 150, 250},
        {120, 180, 300},
        {80, 220, 280}
    };

    // Student's ID display
    string student_id;
    cout << "Enter student's ID: ";
    cin >> student_id;
    cout << "Student's ID: " << student_id << endl;

    while (true) {
        // Display menu
        cout << "\nMenu:" << endl;
        cout << "1. Display bill of slab 1 and slab 2" << endl;
        cout << "2. Display bill of slab 3" << endl;
        cout << "3. Exit" << endl;

        char choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the input buffer to avoid potential issues
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == '1') {
            // Calculate and display cost for slab 1 and slab 2
            int total_units = electricity_consumption[0][0] + electricity_consumption[0][1] + electricity_consumption[0][2];
            costSlab1(total_units);
            costSlab2(total_units);
        }
        else if (choice == '2') {
            // Calculate and display cost for slab 3
            int total_units = electricity_consumption[2][0] + electricity_consumption[2][1] + electricity_consumption[2][2];
            costSlab3(total_units);
        }
        else if (choice == '3') {
            // Exit the program
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
