import java.util.Scanner;

public class Question7 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String word = s.next();
        StringBuilder sb = new StringBuilder(word);
        String rep = s.next();
        int t1 = s.nextInt(), f1 = s.nextInt();
        int t2 = s.nextInt(), f2 = s.nextInt();
        sb.replace(t1, f1, rep);
        System.out.println(word + "\n" + sb);
        sb.delete(t2, f2);
        System.out.println(sb);
        s.close();
    }
}
