package october_10;
import java.util.Scanner;

public class Division extends Exception{
    public static void main(String[] args){
        try (Scanner scanner = new Scanner(System.in)) {
            while(true){
                try{
                    System.out.println("Dividend: ");
                    int dividend = Integer.parseInt(scanner.nextLine());

                    System.out.println("Divisor: ");
                    int divisor = Integer.parseInt(scanner.nextLine());

                    if(divisor == 0){
                        System.out.println("Error, cannot divide by zero\n");
                    }
                    else{
                        int result = dividend/divisor;
                        System.out.println("Result: " + result);
                        break;
                    }
                }
                catch(Exception e){
                    System.out.println("Invalid dividend, please type again\n ");
                }
                
            }
        }
    }
    
}
