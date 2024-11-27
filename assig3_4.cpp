#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name, accountType;
    int accountNumber;
    double balance;

public:
    void initialize() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter account type: ";
        cin.ignore();
        getline(cin, accountType);
        cout << "Enter balance: ";
        cin >> balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient balance!" << endl;
    }

    void displayDetails() {
        cout << "Name: " << name << "\nAccount Number: " << accountNumber
             << "\nAccount Type: " << accountType << "\nBalance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount b;
    b.initialize();
    b.deposit(500);
    b.withdraw(300);
    b.displayDetails();
    return 0;
}
