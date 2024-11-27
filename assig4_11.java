import java.util.HashSet;

public class PerfectString {
    public static boolean isPerfectString(String input) {
        HashSet<Character> uniqueChars = new HashSet<>();
        for (char c : input.toCharArray()) {
            if (!uniqueChars.add(c)) {
                return false;
            }
        }
        return
