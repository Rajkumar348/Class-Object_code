
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class" << endl;
    }
};

int main() {
    // 1. Implicit Type Casting
    int a;
    cout << "Enter an integer: ";
    cin >> a;

    float b = a;
    cout << "Implicit casting (float): " << b << endl;

    // 2. Explicit Type Casting
    double x;
    cout << "\nEnter a decimal number: ";
    cin >> x;

    int y = (int)x;
    cout << "Explicit casting (integer): " << y << endl;

    // 3. static_cast
    double price;
    cout << "\nEnter a decimal value for static_cast: ";
    cin >> price;

    int amount = static_cast<int>(price);
    cout << "static_cast result: " << amount << endl;

    // 4. dynamic_cast
    cout << "\n--- dynamic_cast ---" << endl;

    Derived d;
    Base* basePtr = &d;
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr != NULL) {
        derivedPtr->show();
    } else {
        cout << "Conversion failed" << endl;
    }

    // 5. const_cast
    int number;
    cout << "\nEnter an integer for const_cast: ";
    cin >> number;

    const int* constPtr = &number;
    int* normalPtr = const_cast<int*>(constPtr);

    *normalPtr = *normalPtr + 10;

    cout << "After const_cast: " << number << endl;

    // 6. reinterpret_cast
    int value;
    cout << "\nEnter an integer for reinterpret_cast: ";
    cin >> value;

    char* charPtr = reinterpret_cast<char*>(&value);

    cout << "Memory address: "
         << static_cast<void*>(charPtr) << endl;

    return 0;
}