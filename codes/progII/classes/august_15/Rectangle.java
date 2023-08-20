package august_15;

public class Rectangle implements CalculableArea {
    private double width;
    private double height;

    public Rectangle(){
        width = 0.0;
        height = 0.0;
    }

    public Rectangle(double width, double height){
        this.width = width;
        this.height = height;
    }

    public double getWidth(){
        return width;
    }

    public double getHeight(){
        return height;
    }

    public void setWidth(double width){
        this.width = width;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    @Override
    public double calculateArea(){
        return width * height;
    }
}
