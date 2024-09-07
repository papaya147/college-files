import java.util.Scanner;

public class Permutation {
    public static String sort(String s) {
        char[] letters = s.toCharArray();
        for (int x = 0; x < letters.length - 1; x++)
            for (int y = x + 1; y < letters.length; y++)
                if (letters[x] > letters[y]) {
                    char temp = letters[x];
                    letters[x] = letters[y];
                    letters[y] = temp;
                }
        return new String(letters);
    }

    public static void permutePrint(String s){
        for(int x = 0; x < s.length())
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String str = s.nextLine().trim();
        s.close();
        String sorted = sort(str);
        permutePrint(sorted);
    }
}
