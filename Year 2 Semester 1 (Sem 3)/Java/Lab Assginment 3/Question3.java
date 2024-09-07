import java.util.Scanner;

public class Question3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int mat[][] = new int[n][n];
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                mat[x][y] = s.nextInt();
        for (int x = 0; x < n; x++) {
            int temp = mat[x][n - x - 1];
            mat[x][n - x - 1] = mat[x][x];
            mat[x][x] = temp;
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++)
                System.out.print(mat[x][y] + " ");
            System.out.println("");
        }
        s.close();
    }
}
