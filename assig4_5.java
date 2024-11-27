import java.util.Scanner;

public class GasMileage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double totalMiles = 0;
        double totalGallons = 0;
        double miles, gallons;

        while (true) {
            System.out.print("Enter miles driven (-1 to end): ");
            miles = sc.nextDouble();
            if (miles == -1) break;

            System.out.print("Enter gallons used: ");
            gallons = sc.nextDouble();

            totalMiles += miles;
            totalGallons += gallons;

            double mpg = miles / gallons;
            System.out.println("Miles per gallon for this trip: " + mpg);
        }

        double overallMPG = totalMiles / totalGallons;
        System.out.println("Overall miles per gallon: " + overallMPG);
    }
}
