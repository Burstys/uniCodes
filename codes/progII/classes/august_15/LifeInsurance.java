package august_15;

public class LifeInsurance implements Taxable{
    private double membership;

    public double getMembership(){
        return membership;
    }

    public void setMembership(double Membership){
        this.membership = Membership;
    }

    public LifeInsurance(){
        membership = 0.0;
    }

    public LifeInsurance(double membership){
        this.membership = membership;
    }

    @Override
    public double calculateTaxes(){
        return 0.01*this.getMembership();
    }
}
