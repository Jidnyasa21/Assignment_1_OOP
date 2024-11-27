public class Date {
    private int month;
    private int day;
    private int year;

    public Date(int month, int day, int year) {
        this.month = month;
        this.day = day;
        this.year = year;
    }

    public void displayDate() {
        System.out.println(month + "/" + day + "/" + year);
    }

    public static void main(String[] args) {
        Date date = new Date(12, 25, 2022);
        date.displayDate();
    }
}
