import java.util.Scanner;

public class question2 {
    public static int bitsToInteger(String bits) {
        int sum = 0;
        for (int x = 0; x < bits.length(); x++)
            sum += (bits.charAt(x) - '0') * Math.pow(2, bits.length() - x - 1);
        return sum;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String ip = s.nextLine().trim();
        String bytes[] = ip.split("(?<=\\G.{8})");
        int c = 0;
        for (String str : bytes)
            if (c++ == 0)
                System.out.print(bitsToInteger(str));
            else
                System.out.print("." + bitsToInteger(str));
        System.out.println("");
        s.close();
    }
}
