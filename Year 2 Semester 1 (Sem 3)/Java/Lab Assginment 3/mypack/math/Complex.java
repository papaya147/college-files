package mypack.math;

public class Complex {
    double a, b;

    public Complex(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public Complex add(Complex c) {
        return new Complex(a + c.a, b + c.b);
    }

    public Complex sub(Complex c) {
        return new Complex(a - c.a, b - c.b);
    }

    public String toString() {
        return Double.toString(a) + "+" + Double.toString(b) + "i";
    }
}
