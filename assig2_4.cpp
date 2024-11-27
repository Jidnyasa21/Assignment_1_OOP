#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    string name, illness;
    char sex;
    int age, ward, bed;
    string dateOfAdmission;

public:
    Patient() {}
    ~Patient() {}

    void inputData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Sex (M/F): ";
        cin >> sex;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Ward Number: ";
        cin >> ward;
        cout << "Enter Bed Number: ";
        cin >> bed;
        cout << "Enter Nature of Illness: ";
        cin.ignore();
        getline(cin, illness);
        cout << "Enter Date of Admission: ";
        getline(cin, dateOfAdmission);
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
        cout << "Ward Number: " << ward << endl;
        cout << "Bed Number: " << bed << endl;
        cout << "Illness: " << illness << endl;
        cout << "Date of Admission: " << dateOfAdmission << endl;
    }
};

int main() {
    Patient p;
    p.inputData();
    p.displayData();
    return 0;
}
