import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Question14 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        try {
            PrintWriter pw = new PrintWriter(new File("Sample.txt"));
            pw.write("This is part of Assessment - 3\nAbhinav Dinesh Srivatsa\n21BDS0340");
            pw.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        s.close();
    }
}
