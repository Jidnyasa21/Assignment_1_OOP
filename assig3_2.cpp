#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    int calls;
    double bill;

public:
    void inputData() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter number of calls: ";
        cin >> calls;
    }

    void computeBill() {
        if (calls <= 100) bill = 200;
        else if (calls <= 150) bill = 200 + (calls - 100) * 0.60;
        else if (calls <= 200) bill = 200 + 50 * 0.60 + (calls - 150) * 0.50;
        else bill = 200 + 50 * 0.60 + 50 * 0.50 + (calls - 200) * 0.40;
    }

    void displayData() {
        cout << "Name: " << name << "\nBill: Rs. " << bill << endl;
    }
};

int main() {
    Customer c;
    c.inputData();
    c.computeBill();
    c.displayData();
    return 0;
}
