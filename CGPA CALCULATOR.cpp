#include <iostream>
#include <vector>
using namespace std;

// Class to represent each subject's information
class Subject 
{
public:
    string subjectName;   // Name of the subject
    int creditHours;      // Credit hours for the subject
    float gradePoint;     // Grade point earned in the subject

    // Constructor to initialize a Subject
    Subject(string sn, int ch, float gp)
    {
        subjectName = sn;
        creditHours = ch;
        gradePoint = gp;
    }
};

// Class to represent a student and their subjects
class Student
{
public:
    string name;                     // Student's name
    vector<Subject> subjects;        // List of subjects

    // Constructor to initialize student name
    Student(string studentName)
    {
        name = studentName;
    }

    // Function to add a subject to the student's record
    void addSubject(string subjectName, int creditHours, float gradePoint)
    {
        // Create a new Subject object and add it to the subjects vector
        Subject newSubject(subjectName, creditHours, gradePoint);
        subjects.push_back(newSubject);
    }

    // Function to calculate CGPA
    float calculatecgpa()
    {
        int total_credit_hours = 0;       // Total credit hours
        float total_quality_points = 0;   // Total of (creditHours × gradePoint)

        // Loop through each subject to calculate totals
        for (const Subject &subject : subjects)
        {
            total_credit_hours += subject.creditHours;
            total_quality_points += subject.creditHours * subject.gradePoint;
        }

        // CGPA formula = total quality points / total credit hours
        return (total_credit_hours > 0) ? (total_quality_points / total_credit_hours) : 0;
    }

    // Function to display the student's CGPA
    void displaycgpa()
    {
        cout << "\nStudent Name: " << name << endl;
        float CGPA = calculatecgpa();   // Call function to get CGPA
        cout << "CGPA: " << CGPA << endl;
    }
};

// Main function — entry point of the program
int main()
{
    string name;
    int numberOfSubject;

    // Take student name input
    cout << "Enter the Student Name: ";
    getline(cin, name);

    // Take number of subjects input
    cout << "Enter the number of subjects: ";
    cin >> numberOfSubject;

    // Create a Student object
    Student student(name);

    // Loop to take input for each subject
    for (int i = 1; i <= numberOfSubject; i++)
    {
        string subjectName;
        int creditHours;
        float gradePoint;

        cout << "\nEnter the subject name: ";
        cin.ignore();                  // Clear leftover newline character
        getline(cin, subjectName);     // Input subject name with spaces

        cout << "Enter the credit hours: ";
        cin >> creditHours;

        cout << "Enter the grade point: ";
        cin >> gradePoint;

        // Add subject to the student's subject list
        student.addSubject(subjectName, creditHours, gradePoint);
    }

    // Display the calculated CGPA
    student.displaycgpa();

    return 0;
}

