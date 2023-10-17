package october_17;

public class TestException{
    public static void main(String[] args) {
        System.out.println("beginning");
        metodo1();
        System.out.println("ending");
    }

    static void metodo1(){
        System.out.println("m1 beginning");
        metodo2();
        System.out.println("m1 ending");
    }

    static void metodo2(){
        System.out.println("m2 beginning");
        int[] array = new int[10];
        for(int i=0; i< array.length; i++){
            array[i] = i;
            System.out.println(i);
        }
        System.out.println("m2 ending");
    }
}