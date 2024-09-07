import java.util.Scanner;

public class Question2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];
        for (int x = 0; x < n; x++)
            arr[x] = s.nextInt();
        int diff, num1 = 0, num2 = 0, min = Integer.MAX_VALUE;
        for (int x = 0; x < n - 1; x++)
            for (int y = x + 1; y < n; y++) {
                diff = Math.abs(arr[x] + arr[y]);
                if (diff < min) {
                    min = diff;
                    num1 = arr[x];
                    num2 = arr[y];
                }
            }
        System.out.println(num1 + "\n" + num2);
        s.close();
    }
}
