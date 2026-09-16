#include <iostream>
using namespace std;

class BankAccount
{
    float balance;

public:

    // Default constructor
    BankAccount()
    {
        balance = 0;
    }

    // Parameterized constructor
    BankAccount(float b)
    {
        balance = b;
    }

    // Operator overloading
    BankAccount operator+(BankAccount acc)
    {
        BankAccount temp;
        temp.balance = balance + acc.balance;
        return temp;
    }

    
    void display()
    {
        cout << "Balance = Rs. " << balance << endl;
    }
};

int main()
{
    float balance1, balance2;

    cout << "Enter balance of Account 1: ";
    cin >> balance1;

    cout << "Enter balance of Account 2: ";
    cin >> balance2;

    BankAccount acc1(balance1);
    BankAccount acc2(balance2);

    BankAccount total = acc1 + acc2;

    cout << "\nAccount 1: ";
    acc1.display();

    cout << "Account 2: ";
    acc2.display();

    cout << "Total Balance: ";
    total.display();

    return 0;
}
