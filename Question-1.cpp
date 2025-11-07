#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Variables
    int accountNumber, totalMinutes, dayMinutes, nightMinutes;
    char serviceCode;
    double totalBill;

    // Prompt user for input
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout << "Enter service code (r/R for regular, p/P for premium): ";
    cin >> serviceCode;
    cout << "Enter total minutes used: ";
    cin >> totalMinutes;

    // Calculate bill based on service type
    if (serviceCode == 'r' || serviceCode == 'R') {
        // Regular service
        double baseRate = 100.0;
        double ratePerMinute = 2.0;
        int freeMinutes = 50;

        if (totalMinutes > freeMinutes) {
            totalBill = baseRate + (totalMinutes - freeMinutes) * ratePerMinute;
        } else {
            totalBill = baseRate;
        }
    } else if (serviceCode == 'p' || serviceCode == 'P') {
        // Premium service
        double baseRate = 250.0;
        double dayRate = 1.0;
        double nightRate = 0.5;
        int dayFreeMinutes = 75;
        int nightFreeMinutes = 100;

        cout << "Enter minutes used during the day (6:00 a.m. to 6:00 p.m.): ";
        cin >> dayMinutes;
        cout << "Enter minutes used during the night (6:00 p.m. to 6:00 a.m.): ";
        cin >> nightMinutes;

        double dayCharge = (dayMinutes > dayFreeMinutes) ? baseRate + (dayMinutes - dayFreeMinutes) * dayRate : baseRate;
        double nightCharge = (nightMinutes > nightFreeMinutes) ? baseRate + (nightMinutes - nightFreeMinutes) * nightRate : baseRate;
        totalBill = dayCharge + nightCharge;
    } else {
        // Invalid service code
        cout << "Invalid service code. Please try again." << endl;
        return 1;
    }

    // Output the bill
    cout << fixed << setprecision(2);
    cout << "Account Number: " << accountNumber << endl;
    cout << "Service Type: " << ((serviceCode == 'r' || serviceCode == 'R') ? "Regular" : "Premium") << endl;
    cout << "Total Minutes Used: " << totalMinutes << endl;
    cout << "Total Bill: R" << totalBill << endl;

    return 0;
}
