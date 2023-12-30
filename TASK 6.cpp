#include <iostream>
#include <iomanip>
#include <algorithm> // Added for std::min

const double CEMENT_WEIGHT_MIN = 24.9;
const double CEMENT_WEIGHT_MAX = 25.1;
const double SAND_GRAVEL_WEIGHT_MIN = 49.9;
const double SAND_GRAVEL_WEIGHT_MAX = 50.1;

const double CEMENT_PRICE = 3.0;
const double GRAVEL_PRICE = 2.0;
const double SAND_PRICE = 2.0;
const double DISCOUNT_PACK_PRICE = 10.0;

void checkSack(double weight, char content) {
    if ((content == 'C' && (weight < CEMENT_WEIGHT_MIN || weight > CEMENT_WEIGHT_MAX)) ||
        ((content == 'S' || content == 'G') && (weight < SAND_GRAVEL_WEIGHT_MIN || weight > SAND_GRAVEL_WEIGHT_MAX))) {
        std::cout << "Rejected: Invalid weight or content for the sack.\n";
    }
    else {
        std::cout << "Accepted: Sack with content '" << content << "' and weight " << weight << " kg.\n";
    }
}

void checkOrder() {
    int numCement, numGravel, numSand;
    int rejectedSacks = 0;
    double totalWeight = 0.0;

    std::cout << "Enter the number of sacks of cement, gravel, and sand for the order:\n";
    std::cin >> numCement >> numGravel >> numSand;

    std::cout << "\nChecking the order:\n";

    for (int i = 0; i < numCement; ++i) {
        double weight;
        char content = 'C';

        std::cout << "Enter the weight for cement sack " << i + 1 << ":\n";
        std::cin >> weight;

        checkSack(weight, content);
        totalWeight += weight;
    }

    for (int i = 0; i < numGravel; ++i) {
        double weight;
        char content = 'G';

        std::cout << "Enter the weight for gravel sack " << i + 1 << ":\n";
        std::cin >> weight;

        checkSack(weight, content);
        totalWeight += weight;
    }

    for (int i = 0; i < numSand; ++i) {
        double weight;
        char content = 'S';

        std::cout << "Enter the weight for sand sack " << i + 1 << ":\n";
        std::cin >> weight;

        checkSack(weight, content);
        totalWeight += weight;
    }

    std::cout << "\nTotal weight of the order: " << totalWeight << " kg.\n";
    std::cout << "Number of rejected sacks: " << rejectedSacks << "\n";
}

void calculatePrice() {
    int numCement, numGravel, numSand;
    double regularPrice = 0.0;

    std::cout << "Enter the number of sacks of cement, gravel, and sand for the order:\n";
    std::cin >> numCement >> numGravel >> numSand;

    regularPrice += numCement * CEMENT_PRICE;
    regularPrice += numGravel * GRAVEL_PRICE;
    regularPrice += numSand * SAND_PRICE;

    int numDiscountPacks = std::min({ numCement, numGravel / 2, numSand / 2 });

    double discountPrice = numDiscountPacks * DISCOUNT_PACK_PRICE;
    double totalDiscount = regularPrice - discountPrice;

    std::cout << "\nRegular price for the order: $" << std::fixed << std::setprecision(2) << regularPrice << "\n";

    if (numDiscountPacks > 0) {
        std::cout << "Discount price for " << numDiscountPacks << " special pack(s): -$" << totalDiscount << "\n";
        std::cout << "New price for the order: $" << regularPrice - totalDiscount << "\n";
    }
    else {
        std::cout << "No discount applied. Total price: $" << regularPrice << "\n";
    }
}

int main() {
    int choice;

    std::cout << "Choose a task:\n";
    std::cout << "1. Check the contents and weight of a single sack\n";
    std::cout << "2. Check a customer’s order for delivery\n";
    std::cout << "3. Calculate the price for a customer’s order\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        double sackWeight;
        char sackContent;

        std::cout << "Enter the weight for a single sack:\n";
        std::cin >> sackWeight;

        std::cout << "Enter the content for the sack (C for cement, G for gravel, S for sand):\n";
        std::cin >> sackContent;

        checkSack(sackWeight, sackContent);
        break;

    case 2:
        checkOrder();
        break;

    case 3:
        calculatePrice();
        break;

    default:
        std::cout << "Invalid choice. Exiting program.\n";
        break;
    }

    return 0;
}
