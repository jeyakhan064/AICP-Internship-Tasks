#include <iostream>
#include <cmath>

using namespace std;

class Hexagon {
private:
    int sideLength;

public:
    Hexagon(int length) : sideLength(length) {}

    double calcArea() const {
        return 1.5 * 1.732 * sideLength * sideLength;
    }

    double calcPeri() const {
        return 6 * sideLength;
    }

    double calcAngleSum() const {
        return 6 * 120;
    }

    void display() const {
        cout << "Hexagon - Area: " << calcArea() << ", Perimeter: " << calcPeri()
            << ", Sum of Angles: " << calcAngleSum() << endl;
    }
};

class Square {
private:
    int sideLength;

public:
    Square(int length) : sideLength(length) {}

    double calcAreaSquare() const {
        return sideLength * sideLength;
    }

    double calcPeriSquare() const {
        return 4 * sideLength;
    }

    void display() const {
        cout << "Square - Area: " << calcAreaSquare() << ", Perimeter: " << calcPeriSquare() << endl;
    }
};

int main() {
    
    int hexagonSideLength = 8;  
    int squareSideLength = hexagonSideLength + 1;

    Hexagon hexagon(hexagonSideLength);
    Square square(squareSideLength);

    cout << "Enter 1 for Hexagon or 2 for Square: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        hexagon.display();
        break;
    case 2:
        square.display();
        break;
    default:
        cout << "Exiting program." << endl;
        return 0;
    }

    return 0;
}
