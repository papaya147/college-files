import java.util.Scanner;

import mypack.math.Complex;

public class Question13 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Complex c1 = new Complex(s.nextDouble(), s.nextDouble());
        Complex c2 = new Complex(s.nextDouble(), s.nextDouble());
        Complex sum = c1.add(c2);
        Complex diff = c1.sub(c2);
        System.out.println("Sum: " + sum.toString());
        System.out.println("Difference: " + diff.toString());
        s.close();
    }
}