#include <iostream>
#include <fstream>
using namespace std;

class Book {
    int bookId;
    char title[50];
    bool issued;

public:
    void add() {
        cout << "Enter Book ID: ";
        cin >> bookId;
        cout << "Enter Book Title: ";
        cin.ignore();
        cin.getline(title, 50);
        issued = false;
    }

    void display() {
        cout << "\nBook ID: " << bookId;
        cout << "\nTitle: " << title;
        cout << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
    }

    int getId() {
        return bookId;
    }

    bool isIssued() {
        return issued;
    }

    void issueBook() {
        issued = true;
    }

    void returnBook() {
        issued = false;
    }
};

void addBook() {
    Book b;
    ofstream file("library.dat", ios::binary | ios::app);
    b.add();
    file.write((char*)&b, sizeof(b));
    file.close();
    cout << "\nBook Added Successfully!\n";
}

void displayBooks() {
    Book b;
    ifstream file("library.dat", ios::binary);
    while (file.read((char*)&b, sizeof(b))) {
        b.display();
        cout << "---------------------";
    }
    file.close();
}

void issueBook() {
    int id;
    bool found = false;
    Book b;
    fstream file("library.dat", ios::binary | ios::in | ios::out);

    cout << "Enter Book ID to Issue: ";
    cin >> id;

    while (file.read((char*)&b, sizeof(b))) {
        if (b.getId() == id && !b.isIssued()) {
            b.issueBook();
            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));
            found = true;
            cout << "\nBook Issued Successfully!\n";
            break;
        }
    }
    file.close();

    if (!found)
        cout << "\nBook Not Available or Not Found!\n";
}

void returnBook() {
    int id;
    bool found = false;
    Book b;
    fstream file("library.dat", ios::binary | ios::in | ios::out);

    cout << "Enter Book ID to Return: ";
    cin >> id;

    while (file.read((char*)&b, sizeof(b))) {
        if (b.getId() == id && b.isIssued()) {
            b.returnBook();
            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));
            found = true;
            cout << "\nBook Returned Successfully!\n";
            break;
        }
    }
    file.close();

    if (!found)
        cout << "\nInvalid Book ID!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: displayBooks(); break;
        case 3: issueBook(); break;
        case 4: returnBook(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}
