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
#include <string> // Needed for string processing
using namespace std;

void calcTuition(double hrs, double aid, double& cost, double& owed) {
    const double RATE = 250.0;  // Cost per credit hour
    cost = hrs * RATE;
    owed = max(0.0, cost - aid);  // Ensure owed amount isn't negative
}

int main() {
    /************************************
    * Variable Descriptions             *
    *************************************
    * name = Student's last name        *
    * hrs = Credit hours taken          *
    * aid = Financial aid amount        *
    * cost = Tuition cost               *
    * owed = Tuition owed after aid     *
    * totalOwed = Total tuition owed    *
    * count = Number of students        *
    *************************************/

    string name;
    double hrs, aid, cost, owed, totalOwed = 0;
    int count = 0;

    cout << fixed << setprecision(2);
    cout << "(Press Ctrl + Z to finish)\n";

    while (true) {
        cout << "\n Enter student's last name: ";
        if (!(cin >> name)) break;

        // Validate credit hours input
        do {
            cout << "        Enter credit hours: ";
            cin >> hrs;
            if (cin.fail() || hrs < 0) {
                cout << "Invalid input. Please enter a non-negative number for credit hours.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break; // Valid input
            }
        } while (true);

        // Validate financial aid input
        do {
            cout << "Enter financial aid amount: $";
            cin >> aid;
            if (cin.fail() || aid < 0) {
                cout << "Invalid input. Please enter a non-negative number for financial aid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break; // Valid input
            }
        } while (true);

        calcTuition(hrs, aid, cost, owed);

        cout << "\nTuition Details for: " << name;
        cout << "\n       Credit Hours: " << hrs;
        cout << "\n       Tuition Cost: $" << cost;
        cout << "\n      Financial Aid: $" << aid;
        cout << "\n       Tuition Owed: $" << owed << "\n";

        totalOwed += owed;
        count++;
    }

    cout << "\nSummary for all students:";
    cout << "\n Number of Students: " << count;
    cout << "\n Total Tuition Owed: $" << totalOwed << endl;

    return 0;
}
