package august_15;

public class Circle implements CalculableArea{
    private double radius;

    public Circle(){
        radius = 0.0;
    }

    public Circle(double radius){
        this.radius = radius;
    }

    public double getRadius(){
        return radius;
    }

    public void setRadius(double radius){
        this.radius = radius;
    }

    @Override
    public double calculateArea(){
        return radius*radius*3.1415; 
    }
    
}
