#include <iostream>
using namespace std;

class DepartmentStore {
private:
    int miners, toasters, fans;
    double totalAmount;

public:
    void inputData() {
        cout << "Enter the number of miners: ";
        cin >> miners;
        cout << "Enter the number of toasters: ";
        cin >> toasters;
        cout << "Enter the number of fans: ";
        cin >> fans;
    }

    void calculateAmount() {
        double minerCost = miners * 1500 * 0.95;
        double toasterCost = toasters * 200 * 0.90;
        double fanCost = fans * 450 * 0.85;
        totalAmount = (minerCost + toasterCost + fanCost) * 1.10;
    }

    void displayAmount() {
        cout << "Total amount to be paid: Rs. " << totalAmount << endl;
    }
};

int main() {
    DepartmentStore store;
    store.inputData();
    store.calculateAmount();
    store.displayAmount();
    return 0;
}
