public class Employee {
    private String firstName;
    private String lastName;
    private double monthlySalary;

    public Employee(String firstName, String lastName, double monthlySalary) {
        this.firstName = firstName;
        this.lastName = lastName;
        setMonthlySalary(monthlySalary);
    }

    public void setMonthlySalary(double monthlySalary) {
        this.monthlySalary = (monthlySalary > 0) ? monthlySalary : 0.0;
    }

    public double getYearlySalary() {
        return monthlySalary * 12;
    }

    public void giveSalaryHike() {
        monthlySalary += monthlySalary * 0.10;
    }

    public void displaySalary() {
        System.out.println("Yearly Salary for " + firstName + " " + lastName + ": Rs. " + getYearlySalary());
    }

    public static void main(String[] args) {
        Employee e1 = new Employee("John", "Doe", 2000);
        Employee e2 = new Employee("Jane", "Doe", 2500);

        e1.displaySalary();
        e2.displaySalary();

        e1.giveSalaryHike();
        e2.giveSalaryHike();

        e1.displaySalary();
        e2.displaySalary();
    }
}
