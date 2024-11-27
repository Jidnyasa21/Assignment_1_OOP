#include <iostream>
#include <string>
using namespace std;

class MarkSheet {
private:
    string name, subjectName;
    int rollNumber, subjectCode;
    double internalMarks, externalMarks, totalMarks;

public:
    MarkSheet() {}
    ~MarkSheet() {}

    void inputData() {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Subject Code: ";
        cin >> subjectCode;
        cout << "Enter Subject Name: ";
        cin.ignore();
        getline(cin, subjectName);
        cout << "Enter Internal Marks: ";
        cin >> internalMarks;
        cout << "Enter External Marks: ";
        cin >> externalMarks;

        totalMarks = internalMarks + externalMarks;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subject: " << subjectName << " (" << subjectCode << ")" << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main() {
    MarkSheet m;
    m.inputData();
    m.displayData();
    return 0;
}
