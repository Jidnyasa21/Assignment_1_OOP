#include <iostream>
using namespace std;

class Integer {
private:
    int value;

public:
    Integer(int v = 0) : value(v) {}

    friend Integer operator+(const Integer& a, const Integer& b) {
        return Integer(a.value + b.value);
    }

    void display() const {
        cout << value << endl;
    }
};

int main() {
    Integer i1(5), i2(10);

    Integer sum = i1 + i2;
    cout << "Sum: ";
    sum.display();

    return 0;
}
