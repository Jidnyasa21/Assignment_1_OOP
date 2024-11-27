#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex multiply(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 2), c2(1, 7);
    Complex result = c1.multiply(c2);

    cout << "Multiplication Result: ";
    result.display();
    return 0;
}
