import java.util.Scanner;

public class Question6 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int a1 = s.nextInt(), a2 = s.nextInt(), b1 = s.nextInt(), b2 = s.nextInt();
        System.out.println(a1 + "+" + a2 + "i");
        System.out.println(b1 + "+" + b2 + "i");
        System.out.println((a1 + b1) + "+" + (a2 + b2) + "i");
        System.out.println((a1 - b1) + "+" + (a2 - b2) + "i");
        s.close();
    }
}
