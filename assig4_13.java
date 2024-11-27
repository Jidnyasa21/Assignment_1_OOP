interface Function {
    int evaluate(int x);
}

class Half implements Function {
    @Override
    public int evaluate(int x) {
        return x / 2;
    }
}

public class FunctionDemo {
    public static int[] halfArray(int[] arr) {
        Half half = new Half();
        int[] result = new int[arr.length];

        for (int i = 0; i < arr.length; i++) {
            result[i] = half.evaluate(arr[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] values = {10, 20, 30, 40, 50};
        int[] halfValues = halfArray(values);

        System.out.println("Original array: ");
        for (int val : values) {
            System.out.print(val + " ");
        }

        System.out.println("\nHalved array: ");
        for (int val : halfValues) {
            System.out.print(val + " ");
        }
    }
}
