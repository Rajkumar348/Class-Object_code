
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> marks;
    int choice, value;

    do {
        cout << "\n--- STUDENT MARKS USING LIST ---" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete from beginning" << endl;
        cout << "4. Delete from end" << endl;
        cout << "5. Search marks" << endl;
        cout << "6. Sort marks" << endl;
        cout << "7. Display marks" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter marks: ";
            cin >> value;
            marks.push_front(value);
            cout << "Inserted at beginning." << endl;
            break;

        case 2:
            cout << "Enter marks: ";
            cin >> value;
            marks.push_back(value);
            cout << "Inserted at end." << endl;
            break;

        case 3:
            if (!marks.empty()) {
                marks.pop_front();
                cout << "First element deleted." << endl;
            } else {
                cout << "List is empty." << endl;
            }
            break;

        case 4:
            if (!marks.empty()) {
                marks.pop_back();
                cout << "Last element deleted." << endl;
            } else {
                cout << "List is empty." << endl;
            }
            break;

        case 5:
            cout << "Enter marks to search: ";
            cin >> value;

            {
                bool found = false;

                for (int m : marks) {
                    if (m == value) {
                        found = true;
                        break;
                    }
                }

                if (found)
                    cout << "Marks found." << endl;
                else
                    cout << "Marks not found." << endl;
            }
            break;

        case 6:
            marks.sort();
            cout << "Marks sorted successfully." << endl;
            break;

        case 7:
            if (marks.empty()) {
                cout << "List is empty." << endl;
            } else {
                cout << "Student marks: ";

                for (int m : marks) {
                    cout << m << " ";
                }

                cout << endl;
            }
            break;

        case 8:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 8);

    return 0;
}