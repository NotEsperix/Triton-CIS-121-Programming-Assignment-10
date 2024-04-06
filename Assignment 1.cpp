/******************************************
* Edgardo Richard Ventura                 *
* Week 10                                 *
* Assignment 1                            *
* Instructor: Frank Alvino                *
* CIS 121-061                             *
*******************************************/

#include <iostream>
#include <iomanip>
#include <limits> // Needed for std::numeric_limits
using namespace std;

string getItemName(double price) {
    if (price <= 0.00) return "Nothing, because you're a Peasant";
    if (price > 0.00 && price <= 0.25) return "Sauce Pack";
    if (price >= 0.26 && price <= 0.50) return "Self Serve Drink";
    if (price >= 0.51 && price <= 1.00) return "Cheese Burger";
    if (price >= 1.01 && price <= 2.00) return "Double Cheese Burger";
    if (price >= 2.01 && price <= 3.00) return "WcHappy Meal";
    if (price >= 3.00 && price <= 4.00) return "Lots of Bacon";
    if (price >= 4.01 && price <= 5.00) return "Butter Milk Chicken Selects";
    if (price >= 5.01 && price <= 6.00) return "Pretzel Bread BBQ, Bacon, and Onion Cheese Burger";
    if (price >= 6.01 && price <= 10.00) return "Milk Shake";
    if (price >= 10.01 && price <= 20.00) return "Vegan Food";
    if (price >= 20.01 && price <= 50.00) return "WcWhopper";
    if (price >= 50.01 && price <= 100.00) return "WcDonalds Special Event Wings";
    if (price >= 100.01 && price <= 250.00) return "WcDonalds and Bob's Burgers Collaboration Event Macaroni Burger";
    if (price >= 250.01 && price <= 350.00) return "WcIzza";
    if (price >= 350.01 && price <= 450.00) return "WcSad Meal";
    if (price >= 450.01 && price <= 550.00) return "Water";
    if (price >= 550.01 && price <= 1000.00) return "Premium Water";
    return "Blessed Italian Beef";
}

int main() {

    /************************************
    * Variable Descriptions            *
    *************************************
    * p  = price per item              *
    * q  = quantity of items           *
    * t  = total cost before tax       *
    * tt = tax for the current order   *
    * to = total cost including tax    *
    * gt = cumulative total before tax *
    * gtt= cumulative total tax        *
    * gto= grand total with tax        *
    * itemName = name of the item      *
    *************************************/

    double p, q, t, tt, to;
    double gt = 0, gtt = 0, gto = 0;
    int count = 0;
    string itemName;

    cout << fixed << setprecision(2);


    /* Greeting */
    cout << "Hello, and welcome to WcDonalds! How may I take your order?\n";
    cout << "(Press Ctrl + Z to finish)\n\n";

    /* Input and Process Phase */
    while (true) {
        // Price Input with Validation
        while (true) {
            cout << "   Enter price: $";
            cin >> p;

            if (cin.eof()) {
                cin.clear();
                break;
            }
            if (cin.fail() || p < 0) {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "\nInvalid Input. Please enter a valid price." << endl;
            }
            else {
                break; // Valid price entered, break out of the loop
            }
        }

        if (cin.eof()) break; // Break out of the while loop to proceed to summary output


        // Quantity Input with Validation
        while (true) {
            cout << "Enter quantity: ";
            cin >> q;

            if (cin.fail() || q < 0) {
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
                cout << "\nInvalid Input. Please enter a valid quantity." << endl;
            }
            else {
                break; // Valid quantity entered, break out of the loop
            }
        }


        /* Process Phase */
        itemName = getItemName(p);  // Ensures the item name is determined by the unit price 
        t = q * p;  // Total cost for the quantity of items ordered 
        tt = t * 0.07;  // Tax calculated on the total cost 
        to = t + tt;  // Total order cost including tax 

        gt += t;  // Updates the grand total (before tax) for all orders 
        gtt += tt;  // Updates the grand total tax for all orders 
        gto += to;  // Updates the grand total cost (including tax) for all orders 
        count++;  // Increments the count of items ordered


        /* Output Phase */
        cout << "\nYour selected order comes out to:";
        cout << "\nItem purchased: " << itemName;
        cout << "\n         Price: $" << p; // Displaying unit price
        cout << "\n      Quantity: " << q << "\n"; // Displaying quantity

        cout << "\n         Total: $" << t; // Displaying total before tax
        cout << "\n           Tax: $" << tt << "\n"; // Displaying tax amount
        cout << "\n  Total w/ Tax: $" << to << "\n"; // Displaying total with tax

        cout << "\nIs there anything else I can help you with?\n";
    }


    /* Summary Output */
    cout << "\n Number of entries: " << count;
    cout << "\n       Grand Total: $" << gt;
    cout << "\n   Grand Total Tax: $" << gtt;
    cout << "\nGrand Total W/ Tax: $" << gto << endl;

    return 0;
}
