/******************************************
* Edgardo Richard Ventura                 *
* Week 10                                 *
* Assignment 5                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/

#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
#include <cmath> // Needed for pow function
using namespace std;

/************************************
* Variable Descriptions             *
*************************************
* amt = initial investment amount   *
* r5 = 5-year interest rate         *
* r10 = 10-year interest rate       *
* amt5 = value after 5 years        *
* amt10 = value after 10 years      *
*************************************/

void calcInvestment(double amt, double r5, double r10, double& amt5, double& amt10) {
    amt5 = amt * pow((1 + r5), 5); // Compound interest for 5 years
    amt10 = amt * pow((1 + r10), 10); // Compound interest for 10 years
}

int main() {
    double amt, r5, r10, amt5, amt10;

    cout << fixed << setprecision(2);
    cout << "Investment Growth Calculator\n";
    cout << "(Press Ctrl+Z then Enter to finish)\n";

    while (true) {
        cout << "\nEnter investment amount: $";
        if (!(cin >> amt)) break;

        cout << "Enter 5-year rate (decimal): ";
        while (!(cin >> r5) || r5 < 0) {
            cout << "Invalid. Enter non-negative decimal for 5-year rate.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter 10-year rate (decimal): ";
        while (!(cin >> r10) || r10 < 0) {
            cout << "Invalid. Enter non-negative decimal for 10-year rate.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        calcInvestment(amt, r5, r10, amt5, amt10);

        cout << "\nInvestment: $" << amt;
        cout << "\nValue after 5 years: $" << amt5;
        cout << "\nValue after 10 years: $" << amt10 << "\n";
    }

    return 0;
}
