package august_15;

public class MainAccount extends Accounts implements Taxable{
    public MainAccount(){
        super();
    }
    
    public MainAccount(double balance){
        super(balance);
    }
    
    @Override
    public double calculateTaxes(){
        return 21.0;
    }
}
