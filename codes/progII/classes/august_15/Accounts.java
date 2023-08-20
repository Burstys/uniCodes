package august_15;

public abstract class Accounts {
    private double balance;

    public Accounts(){
        balance = 0.0;
    }

    public Accounts(double balance){
        this.balance = balance;
    }

    public void deposit(double amount){
        this.balance += amount;
    }

    public void withdraw(double amount){
        if (balance >= amount){
            this.balance -= amount;
        }
        else{
            System.out.println("Saldo insuficiente: " + getBalance());
        }
    }

    public double getBalance(){
        return this.balance;
    }
}

