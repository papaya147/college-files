import java.util.Scanner;

public class question3 {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int y = s.nextInt();
        x += y;
        y = x - y;
        x -= y;
        System.out.println(x + "\n" + y);
        s.close();
    }
}