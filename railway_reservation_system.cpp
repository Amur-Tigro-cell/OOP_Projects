#include <iostream>
#include <fstream>
using namespace std;

class Passenger {
    int pnr;
    char name[50];
    int age;
    char train[50];

public:
    void input() {
        cout << "Enter PNR Number: ";
        cin >> pnr;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Train Name: ";
        cin.ignore();
        cin.getline(train, 50);
    }

    void display() {
        cout << "\nPNR: " << pnr;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nTrain: " << train << endl;
    }

    int getPNR() { return pnr; }
};

void bookTicket() {
    Passenger p;
    ofstream file("railway.dat", ios::binary | ios::app);
    p.input();
    file.write((char*)&p, sizeof(p));
    file.close();
    cout << "\nTicket Booked Successfully!\n";
}

void displayTickets() {
    Passenger p;
    ifstream file("railway.dat", ios::binary);
    while (file.read((char*)&p, sizeof(p))) {
        p.display();
        cout << "---------------------";
    }
    file.close();
}

void cancelTicket() {
    int pnr;
    Passenger p;
    ifstream in("railway.dat", ios::binary);
    ofstream out("temp.dat", ios::binary);

    cout << "Enter PNR to Cancel: ";
    cin >> pnr;

    while (in.read((char*)&p, sizeof(p))) {
        if (p.getPNR() != pnr)
            out.write((char*)&p, sizeof(p));
    }

    in.close();
    out.close();
    remove("railway.dat");
    rename("temp.dat", "railway.dat");

    cout << "\nTicket Cancelled Successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== RAILWAY RESERVATION SYSTEM =====";
        cout << "\n1. Book Ticket";
        cout << "\n2. Display Tickets";
        cout << "\n3. Cancel Ticket";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: bookTicket(); break;
        case 2: displayTickets(); break;
        case 3: cancelTicket(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
