package august_15;

public class TaxManager{
    
    static double calculate(Taxable... taxableAccounts) {
        double totalTaxes = 0.0;
        
        for (Taxable taxable : taxableAccounts) {
            totalTaxes += taxable.calculateTaxes();
        }
        
        return totalTaxes;
    }
}
