public class Invoice {
    private String partNumber;
    private String partDescription;
    private int quantity;
    private double pricePerItem;

    public Invoice(String partNumber, String partDescription, int quantity, double pricePerItem) {
        this.partNumber = partNumber;
        this.partDescription = partDescription;
        setQuantity(quantity);
        setPricePerItem(pricePerItem);
    }

    public void setQuantity(int quantity) {
        this.quantity = (quantity > 0) ? quantity : 0;
    }

    public void setPricePerItem(double pricePerItem) {
        this.pricePerItem = (pricePerItem > 0) ? pricePerItem : 0.0;
    }

    public double getInvoiceAmount() {
        return quantity * pricePerItem;
    }

    public void displayInvoice() {
        System.out.println("Part Number: " + partNumber);
        System.out.println("Description: " + partDescription);
        System.out.println("Quantity: " + quantity);
        System.out.println("Price Per Item: Rs. " + pricePerItem);
        System.out.println("Invoice Amount: Rs. " + getInvoiceAmount());
    }

    public static void main(String[] args) {
        Invoice invoice = new Invoice("A123", "Hammer", 5, 150);
        invoice.displayInvoice();
    }
}
