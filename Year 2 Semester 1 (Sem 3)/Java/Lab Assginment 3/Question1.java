import java.util.Scanner;

public class Question1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (int x = 1; x <= n; x++) {
            for (int y = 0; y < x; y++)
                System.out.print("* ");
            System.out.println("");
        }
        s.close();
    }
}