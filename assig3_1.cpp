#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double earning, bonus;

public:
    void inputData() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter earning: ";
        cin >> earning;
    }

    void computeBonus() {
        bonus = (earning >= 2000) ? 0.10 * earning : 0;
    }

    void displayData() {
        cout << "Name: " << name << "\nBonus: Rs. " << bonus << endl;
    }
};

int main() {
    Employee e;
    e.inputData();
    e.computeBonus();
    e.displayData();
    return 0;
}
