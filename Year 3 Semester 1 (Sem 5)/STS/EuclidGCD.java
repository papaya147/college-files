import java.util.Scanner;

public class EuclidGCD {
    public static int gcd(int x, int y) {
        if (x == y || y == 1)
            return y;
        return x > y ? gcd(y, x - y) : gcd(x, y - x);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int y = s.nextInt();
        s.close();

        int gcd = gcd(x, y);
        System.out.println(gcd);
    }
}