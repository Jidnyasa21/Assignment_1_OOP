#include <iostream>
#include <string>
using namespace std;

class Payroll {
private:
    string name, designation;
    int code, accountNumber;
    string dateOfJoining;
    double basicPay, DA, HRA, CCA, deductions, netPay;

public:
    Payroll() {}
    ~Payroll() {}

    void inputData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee Code: ";
        cin >> code;
        cout << "Enter Designation: ";
        cin.ignore();
        getline(cin, designation);
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Date of Joining: ";
        cin.ignore();
        getline(cin, dateOfJoining);
        cout << "Enter Basic Pay: ";
        cin >> basicPay;
        cout << "Enter Deductions: ";
        cin >> deductions;

        DA = 0.10 * basicPay;
        HRA = 0.15 * basicPay;
        CCA = 0.05 * basicPay;
        netPay = basicPay + DA + HRA + CCA - deductions;
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Employee Code: " << code << endl;
        cout << "Designation: " << designation << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Date of Joining: " << dateOfJoining << endl;
        cout << "Net Pay: Rs. " << netPay << endl;
    }
};

int main() {
    Payroll p;
    p.inputData();
    p.displayData();
    return 0;
}
