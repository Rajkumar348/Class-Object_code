#include <iostream>
#include <string>
using namespace std;

class MarksAudit;

class Student
{
private:
    int prn;
    string name;
    float marks1, marks2, marks3;

    static int studentCount;

public:
    // Constructor using this pointer
    Student(int p, string n, float m1, float m2, float m3)
    {
        this->prn = p;
        this->name = n;
        this->marks1 = m1;
        this->marks2 = m2;
        this->marks3 = m3;

        studentCount++;
    }

    // Inline function to calculate total
    inline float calculateTotal()
    {
        return marks1 + marks2 + marks3;
    }

    // Inline function to calculate average
    inline float calculateAverage()
    {
        return calculateTotal() / 3.0;
    }

    // Display student details
    inline void displayDetails()
    {
        cout << "\nPRN Number  : " << prn;
        cout << "\nName        : " << name;
        cout << "\nSubject 1   : " << marks1;
        cout << "\nSubject 2   : " << marks2;
        cout << "\nSubject 3   : " << marks3;
        cout << "\nTotal Marks : " << calculateTotal();
        cout << "\nAverage     : " << calculateAverage();

        if (calculateAverage() >= 40)
            cout << "\nResult      : PASS\n";
        else
            cout << "\nResult      : FAIL\n";
    }

    int getPRN()
    {
        return prn;
    }

    // Static member function
    static void displayStudentCount()
    {
        cout << "\nTotal Students Created: "
             << studentCount << endl;
    }

    friend class MarksAudit;
};

// Initialize static data member
int Student::studentCount = 0;


// Friend class for marks auditing
class MarksAudit
{
public:
    void auditStudent(Student &s)
    {
        float total = s.marks1 + s.marks2 + s.marks3;
        float average = total / 3.0;

        float highest = s.marks1;
        float lowest = s.marks1;

        if (s.marks2 > highest)
            highest = s.marks2;

        if (s.marks3 > highest)
            highest = s.marks3;

        if (s.marks2 < lowest)
            lowest = s.marks2;

        if (s.marks3 < lowest)
            lowest = s.marks3;

        cout << "\n===== MARKS AUDIT REPORT =====";
        cout << "\nStudent Name : " << s.name;
        cout << "\nTotal Marks  : " << total;
        cout << "\nAverage      : " << average;
        cout << "\nHighest Marks: " << highest;
        cout << "\nLowest Marks : " << lowest;

        if (average >= 40)
            cout << "\nAudit Status : PASS";
        else
            cout << "\nAudit Status : FAIL";

        cout << "\n==============================\n";
    }
};


// Validate marks
bool validMarks(float m1, float m2, float m3)
{
    return m1 >= 0 && m1 <= 100 &&
           m2 >= 0 && m2 <= 100 &&
           m3 >= 0 && m3 <= 100;
}


int main()
{
    Student *students[50];

    int n, prn, created = 0;
    string name;
    float m1, m2, m3;

    MarksAudit auditor;

    cout << "====================================";
    cout << "\n STUDENT MARKS MANAGEMENT SYSTEM";
    cout << "\n====================================";

    cout << "\nEnter number of students (1-50): ";
    cin >> n;

    if (n < 1 || n > 50)
    {
        cout << "Invalid number of students!";
        return 0;
    }

    // Enter student records
    while (created < n)
    {
        cout << "\n\nEnter details for Student "
             << created + 1 << endl;

        cout << "Enter PRN Number: ";
        cin >> prn;

        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter marks for Subject 1: ";
        cin >> m1;

        cout << "Enter marks for Subject 2: ";
        cin >> m2;

        cout << "Enter marks for Subject 3: ";
        cin >> m3;

        if (!validMarks(m1, m2, m3))
        {
            cout << "Invalid marks! Enter marks between 0 and 100.\n";
            continue;
        }

        students[created] =
            new Student(prn, name, m1, m2, m3);

        cout << "\n----- STUDENT DETAILS -----";
        students[created]->displayDetails();

        auditor.auditStudent(*students[created]);

        created++;
    }

    // Display student count
    Student::displayStudentCount();

    // Menu-driven operations
    int choice;

    do
    {
        cout << "\n========== MAIN MENU ==========";
        cout << "\n1. Display All Student Records";
        cout << "\n2. Audit Student by PRN";
        cout << "\n3. Display Student Count";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                for (int i = 0; i < created; i++)
                {
                    cout << "\nStudent " << i + 1;
                    students[i]->displayDetails();
                }
                break;

            case 2:
            {
                int searchPRN;
                bool found = false;

                cout << "Enter PRN to audit: ";
                cin >> searchPRN;

                for (int i = 0; i < created; i++)
                {
                    if (students[i]->getPRN() == searchPRN)
                    {
                        auditor.auditStudent(*students[i]);
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Student not found!\n";

                break;
            }

            case 3:
                Student::displayStudentCount();
                break;

            case 4:
                cout << "Exiting Student Marks Management System...";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    // Release allocated memory
    for (int i = 0; i < created; i++)
    {
        delete students[i];
    }

    return 0;
}
