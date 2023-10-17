package october_3;

public class GWSTest {
    public static void main(String[] args) {
        
        Integer[] array = {1, 2, 3, 4, 5};
        
        GenericWordSwapper.swapElements(array, 0, 2);
        for(int i=0; i<array.length; i++) {
            System.out.println(array[i]);
        }
    }
}
