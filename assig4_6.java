public class CarModel {
    public static String getCarModel(String category) {
        switch (category.toUpperCase()) {
            case "SUV": return "TATA SAFARI";
            case "SEDAN": return "TATA INDIGO";
            case "ECONOMY": return "TATA INDICA";
            case "MINI": return "TATA NANO";
            default: return "Unknown Category";
        }
    }

    public static void main(String[] args) {
        System.out.println(getCarModel("SUV"));
        System.out.println(getCarModel("SEDAN"));
        System.out.println(getCarModel("MINI"));
    }
}
