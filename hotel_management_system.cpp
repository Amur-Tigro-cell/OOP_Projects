#include <iostream>
using namespace std;

class Hotel {
    int roomNo;
    bool booked;

public:
    Hotel() {
        booked = false;
    }

    void bookRoom() {
        if (!booked) {
            cout << "Enter Room Number: ";
            cin >> roomNo;
            booked = true;
            cout << "✅ Room Booked Successfully!\n";
        } else {
            cout << "❌ Room Already Booked!\n";
        }
    }

    void checkout() {
        if (booked) {
            booked = false;
            cout << "✅ Check-out Successful!\n";
        } else {
            cout << "❌ No Active Booking!\n";
        }
    }

    void status() {
        cout << "Room Status: " << (booked ? "Booked" : "Available") << endl;
    }
};

int main() {
    Hotel h;
    int choice;

    do {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====";
        cout << "\n1. Book Room";
        cout << "\n2. Check-out";
        cout << "\n3. Room Status";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: h.bookRoom(); break;
        case 2: h.checkout(); break;
        case 3: h.status(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
