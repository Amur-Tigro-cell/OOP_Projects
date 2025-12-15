#include <iostream>
using namespace std;

class Employee {
    int empId;
    char name[50];
    float basic, hra, da, gross;

public:
    void input() {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Basic Salary: ";
        cin >> basic;
    }

    void calculate() {
        hra = 0.20 * basic;
        da  = 0.10 * basic;
        gross = basic + hra + da;
    }

    void display() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
        cout << "\nBasic Salary: " << basic;
        cout << "\nHRA: " << hra;
        cout << "\nDA: " << da;
        cout << "\nGross Salary: " << gross << endl;
    }
};

int main() {
    Employee e;
    int choice;

    do {
        cout << "\n===== EMPLOYEE PAYROLL SYSTEM =====";
        cout << "\n1. Enter Employee Details";
        cout << "\n2. Calculate Salary";
        cout << "\n3. Display Payslip";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            e.input();
            break;
        case 2:
            e.calculate();
            cout << "✅ Salary Calculated Successfully!\n";
            break;
        case 3:
            e.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
