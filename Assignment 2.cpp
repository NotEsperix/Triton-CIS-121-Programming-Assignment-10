/******************************************
* Edgardo Richard Ventura                 *
* Week 10                                 *
* Assignment 2                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/

#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
#include <string> // Needed for string processing
using namespace std;

// Function prototype
void computePostage(double weight, int zipCode, double& areaCharge, double& weightCharge, double& postage);

double getAreaCharge(int zipCode) {
    switch (zipCode) {
    case 60171: return 2.00;
    case 60172: return 2.50;
    case 60635: return 3.00;
    default: return 5.00;
    }
}

double getWeightCharge(double weight) {
    if (weight > 100) return 0.02;
    else if (weight > 50) return 0.03;
    else return 0.05;
}

bool isValidZipCode(const string& zipCode) {
    if (zipCode.length() != 5) return false;
    for (char digit : zipCode) {
        if (!isdigit(digit)) return false;
    }
    return true;
}

int main() {
    double weight, areaCharge, weightCharge, postage;
    string zipCodeInput;
    int zipCode, count = 0;
    double totalPostage = 0;

    cout << fixed << setprecision(2);
    cout << "Welcome to Amazoon Storefront and Postal Service!\n";
    cout << "(Press Ctrl + Z to finish)\n";

    while (true) {
        // Weight Input with Validation
        while (true) {
            cout << "\nWeight of the package (oz): ";
            cin >> weight;
            if (cin.fail() || weight <= 0) {
                cout << "Invalid input. Please enter a positive number for ounces.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break; // Valid weight entered
            }
        }

        // Zip Code Input with Validation
        while (true) {
            cout << "        Enter the zip code: ";
            cin >> zipCodeInput;
            if (!isValidZipCode(zipCodeInput)) {
                cout << "\nInvalid zip code. Please enter a 5-digit zip code.\n";
                cin.clear();
                // No need to ignore remaining input here since we're reading the whole line
            }
            else {
                zipCode = stoi(zipCodeInput); // Convert valid zip code to integer
                break; // Valid zip code entered
            }
        }

        computePostage(weight, zipCode, areaCharge, weightCharge, postage);

        cout << "\n  Area Charge: $" << areaCharge;
        cout << "\nWeight Charge: $" << weightCharge;
        cout << "\nTotal Postage: $" << postage << "\n";

        totalPostage += postage;
        count++;
    }
    
    cout << "\n            Number of Packages: " << count;
    cout << "\nTotal Postage for all Packages: $" << totalPostage << endl;

    return 0;
}

void computePostage(double weight, int zipCode, double& areaCharge, double& weightCharge, double& postage) {
    areaCharge = getAreaCharge(zipCode);
    weightCharge = weight * getWeightCharge(weight);
    postage = areaCharge + weightCharge;
}
