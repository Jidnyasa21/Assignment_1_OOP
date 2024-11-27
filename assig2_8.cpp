#include <iostream>
#include <string>
using namespace std;

class Personnel {
private:
    string name, dob, bloodGroup, address, insurancePolicy, drivingLicense;
    double height, weight;
    long telephoneNumber;

public:
    Personnel() {}
    ~Personnel() {}

    void inputData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Date of Birth: ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Height (in cm): ";
        cin >> height;
        cout << "Enter Weight (in kg): ";
        cin >> weight;
        cout << "Enter Contact Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;
        cout << "Enter Insurance Policy Number: ";
        cin.ignore();
        getline(cin, insurancePolicy);
        cout << "Enter Driving License Number: ";
        getline(cin, drivingLicense);
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Insurance Policy Number: " << insurancePolicy << endl;
        cout << "Driving License Number: " << drivingLicense << endl;
    }
};

int main() {
    Personnel p;
    p.inputData();
    p.displayData();
    return 0;
}
