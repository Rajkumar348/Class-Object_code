
#include <iostream>
#include <string>
using namespace std;

// 1. SINGLE INHERITANCE
class Student {
protected:
    string name;
    int roll;

public:
    void getDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
    }
};

class StudentInfo : public Student {
public:
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
    }
};

// 2. MULTIPLE INHERITANCE
class Academic {
protected:
    int academicMarks;

public:
    void getAcademic() {
        cout << "Enter academic marks: ";
        cin >> academicMarks;
    }
};

class Sports {
protected:
    int sportsMarks;

public:
    void getSports() {
        cout << "Enter sports marks: ";
        cin >> sportsMarks;
    }
};

class Total : public Academic, public Sports {
public:
    void displayTotal() {
        cout << "Total Marks: "
             << academicMarks + sportsMarks << endl;
    }
};

// 3. MULTILEVEL INHERITANCE
class Grandparent {
public:
    void showGrandparent() {
        cout << "Grandparent class" << endl;
    }
};

class Parent : public Grandparent {
public:
    void showParent() {
        cout << "Parent class" << endl;
    }
};

class Child : public Parent {
public:
    void showChild() {
        cout << "Child class" << endl;
    }
};

// 4. HIERARCHICAL INHERITANCE
class Animal {
public:
    void eat() {
        cout << "Animal eats food" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows" << endl;
    }
};

// 5. HYBRID INHERITANCE
class Person {
protected:
    string personName;

public:
    void getName() {
        cout << "Enter teaching assistant name: ";
        cin >> personName;
    }

    void showName() {
        cout << "Name: " << personName << endl;
    }
};

class StudentRole : virtual public Person {
public:
    void study() {
        cout << "Student studies" << endl;
    }
};

class EmployeeRole : virtual public Person {
public:
    void work() {
        cout << "Employee works" << endl;
    }
};

class TeachingAssistant : public StudentRole,
                          public EmployeeRole {
};

// MAIN FUNCTION
int main() {

    // Single Inheritance
    cout << "--- SINGLE INHERITANCE ---" << endl;
    StudentInfo s;
    s.getDetails();
    s.display();

    // Multiple Inheritance
    cout << "\n--- MULTIPLE INHERITANCE ---" << endl;
    Total t;
    t.getAcademic();
    t.getSports();
    t.displayTotal();

    // Multilevel Inheritance
    cout << "\n--- MULTILEVEL INHERITANCE ---" << endl;
    Child c;
    c.showGrandparent();
    c.showParent();
    c.showChild();

    // Hierarchical Inheritance
    cout << "\n--- HIERARCHICAL INHERITANCE ---" << endl;
    Dog d;
    Cat cat;

    d.eat();
    d.bark();
    cat.eat();
    cat.meow();

    // Hybrid Inheritance
    cout << "\n--- HYBRID INHERITANCE ---" << endl;
    TeachingAssistant ta;
    ta.getName();
    ta.showName();
    ta.study();
    ta.work();

    return 0;
}
