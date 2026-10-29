
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    double numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;

    // Check invalid numerator
    if (cin.fail()) {
        cout << "Error: Please enter a valid number." << endl;
        return 0;
    }

    cout << "Enter denominator: ";
    cin >> denominator;

    // Check invalid denominator
    if (cin.fail()) {
        cout << "Error: Please enter a valid number." << endl;
        return 0;
    }

    try {
        // Check division by zero
        if (denominator == 0) {
            throw runtime_error(
                "Division by zero is not allowed."
            );
        }

        double result = numerator / denominator;

        cout << "Result = " << result << endl;
    }
    catch (const runtime_error &e) {
        cout << "Exception caught: "
             << e.what() << endl;
    }

    cout << "Program execution completed." << endl;

    return 0;
}
