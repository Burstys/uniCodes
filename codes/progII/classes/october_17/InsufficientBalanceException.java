package october_17;

public class InsufficientBalanceException extends Exception {
    private double balance;

    public InsufficientBalanceException(String message, double balance) {
        super(message);
        this.balance = balance;
    }

    public double getBalance(){
        return balance;
    }
}
