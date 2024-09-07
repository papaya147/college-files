import java.util.Scanner;

public class question4 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int c = s.nextInt();
        float f = (float) c * 9 / 5 + 32;
        System.out.println(f);
        s.close();
    }
}