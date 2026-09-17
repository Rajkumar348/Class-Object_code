#include <iostream>
using namespace std;

class Student
{
    int rollNo;
    string name;
    float marks;

public:

    // Default Constructor
    Student()
    {
        rollNo = 0;
        name = "Unknown";
        marks = 0;
    }

    // Parameterized Constructor
    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
    }

    // Copy Constructor
    Student(Student &s)
    {
        rollNo = s.rollNo;
        name = s.name;
        marks = s.marks;
    }

    
    void display()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "------------------------" << endl;
    }

    
    void changeMarks(float m)
    {
        marks = m;
    }

   
    void result()
    {
        if (marks >= 40)
            cout << name << " has Passed." << endl;
        else
            cout << name << " has Failed." << endl;
    }
};

int main()
{
    
    Student s1;

    cout << "Default Constructor:" << endl;
    s1.display();

   
    Student s2(011, "Rajkumar", 75.5);

    cout << "Parameterized Constructor:" << endl;
    s2.display();

    
    Student s3(s2);

    cout << "Copy Constructor:" << endl;
    s3.display();

    
    cout << "After changing marks:" << endl;
    s3.changeMarks(90);
    s3.display();

    
    cout << "Result:" << endl;
    s3.result();

    return 0;
}