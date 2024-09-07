import java.util.Scanner;

public class Question5 {
   public static void main(String[] args) {
      Scanner s = new Scanner(System.in);
      String str = s.nextLine().trim();
      String words[] = str.split(" ");
      int count = 0;
      for (int x = 0; x < words.length - 1; x++) {
         boolean flag = true;
         for (int y = x + 1; y < words.length; y++)
            if (words[x].equals(words[y]))
               flag = false;
         if (flag)
            count++;
      }
      System.out.println(count + 1);
      s.close();
   }
}