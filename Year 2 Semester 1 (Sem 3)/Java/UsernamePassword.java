import java.util.Scanner;

public class UsernamePassword {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String username = s.nextLine().trim();
        String password = s.nextLine().trim();
        String confpass = s.nextLine().trim();

        if (username.length() < 8)
            System.out.println("Invalid username length.");
        else if (password.length() < 8)
            System.out.println("Invalid password length.");
        else {
            for (int x = 0; x < username.length(); x++)
                if (username.charAt(x) == ' ')
                    System.out.println("Username must not contain spaces.");
            for (int x = 0; x < password.length(); x++)
                if (password.charAt(x) == ' ')
                    System.out.println("Password must not contain spaces.");
            if (!password.equals(confpass))
                System.out.println("Passwords don't match.");
            outer: for (int x = 3; x < username.length(); x++)
                for (int y = 3; y < password.length(); y++)
                    if (username.substring(x - 3, x).equals(password.substring(y - 3, y))) {
                        System.out.println("Password cannot contain username.");
                        break outer;
                    }
        }

        s.close();
    }
}