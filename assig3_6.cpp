#include <iostream>
using namespace std;

class ClassA;
class ClassB;

class ClassA {
private:
    double numA;

public:
    void setData(double a) { numA = a; }
    friend double calculateMean(ClassA, ClassB);
};

class ClassB {
private:
    double numB;

public:
    void setData(double b) { numB = b; }
    friend double calculateMean(ClassA, ClassB);
};

double calculateMean(ClassA a, ClassB b) {
    return (a.numA + b.numB) / 2.0;
}

int main() {
    ClassA a;
    ClassB b;

    a.setData(12.5);
    b.setData(15.5);

    cout << "Mean: " << calculateMean(a, b) << endl;
    return 0;
}
