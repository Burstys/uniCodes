package october_17;

public class TestAccount {
    public static void main(String[] args) {
        Account account = new Account();
        account.deposit(1000);
        try{
            account.withdraw(10000);
        }catch (InsufficientBalanceException e) {
            System.out.println("Exception:" + e.getMessage());
            System.out.println("Current balance: " + e.getBalance());
        }
    }
}