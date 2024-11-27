#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    vector<int> elements;

public:
    friend istream& operator>>(istream& in, Vector& v) {
        int size;
        cout << "Enter size of vector: ";
        in >> size;

        v.elements.resize(size);
        cout << "Enter elements: ";
        for (int i = 0; i < size; ++i) {
            in >> v.elements[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Vector& v) {
        out << "[ ";
        for (int el : v.elements) {
            out << el << " ";
        }
        out << "]";
        return out;
    }

    Vector operator+(const Vector& v) const {
        Vector result;
        result.elements.resize(elements.size());
        for (size_t i = 0; i < elements.size(); ++i) {
            result.elements[i] = elements[i] + v.elements[i];
        }
        return result;
    }
};

int main() {
    Vector v1, v2;
    cin >> v1 >> v2;
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    Vector v3 = v1 + v2;
    cout << "Sum of Vectors: " << v3 << endl;

    return 0;
}
