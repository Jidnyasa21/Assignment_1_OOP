#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int emp_id;
    string emp_name;
    int age;

public:
    void setData(int id, string name, int a) {
        emp_id = id;
        emp_name = name;
        age = a;
    }

    int getId() const { return emp_id; }

    void displayData() const {
        cout << "ID: " << emp_id << "\nName: " << emp_name << "\nAge: " << age << endl;
    }
};

int main() {
    Employee employees[10];
    for (int i = 0; i < 10; ++i) {
        employees[i].setData(100 + i, "Employee_" + to_string(i + 1), 25 + i);
    }

    int searchId;
    cout << "Enter Employee ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < 10; ++i) {
        if (employees[i].getId() == searchId) {
            employees[i].displayData();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee not found!" << endl;
    }
    return 0;
}
