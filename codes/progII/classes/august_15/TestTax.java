package august_15;

public class TestTax {
    public static void main(String[] args) {
        MainAccount mainAccount = new MainAccount();
        SavingsAccount savingsAccount = new SavingsAccount();
        LifeInsurance lifeInsurance = new LifeInsurance(1000.0);

        double totalTaxes = TaxManager.calculate(mainAccount, lifeInsurance);
        System.out.println("Total taxes: " + totalTaxes);
    }
}

