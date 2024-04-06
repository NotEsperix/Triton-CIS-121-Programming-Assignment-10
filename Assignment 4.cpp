/******************************************
* Edgardo Richard Ventura                 *
* Week 10                                 *
* Assignment 4                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/
#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
using namespace std;

// Function prototype
void calculateOrder(int widgets, double& costPerWidget, double& extendedPrice, double& salesTax, double& totalOrder);

// Function to determine the cost per widget based on quantity
double getCostPerWidget(int widgets) {
    if (widgets >= 10000) return 4.00;
    else if (widgets >= 5000) return 5.00;
    else return 10.00;
}

int main() {
    int widgets;
    double costPerWidget, extendedPrice, salesTax, totalOrder, grandTotal = 0;

    cout << fixed << setprecision(2);
    cout << "Widget Order Calculator\n";
    cout << "(Press Ctrl+Z then Enter to finish)\n";

    while (true) {
        cout << "\nEnter number of widgets: ";
        if (!(cin >> widgets)) break;

        calculateOrder(widgets, costPerWidget, extendedPrice, salesTax, totalOrder);

        cout << "\nNumber of Widgets: " << widgets;
        cout << "\nCost per Widget: $" << costPerWidget;
        cout << "\nExtended Price: $" << extendedPrice;
        cout << "\nSales Tax: $" << salesTax;
        cout << "\nTotal Order: $" << totalOrder << "\n";

        grandTotal += totalOrder;
    }

    cout << "\nSummary:";
    cout << "\nGrand Total of All Orders: $" << grandTotal << endl;

    return 0;
}

void calculateOrder(int widgets, double& costPerWidget, double& extendedPrice, double& salesTax, double& totalOrder) {
    const double TAX_RATE = 0.07; // 7% sales tax

    costPerWidget = getCostPerWidget(widgets);
    extendedPrice = widgets * costPerWidget;
    salesTax = extendedPrice * TAX_RATE;
    totalOrder = extendedPrice + salesTax;
}
