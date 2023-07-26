package July_4;

public class Card {
    private int balance;

    /*public int getBalance(){
        return balance;
    }

    public void setBalance(int balance){
        this.balance = balance;
    }*/
    
    public Card(){
        this.balance = 10;
    }

    public Card(int Balance){
        this.balance = Balance;
    }

    void setBalance(int newBalance){
        this.balance += newBalance;
    }

    void useBalance(){
        this.balance -= 1;
    }
}
