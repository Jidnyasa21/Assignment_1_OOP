#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name, designation;
    int code, experience, age;

public:
    Employee() {}
    ~Employee() {}

    void inputData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Code: ";
        cin >> code;
        cout << "Enter Designation: ";
        cin.ignore();
        getline(cin, designation);
        cout << "Enter Experience: ";
        cin >> experience;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
        cout << "Designation: " << designation << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Employee emp;
    emp.inputData();
    emp.displayData();
    return 0;
}
