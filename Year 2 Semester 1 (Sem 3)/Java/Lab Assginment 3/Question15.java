import java.io.File;
import java.util.Scanner;

public class Question15 {
    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(new File("Sample.txt"));
            while (s.hasNext())
                System.out.println(s.nextLine().trim());
            s.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
