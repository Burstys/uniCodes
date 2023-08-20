package august_15;

public class Square implements CalculableArea {
    private double side;

    public Square(){
        side = 0.0;
    }

    public Square(double side){
        this.side = side;
    }

    public double getSide(){
        return side;
    }

    public void setSide(double side){
        this.side = side;
    }

    @Override
    public double calculateArea(){
        return this.side * this.side;
    }
}
