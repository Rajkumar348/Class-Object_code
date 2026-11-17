
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;

    // Parameterized Constructor
    Student(string n, int r)
    {
        name = n;
        rollNo = r;
    }

    // Move Constructor
    Student(Student&& s)
    {
        name = std::move(s.name);
        rollNo = s.rollNo;

        s.rollNo = 0;

        cout << "Move Constructor Called" << endl;
    }

    // Display Function
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

int main()
{
    Student s1("Rajkumar", 101);

    cout << "Before Move Operation:" << endl;
    s1.display();

    Student s2(std::move(s1));

    cout << "\nAfter Move Operation:" << endl;

    cout << "\nStudent 1 Details:" << endl;
    s1.display();

    cout << "\nStudent 2 Details:" << endl;
    s2.display();

    return 0;
}