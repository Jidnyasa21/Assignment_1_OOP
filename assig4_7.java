import java.util.Random;

public class CrapsGame {
    enum Outcome { WIN, LOSE, CONTINUE }

    public static Outcome playCraps() {
        Random rand = new Random();
        int die1 = rand.nextInt(6) + 1;
        int die2 = rand.nextInt(6) + 1;
        int sum = die1 + die2;

        if (sum == 7 || sum == 11) return Outcome.WIN;
        if (sum == 2 || sum == 3 || sum == 12) return Outcome.LOSE;
        return Outcome.CONTINUE;
    }

    public static void main(String[] args) {
        System.out.println(playCraps());
    }
}
