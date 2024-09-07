import java.util.Scanner;

public class Question10 {
    public static int mult(int a, int b) {
        return a * b;
    }

    public static float mult(float a, float b) {
        return a * b;
    }

    public static double mult(double a, double b) {
        return a * b;
    }

    public static int sub(int a, int b) {
        return a - b;
    }

    public static float sub(float a, float b) {
        return a - b;
    }

    public static double sub(double a, double b) {
        return a - b;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println(mult(s.nextInt(), s.nextInt()) + "\n" + mult(s.nextFloat(), s.nextFloat()) + "\n"
                + mult(s.nextDouble(), s.nextDouble()));
        System.out.println(sub(s.nextInt(), s.nextInt()) + "\n" + sub(s.nextFloat(), s.nextFloat()) + "\n"
                + sub(s.nextDouble(), s.nextDouble()));
        s.close();
    }
}
