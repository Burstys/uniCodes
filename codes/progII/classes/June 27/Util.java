public class Util {

    public static boolean Even(int number){
        if (number%2 == 0){
            return true;
        }
        else {
            return false;
        }
    }

    public static boolean Negative(int number){
        if (number < 0){
            return true;
        }
        else {
            return false;
        }
    }

    public static double Bigger(double number1, double number2){
        if (number1 < number2){
            return number2;
        }
        else {
            return number1;
        }
    }

    public static int Bigger(int... numbers)  {
        int i = -1;
        for (int j = 0; j < numbers.length; j++){
            if (numbers[j]>i){
                i = numbers[j];
            }
        }
        return i;
    }  
}
