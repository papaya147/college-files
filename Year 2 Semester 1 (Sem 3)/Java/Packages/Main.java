import dispinput.DispInput;
import dispstring.DispString;
import java.util.Scanner;
import matrix.Matrix;

public class Main {

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    (new DispString()).displayString();
    (new DispInput()).displayInput(s);
    (new Matrix()).doStuff(s);
    s.close();
  }
}
