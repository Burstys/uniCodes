package July_18;

public class DayLaborer extends Employee{  
    private double dailySalary;
    private int activeDays;

    public double getDailySalary(){
        return dailySalary;
    }
    
    public void setDailySalary(double dailySalary) {
        this.dailySalary = dailySalary;
    }

    public int getActiveDays(){
        return activeDays;
    }
    
    public void setActiveDays(int activeDays) {
        this.activeDays = activeDays;
    }

    public DayLaborer(){
        super();
        this.dailySalary = 0;
        this.activeDays = 0;
    }

    public DayLaborer(int id, String name, double dailySalary, int activeDays){
        super(id, name);
        this.dailySalary = dailySalary;
        this.activeDays = activeDays;
    }

    public double calculateSalary(double dailySalary, int activeDays){
        return dailySalary * activeDays;
    }
    public double calculateSalary(double dailySalary){
        return 0;
    }

}
