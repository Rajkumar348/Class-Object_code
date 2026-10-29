
#include <iostream>
#include <cmath>
using namespace std;

// Compile-Time Polymorphism
class Area {
public:
    // Area of Square
    int calculateArea(int side) {
        return side * side;
    }

    // Area of Rectangle
    int calculateArea(int length, int breadth) {
        return length * breadth;
    }
};

// Runtime Polymorphism
class Shape {
public:
    virtual void display() {
        cout << "This is a shape." << endl;
    }

    virtual ~Shape() {}
};

// Derived Class Rectangle
class Rectangle : public Shape {
public:
    void display() override {
        cout << "This is a rectangle." << endl;
    }
};

// Derived Class Circle
class Circle : public Shape {
public:
    void display() override {
        cout << "This is a circle." << endl;
    }
};

int main() {
    int side, length, breadth;
    double radius;

    // User Input
    cout << "Enter side of square: ";
    cin >> side;

    cout << "Enter length and breadth of rectangle: ";
    cin >> length >> breadth;

    cout << "Enter radius of circle: ";
    cin >> radius;

    Area obj;

    // Compile-Time Polymorphism
    cout << "\n--- Compile-Time Polymorphism ---" << endl;

    cout << "Area of square: "
         << obj.calculateArea(side) << endl;

    cout << "Area of rectangle: "
         << obj.calculateArea(length, breadth) << endl;

    // Runtime Polymorphism
    cout << "\n--- Runtime Polymorphism ---" << endl;

    Rectangle rect;
    Circle cir;

    Shape *ptr;

    ptr = &rect;
    ptr->display();

    ptr = &cir;
    ptr->display();

    // Area of Circle
    double circleArea = 3.14159 * radius * radius;

    cout << "\nArea of circle: "
         << circleArea << endl;

    return 0;
}
