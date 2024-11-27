#include <iostream>
using namespace std;

class Cube;

class Cuboid {
private:
    double length, width, height;

public:
    void setDimensions(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    double calculateArea() {
        return 2 * (length * width + width * height + height * length);
    }

    friend class Cube;
};

class Cube {
public:
    void convertToCube(Cuboid& c) {
        double side = c.length;
        c.width = side;
        c.height = side;
    }
};

int main() {
    Cuboid cuboid;
    Cube cube;

    cuboid.setDimensions(4.0, 5.0, 6.0);
    cout << "Cuboid Area: " << cuboid.calculateArea() << endl;

    cube.convertToCube(cuboid);
    cout << "Converted Cube Area: " << cuboid.calculateArea() << endl;
    return 0;
}
