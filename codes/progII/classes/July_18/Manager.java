package July_18;

public class Manager extends Employee{
    private double monthlySalary;

    public double getMonthlySalary(){
        return monthlySalary;
    }
    
    public void setMonthlySalary(double monthlySalary) {
        this.monthlySalary = monthlySalary;
    }

    public Manager(){
        super();
        this.monthlySalary = 0;
    }

    public Manager(int id, String name, double monthlySalary){
        super(id, name);
        this.monthlySalary = monthlySalary;
    }

    public double calculateSalary(double monthlySalary){
        return monthlySalary * 1.1;
    }

    public double calculateSalary(double monthlySalary, int nada){
        return 0;
    }
}
