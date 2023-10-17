package october_3;

public class GenericWordSwapper {
    public static <T> void swapElements(T[] array, int i, int j) {
        if (i >= 0 && i < array.length && j >= 0 && j < array.length) {
            T aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        } else {
            System.out.println("Incorrect indexes");
        }
    }
}
