import java.util.Scanner;

public class SimpleSieve {
    public static boolean[] sieve(int n) {
        boolean prime[] = new boolean[n - 1];
        for (int x = 2; x < n + 1; x++) {
            if (prime[x - 2])
                continue;
            for (int y = x + 1; y < n + 1; y++)
                if (y % x == 0)
                    prime[y - 2] = true;
        }
        return prime;
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        boolean prime[] = sieve(n);
        for (int x = 2; x < n + 1; x++)
            if (!prime[x - 2])
                System.out.println(x);
        s.close();
    }
}
