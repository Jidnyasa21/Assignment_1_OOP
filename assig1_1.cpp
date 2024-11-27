#include <iostream>
using namespace std;

class PostalService {
private:
    double weight;
    double cost;

public:
    void inputWeight() {
        cout << "Enter the weight of the letter (in grams): ";
        cin >> weight;
    }

    void calculateCost() {
        if (weight <= 50) {
            cost = 0.50 * (weight / 10);
        } else if (weight <= 150) {
            cost = 0.50 * 5 + 0.40 * ((weight - 50) / 10);
        } else if (weight <= 400) {
            cost = 0.50 * 5 + 0.40 * 10 + 0.25 * ((weight - 150) / 10);
        } else {
            cost = 25 * (weight / 1000);
        }
    }

    void displayCost() {
        cout << "The postage cost is: Rs. " << cost << endl;
    }
};

int main() {
    PostalService p;
    p.inputWeight();
    p.calculateCost();
    p.displayCost();
    return 0;
}
