import java.util.regex.*;

public class PasswordValidator {
    public static boolean validatePassword(String password) {
        String pattern = "^(?=.*[a-z])(?=.*\\d)[a-z0-9]{5,12}$";
        return password.matches(pattern);
    }

    public static void main(String[] args) {
        String password = "abc123";
        System.out.println("Password valid: " + validatePassword(password));
    }
}
