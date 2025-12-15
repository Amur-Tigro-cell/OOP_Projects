#include <iostream>
using namespace std;

int main() {
    int pin = 1234, enteredPin;
    double balance = 10000;
    int choice;
    double amount;

    cout << "===== ATM SIMULATION SYSTEM =====\n";

    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (enteredPin != pin) {
        cout << "❌ Invalid PIN! Access Denied.\n";
        return 0;
    }

    do {
        cout << "\n1. Check Balance";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n💰 Current Balance: " << balance << endl;
            break;

        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            balance += amount;
            cout << "✅ Amount Deposited Successfully!\n";
            break;

        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (amount <= balance) {
                balance -= amount;
                cout << "✅ Please collect your cash.\n";
            } else {
                cout << "❌ Insufficient Balance!\n";
            }
            break;

        case 4:
            cout << "Thank you for using ATM!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
