import java.util.Scanner;
import java.util.ArrayList;

public class Stobogrammatic {
    public static ArrayList<String> numdef(int n, int length) {
        ArrayList<String> result = new ArrayList<String>();
        if (n == 0) {
            result.add("");
            return result;
        }
        if (n == 1) {
            result.add("0");
            result.add("1");
            result.add("8");
            return result;
        }

        ArrayList<String> middles = numdef(n - 2, length);
        for (String middle : middles) {
            if (n != length)
                result.add("0" + middle + "0");
            result.add("1" + middle + "1");
            result.add("6" + middle + "9");
            result.add("8" + middle + "8");
            result.add("9" + middle + "6");
        }

        return result;
    }

    public static ArrayList<String> strobogrammatic(int n) {
        return numdef(n, n);
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (String i : strobogrammatic(n))
            System.out.println(i);
        s.close();
    }
}