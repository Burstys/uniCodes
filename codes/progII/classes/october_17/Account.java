package october_17;

public class Account{
    private double balance;

    public double getBalance() {
        return balance;
    }

    public void deposit(double balance) {
        this.balance += balance;
    }

    public double withdraw(double n) throws InsufficientBalanceException{
        if (n <= balance){
            balance -= n;
            System.out.println("New balance: "+ balance);
            return n;
        }
        else{
            throw new InsufficientBalanceException("Isuficient balance", balance);
        }
    }  
}


