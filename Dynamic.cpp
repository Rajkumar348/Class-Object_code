
#include <iostream>
using namespace std;

// Swap two values using references
void swapByReference(float &x, float &y)
{
    float temp = x;
    x = y;
    y = temp;
}

// Swap two values using pointers
void swapByPointer(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Bank Account class
class BankAccount
{
    int accountNo;
    float balance;

public:
    BankAccount(int accNo, float amount)
    {
        accountNo = accNo;
        balance = amount;
    }

    void display()
    {
        cout << "Account Number: " << accountNo
             << ", Balance: Rs. " << balance << endl;
    }
};

int main()
{
    // PART A: REFERENCES AND POINTERS
    cout << "===== PART A: REFERENCES AND POINTERS =====" << endl;

    float a = 10000, b = 20000;
    float &ref = a;
    float *ptr = &b;

    cout << "a = " << a << ", ref = " << ref << endl;
    cout << "Address of a   : " << &a << endl;
    cout << "Address of ref : " << &ref << endl;
    cout << "b = " << b << ", *ptr = " << *ptr << endl;
    cout << "ptr holds address: " << ptr << endl;

    ref = 15000;
    *ptr = 25000;

    cout << "\nAfter ref = 15000 and *ptr = 25000:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    float x, y;
    cout << "\nEnter two account balances: ";
    cin >> x >> y;

    float x2 = x, y2 = y;

    swapByReference(x, y);
    cout << "Swap by reference: x = " << x
         << ", y = " << y << endl;

    swapByPointer(&x2, &y2);
    cout << "Swap by pointer  : x = " << x2
         << ", y = " << y2 << endl;

    // PART B: NEW AND DELETE OPERATORS
    cout << "\n===== PART B: NEW AND DELETE =====" << endl;

    // Dynamic single balance
    float *singleBalance = new float(25000);
    cout << "Dynamic balance: Rs. "
         << *singleBalance << endl;
    delete singleBalance;

    // Dynamic array of account balances
    int n;
    cout << "\nEnter number of account balances: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of balances must be positive." << endl;
        return 1;
    }

    float *balances = new float[n];
    float total = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter balance for account " << i + 1
             << ": Rs. ";
        cin >> balances[i];
        total = total + balances[i];
    }

    cout << "Total Balance   = Rs. " << total << endl;
    cout << "Average Balance = Rs. "
         << total / n << endl;

    delete[] balances;

    // Dynamic BankAccount object
    BankAccount *account = new BankAccount(101, 85500);
    cout << "\nDynamic Bank Account -> ";
    account->display();
    delete account;

    cout << "\nMemory freed using delete and delete[]." << endl;

    return 0;
}
