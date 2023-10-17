package october_17;

import java.util.Scanner;

public class SecondQuestion {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("division");
        System.out.println("Dividend: ");
        int x = keyboard.nextInt();
        System.out.println("Divisor: ");
        int y = keyboard.nextInt();
        double r = x/y;
        System.out.println(r);
        keyboard.close();
    }
}
