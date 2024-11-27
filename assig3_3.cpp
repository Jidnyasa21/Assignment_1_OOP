#include <iostream>
#include <string>
using namespace std;

class TaxPayer {
private:
    string name;
    double income, tax;

public:
    void inputData() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter income: ";
        cin >> income;
    }

    void computeTax() {
        if (income <= 100000) tax = 0;
        else if (income <= 150000) tax = 0.10 * (income - 100000);
        else if (income <= 200000) tax = 5000 + 0.20 * (income - 150000);
        else tax = 15000 + 0.30 * (income - 200000);
    }

    void displayData() {
        cout << "Name: " << name << "\nTax: Rs. " << tax << endl;
    }
};

int main() {
    TaxPayer t;
    t.inputData();
    t.computeTax();
    t.displayData();
    return 0;
}
