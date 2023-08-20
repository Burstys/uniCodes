package August_8;

public class Manager implements IEmployee{
    private double salary;

    public Manager(){
        salary=0.0;
    }

    public Manager(double salary){
        this.salary = salary;
    }

    public double getSalary(){
        return salary;
    }

    public void setSalary(double salary){
        this.salary = salary;
    }

    @Override
    public double calculateSalary(double salary){
        this.salary = salary*1.1;
        return this.salary;
    }

}
