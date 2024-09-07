import java.util.Scanner;

public class EulersPhi {
    public static int phi(int n) {
        float result = n;
        for (int x = 2; x * x <= n; x++) {
            if (n % x == 0) {
                while (n % x == 0)
                    n /= x;
                result *= (1.0 - 1.0 / (float) x);
            }
        }
        if (n > 1)
            result -= result / n;
        return (int) result;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        System.out.println(phi(n));
        s.close();
    }
}
