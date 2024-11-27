import java.util.Scanner;

public class DrivingCost {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter total miles driven per day: ");
        double miles = sc.nextDouble();
        System.out.print("Enter cost per gallon of gasoline: ");
        double costPerGallon = sc.nextDouble();
        System.out.print("Enter average fees per day: ");
        double avgFees = sc.nextDouble();
        System.out.print("Enter tolls per day: ");
        double tolls = sc.nextDouble();

        double totalCost = (miles / 25) * costPerGallon + avgFees + tolls;
        System.out.println("Your daily driving cost is: Rs. " + totalCost);
    }
}
