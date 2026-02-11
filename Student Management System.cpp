#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

/* ================= STUDENT CLASS ================= */
class Student {
public:
    int roll;
    string name;
    float cgpa;

    Student(int r = 0, string n = "", float c = 0.0) {
        roll = r;
        name = n;
        cgpa = c;
    }
};

/* ================= LINKED LIST NODE ================= */
class Node {
public:
    Student data;
    Node* next;

    Node(Student s) {
        data = s;
        next = NULL; // use NULL instead of nullptr
    }
};

/* ================= COMPARATOR ================= */
class CGPACompare {
public:
    bool operator()(Student a, Student b) {
        return a.cgpa < b.cgpa; // Max Heap for priority_queue
    }
};

/* ================= STUDENT MANAGEMENT SYSTEM ================= */
class StudentManagementSystem {
private:
    Node* head;
    stack<Student> undoStack;
    priority_queue<Student, vector<Student>, CGPACompare> admissionQueue;

    static bool compareCGPA(const Student &a, const Student &b);

public:
    StudentManagementSystem() { head = NULL; }
    ~StudentManagementSystem() { clearAll(); }

    bool rollExists(int roll) {
        Node* temp = head;
        while (temp) {
            if (temp->data.roll == roll) return true;
            temp = temp->next;
        }
        return false;
    }

    void clearAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        while (!undoStack.empty()) undoStack.pop();
        while (!admissionQueue.empty()) admissionQueue.pop();
    }

    void addStudent(Student s) {
        if (rollExists(s.roll)) {
            cout << "Roll number already exists!\n";
            return;
        }

        Node* newNode = new Node(s);

        // Insert in sorted order by Roll
        if (!head || s.roll < head->data.roll) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->data.roll < s.roll) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Student Added Successfully.\n";
    }

    void displayStudents() {
        if (!head) {
            cout << "No records found.\n";
            return;
        }

        Node* temp = head;
        float total = 0;
        int count = 0;

        cout << "\n--- Student Records ---\n";
        cout << left << setw(10) << "Roll"
             << setw(20) << "Name"
             << setw(10) << "CGPA\n";

        while (temp) {
            cout << left << setw(10) << temp->data.roll
                 << setw(20) << temp->data.name
                 << setw(10) << temp->data.cgpa << endl;

            total += temp->data.cgpa;
            count++;
            temp = temp->next;
        }

        cout << "Average CGPA: " << total / count << endl;
    }

    void searchStudent(int roll) {
        Node* temp = head;
        while (temp) {
            if (temp->data.roll == roll) {
                cout << "Found: " << temp->data.name
                     << " | CGPA: " << temp->data.cgpa << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int roll) {
        Node* curr = head;
        Node* prev = NULL;

        while (curr && curr->data.roll != roll) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Student not found.\n";
            return;
        }

        undoStack.push(curr->data);

        if (prev)
            prev->next = curr->next;
        else
            head = curr->next;

        delete curr;
        cout << "Deleted successfully (Undo available).\n";
    }

    void undoDelete() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        addStudent(undoStack.top());
        undoStack.pop();
    }

    void enqueueStudent(Student s) {
        admissionQueue.push(s);
        cout << "Added to admission queue.\n";
    }

    void processQueue() {
        if (admissionQueue.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Student s = admissionQueue.top();
        admissionQueue.pop();
        addStudent(s);
    }

    void sortByCGPA() {
        if (!head) {
            cout << "No records to sort.\n";
            return;
        }

        vector<Student> students;
        Node* temp = head;
        while (temp) {
            students.push_back(temp->data);
            temp = temp->next;
        }

        sort(students.begin(), students.end(), compareCGPA);

        cout << "\n--- Sorted by CGPA (High to Low) ---\n";
        cout << left << setw(10) << "Roll"
             << setw(20) << "Name"
             << setw(10) << "CGPA\n";
        for (int i = 0; i < (int)students.size(); i++) {
            cout << left << setw(10) << students[i].roll
                 << setw(20) << students[i].name
                 << setw(10) << students[i].cgpa << endl;
        }
    }

    void saveToFile() {
        ofstream file("students.txt");
        Node* temp = head;
        while (temp) {
            file << temp->data.roll << ","
                 << temp->data.name << ","
                 << temp->data.cgpa << endl;
            temp = temp->next;
        }
        file.close();
        cout << "Data saved successfully.\n";
    }

    void loadFromFile() {
        clearAll();
        ifstream file("students.txt");
        string line;

        while (getline(file, line)) {
            int roll;
            string name;
            float cgpa;

            size_t p1 = line.find(",");
            size_t p2 = line.rfind(",");

            if (p1 == string::npos || p2 == string::npos) continue;

            roll = atoi(line.substr(0, p1).c_str());
            name = line.substr(p1 + 1, p2 - p1 - 1);
            cgpa = atof(line.substr(p2 + 1).c_str());

            addStudent(Student(roll, name, cgpa));
        }
        file.close();
        cout << "Data loaded successfully.\n";
    }
};

bool StudentManagementSystem::compareCGPA(const Student &a, const Student &b) {
    return a.cgpa > b.cgpa; // high to low
}

/* ================= MAIN ================= */
int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n1.Add\n2.Display\n3.Search\n4.Delete\n5.Undo\n"
             << "6.Enqueue\n7.Process Queue\n8.Sort by CGPA\n"
             << "9.Save\n10.Load\n0.Exit\nChoice: ";
        cin >> choice;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        int roll;
        string name;
        float cgpa;

        switch (choice) {
        case 1:
            cout << "Roll: "; cin >> roll;
            if(cin.fail()) { cin.clear(); cin.ignore(1000,'\n'); break; }
            cin.ignore();
            cout << "Name: "; getline(cin, name);
            cout << "CGPA: "; cin >> cgpa;
            if(cin.fail() || cgpa < 0 || cgpa > 4) {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid CGPA (0-4 allowed)\n";
                break;
            }
            sms.addStudent(Student(roll, name, cgpa));
            break;

        case 2: sms.displayStudents(); break;
        case 3:
            cout << "Roll: "; cin >> roll;
            sms.searchStudent(roll);
            break;
        case 4:
            cout << "Roll: "; cin >> roll;
            sms.deleteStudent(roll);
            break;
        case 5: sms.undoDelete(); break;
        case 6:
            cout << "Roll: "; cin >> roll;
            cin.ignore();
            cout << "Name: "; getline(cin, name);
            cout << "CGPA: "; cin >> cgpa;
            sms.enqueueStudent(Student(roll, name, cgpa));
            break;
        case 7: sms.processQueue(); break;
        case 8: sms.sortByCGPA(); break;
        case 9: sms.saveToFile(); break;
        case 10: sms.loadFromFile(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

