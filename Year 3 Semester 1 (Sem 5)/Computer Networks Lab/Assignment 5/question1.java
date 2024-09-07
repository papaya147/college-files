import java.util.Scanner;

public class question1 {
    public static String integerToBits(int n) {
        String bin = "";
        while (n != 0) {
            bin = Integer.toString(n % 2) + bin;
            n /= 2;
        }
        return bin;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String ip = s.nextLine().trim();
        int netId = Integer.parseInt(ip.split("\\.")[0]);
        String bits = integerToBits(netId);
        char ipClass = '\0';
        if (bits.startsWith("0"))
            ipClass = 'A';
        else if (bits.startsWith("10"))
            ipClass = 'B';
        else if (bits.startsWith("110"))
            ipClass = 'C';
        else if (bits.startsWith("1110"))
            ipClass = 'C';
        else if (bits.startsWith("1111"))
            ipClass = 'E';
        System.out.println("IP is class " + ipClass);
        s.close();
    }
}