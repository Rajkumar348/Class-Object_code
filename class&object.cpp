#include <iostream>
#include <string>
using namespace std;

class Student
{
    int rollNo;
    string name;
    float marks;

public:

    // Constructor
    Student()
    {
        cout << "Student object created" << endl;
    }

    void getData()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin.ignore();              // Important
        getline(cin, name);        // Full name accept करेल

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayData()
    {
        cout << "\n--- Student Details ---" << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "\nStudent object destroyed" << endl;
    }
};

int main()
{
    Student s;

    s.getData();
    s.displayData();

    return 0;
}