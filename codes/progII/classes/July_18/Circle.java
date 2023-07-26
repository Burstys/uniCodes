package July_18;

public class Circle extends Point{
    private double radius;

    public Circle(){
        super(0, 0);
        this.radius = 1;
    }
    
    public Circle(int x, int y, double radius) {
        super(x, y);
        this.radius = radius;
    }

    public double getRadius(){
        return radius;
    }
    
    public void setRadius(double radius) {
        this.radius = radius;
    }
    
}
