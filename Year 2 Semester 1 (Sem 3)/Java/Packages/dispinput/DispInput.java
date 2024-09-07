package dispinput;

import java.util.Scanner;

public class DispInput {

  public void displayInput(Scanner s) {
    System.out.print("Enter string: ");
    String str = s.next();
    System.out.println(str);
  }
}
