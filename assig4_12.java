import java.util.Scanner;

public class PatternSearch {
    public static int countPatternOccurrences(int start, int end, String pattern) {
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (String.valueOf(i).contains(pattern)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter range (start end): ");
        int start = sc.nextInt();
        int end = sc.nextInt();

        System.out.print("Enter pattern: ");
        String pattern = sc.next();

        int occurrences = countPatternOccurrences(start, end, pattern);
        System.out.println("The number of times " + pattern + " occurred between " + start + " and " + end + " is: " + occurrences);
    }
}
