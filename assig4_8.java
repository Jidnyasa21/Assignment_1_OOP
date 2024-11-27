package FigPackage;

abstract class Figure {
    protected double r, a, v, pi = 3.1428;

    public abstract void calcArea();
    public abstract void calcVolume();
    public abstract void dispArea();
    public abstract void dispVolume();
}

class Cone extends Figure {
    private double s, h;

    public Cone(double r, double s, double h) {
        this.r = r;
        this.s = s;
        this.h = h;
    }

    public void calcArea() {
        a = pi * r * s + pi * r * r;
    }

    public void calcVolume() {
        v = (pi * r * r * h) / 3;
    }

    public void dispArea() {
        System.out.println("Cone Area: " + a);
    }

    public void dispVolume() {
        System.out.println("Cone Volume: " + v);
    }
}

// Similar classes for Sphere and Cylinder would follow.

public class Demo {
    public static void main(String[] args) {
        Cone cone = new Cone(5, 5, 10);
        cone.calcArea();
        cone.calcVolume();
        cone.dispArea();
        cone.dispVolume();
    }
}

