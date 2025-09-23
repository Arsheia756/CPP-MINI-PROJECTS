#include <iostream>
#include <conio.h>
using namespace std;

class Student {
public:
    string Name;
    int Rollno;
    float Marks[6];
    float Averagemarks;
    char Grade;

    void calculateGrade() {
        if (Averagemarks >= 90) Grade = 'A';
        else if (Averagemarks >= 80) Grade = 'B';
        else if (Averagemarks >= 70) Grade = 'C';
        else if (Averagemarks >= 60) Grade = 'D';
        else Grade = 'F';
    }

    void display() {
        cout << "\nName: " << Name;
        cout << "\nRoll No: " << Rollno;
        cout << "\nAverage Marks: " << Averagemarks;
        cout << "\nGrade: " << Grade << endl;
    }
};

int main() {
    cout << "=======================================================\n";
    cout << "            STUDENT MARKS MANAGEMENT SYSTEM             \n";
    cout << "=======================================================\n";

    cout << "Press any key to enter....";
    getch();
    system("cls");

    int choice;
    Student s;
    cout << "\nMain Menu\n";
    cout << "1. Add Student Record.\n";
    cout << "2. Display Student Record.\n";
    cout << "3. Exit.\n\n";

    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter student name: ";
        cin >> s.Name;
        cout << "Enter student roll no: ";
        cin >> s.Rollno;

        float sum = 0;
        cout << "Enter marks in 6 subjects:\n";
        for (int i = 0; i < 6; i++) {
            cin >> s.Marks[i];
            sum += s.Marks[i];
        }

        s.Averagemarks = sum / 6;
        s.calculateGrade();

        cout << "\nRecord Added Successfully!\n";
        s.display();
    }
    else if (choice == 2) {
        cout << "No records to display yet!\n";
    }
    else if (choice == 3) {
        cout << "Exiting Program...\n";
    }
    else {
        cout << "Invalid choice!\n";
    }

    return 0;
}

