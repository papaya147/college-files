import java.util.Scanner;

import printstring.PrintString;

public class Question12 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        PrintString ps = new PrintString();
        ps.display(s.next());
        s.close();
    }
}
