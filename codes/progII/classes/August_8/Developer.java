package August_8;

public class Developer implements IEmployee{
    private double salary;
    private String name;
    private int age;

    public Developer(){
        salary = 0.0;
        name = "";
        age = 0;
    }

    public Developer(double salary){
        name = "";
        age = 0;
        this.salary = salary;
    }

    public Developer(String name, int age, double salary){
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    public String getName(){
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge(){
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public double getSalary(){
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    @Override
    public double calculateSalary(double salary) {
        this.salary = salary;
        return this.salary;
    }
}
