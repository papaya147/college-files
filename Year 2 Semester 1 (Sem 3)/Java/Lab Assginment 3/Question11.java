import java.util.Scanner;

public class Question11 {
    public static void main(String[] args) throws FirstDigitNotSameException {
        Scanner s = new Scanner(System.in);
        int a = s.nextInt(), b = s.nextInt();
        s.close();
        while (a / 10 != 0)
            a /= 10;
        while (b / 10 != 0)
            b /= 10;
        if (a != b)
            throw new FirstDigitNotSameException("First digits of numbers are not same");
    }
}

class FirstDigitNotSameException extends Exception {
    FirstDigitNotSameException(String s) {
        super(s);
    }
}