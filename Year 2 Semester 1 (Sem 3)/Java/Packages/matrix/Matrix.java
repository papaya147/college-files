package matrix;

import java.util.Scanner;

public class Matrix {

  public int[][] getMatrix(Scanner s, int size) {
    int matrix[][] = new int[size][size];
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        System.out.print("Enter row " + x + " col " + y + ": ");
        matrix[x][y] = s.nextInt();
      }
    }
    return matrix;
  }

  public int[][] addMatrices(int mat1[][], int mat2[][], int size) {
    int out[][] = new int[size][size];
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        out[x][y] = mat1[x][y] + mat2[x][y];
      }
    }
    return out;
  }

  public int[][] multiplyMatrices(int mat1[][], int mat2[][], int size) {
    int out[][] = new int[size][size];
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        for (int z = 0; z < size; z++) {
          out[x][y] += mat1[x][z] * mat2[z][y];
        }
      }
    }
    return out;
  }

  public void displayMatrix(int mat[][], int size) {
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        System.out.print(mat[x][y] + " ");
      }
      System.out.println("");
    }
  }

  public void doStuff(Scanner s) {
    System.out.println("Enter size: ");
    int size = s.nextInt();
    System.out.println("Matrix 1: ");
    int matrix1[][] = getMatrix(s, size);
    System.out.println("Matrix 2: ");
    int matrix2[][] = getMatrix(s, size);
    System.out.println("");
    int sum[][] = addMatrices(matrix1, matrix2, size);
    int prod[][] = multiplyMatrices(matrix1, matrix2, size);
    System.out.println("Sum: ");
    displayMatrix(sum, size);
    System.out.println("Product: ");
    displayMatrix(prod, size);
  }
}
