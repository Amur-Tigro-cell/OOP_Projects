#include <iostream>
#include <fstream>
using namespace std;

class Account {
    int accNo;
    char name[50];
    float balance;

public:
    void create() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void display() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    int getAccNo() {
        return accNo;
    }

    void deposit(float amt) {
        balance += amt;
    }

    bool withdraw(float amt) {
        if (amt <= balance) {
            balance -= amt;
            return true;
        }
        return false;
    }
};

void createAccount() {
    Account a;
    ofstream file("bank.dat", ios::binary | ios::app);
    a.create();
    file.write((char*)&a, sizeof(a));
    file.close();
    cout << "\nAccount Created Successfully!\n";
}

void displayAccounts() {
    Account a;
    ifstream file("bank.dat", ios::binary);
    while (file.read((char*)&a, sizeof(a))) {
        a.display();
        cout << "---------------------";
    }
    file.close();
}

void depositAmount() {
    int acc;
    float amt;
    bool found = false;
    Account a;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    cout << "Enter Account Number: ";
    cin >> acc;
    cout << "Enter Amount to Deposit: ";
    cin >> amt;

    while (file.read((char*)&a, sizeof(a))) {
        if (a.getAccNo() == acc) {
            a.deposit(amt);
            file.seekp(-sizeof(a), ios::cur);
            file.write((char*)&a, sizeof(a));
            found = true;
            cout << "\nAmount Deposited Successfully!\n";
            break;
        }
    }
    file.close();

    if (!found)
        cout << "\nAccount Not Found!\n";
}

void withdrawAmount() {
    int acc;
    float amt;
    bool found = false;
    Account a;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    cout << "Enter Account Number: ";
    cin >> acc;
    cout << "Enter Amount to Withdraw: ";
    cin >> amt;

    while (file.read((char*)&a, sizeof(a))) {
        if (a.getAccNo() == acc) {
            if (a.withdraw(amt)) {
                file.seekp(-sizeof(a), ios::cur);
                file.write((char*)&a, sizeof(a));
                cout << "\nWithdrawal Successful!\n";
            } else {
                cout << "\nInsufficient Balance!\n";
            }
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "\nAccount Not Found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Deposit Amount";
        cout << "\n4. Withdraw Amount";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createAccount(); break;
        case 2: displayAccounts(); break;
        case 3: depositAmount(); break;
        case 4: withdrawAmount(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}
