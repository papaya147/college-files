import java.util.Scanner;

public class Question4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int m = s.nextInt(), n = s.nextInt();
        int mat[][] = new int[m][n];
        for (int x = 0; x < m; x++)
            for (int y = 0; y < n; y++)
                mat[x][y] = s.nextInt();
        int sum[] = new int[m];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                System.out.print(mat[y][x] + " ");
                sum[y] += mat[y][x];
            }
            System.out.println("");
        }
        System.out.println("----");
        for (int x = 0; x < m; x++)
            System.out.print(sum[x] + " ");
        s.close();
    }
}
