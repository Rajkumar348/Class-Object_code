
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> marks;
    int choice, value, position;

    do {
        cout << "\n--- STUDENT MARKS USING VECTOR ---" << endl;
        cout << "1. Insert at end" << endl;
        cout << "2. Insert at position" << endl;
        cout << "3. Delete last element" << endl;
        cout << "4. Delete at position" << endl;
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
            marks.push_back(value);
            cout << "Marks inserted." << endl;
            break;

        case 2:
            cout << "Enter position (1 to "
                 << marks.size() + 1 << "): ";
            cin >> position;

            if (position >= 1 &&
                position <= (int)marks.size() + 1) {
                cout << "Enter marks: ";
                cin >> value;

                marks.insert(
                    marks.begin() + position - 1, value);

                cout << "Marks inserted." << endl;
            } else {
                cout << "Invalid position." << endl;
            }
            break;

        case 3:
            if (!marks.empty()) {
                marks.pop_back();
                cout << "Last element deleted." << endl;
            } else {
                cout << "Vector is empty." << endl;
            }
            break;

        case 4:
            if (marks.empty()) {
                cout << "Vector is empty." << endl;
                break;
            }

            cout << "Enter position to delete (1 to "
                 << marks.size() << "): ";
            cin >> position;

            if (position >= 1 &&
                position <= (int)marks.size()) {
                marks.erase(
                    marks.begin() + position - 1);

                cout << "Element deleted." << endl;
            } else {
                cout << "Invalid position." << endl;
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
            sort(marks.begin(), marks.end());
            cout << "Marks sorted successfully." << endl;
            break;

        case 7:
            if (marks.empty()) {
                cout << "Vector is empty." << endl;
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