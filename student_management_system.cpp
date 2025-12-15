#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll;
    char name[50];
    float marks;

public:
    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    int getRoll() {
        return roll;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);
    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();
    cout << "\nStudent Record Added Successfully!\n";
}

void displayAll() {
    Student s;
    ifstream file("students.dat", ios::binary);
    while (file.read((char*)&s, sizeof(s))) {
        s.display();
        cout << "---------------------";
    }
    file.close();
}

void searchStudent() {
    int r;
    bool found = false;
    Student s;
    ifstream file("students.dat", ios::binary);

    cout << "Enter Roll Number to Search: ";
    cin >> r;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getRoll() == r) {
            s.display();
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "\nStudent Record Not Found!\n";
}

void deleteStudent() {
    int r;
    Student s;
    ifstream in("students.dat", ios::binary);
    ofstream out("temp.dat", ios::binary);

    cout << "Enter Roll Number to Delete: ";
    cin >> r;

    while (in.read((char*)&s, sizeof(s))) {
        if (s.getRoll() != r)
            out.write((char*)&s, sizeof(s));
    }

    in.close();
    out.close();
    remove("students.dat");
    rename("temp.dat", "students.dat");

    cout << "\nStudent Record Deleted!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: displayAll(); break;
        case 3: searchStudent(); break;
        case 4: deleteStudent(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}
