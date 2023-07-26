package July_18;

public class Pixel extends Point{
    private String color;

    public Pixel(){
        super(0, 0);
        this.color = "black";
    }

    public Pixel(int x, int y){
        super(x, y);
        this.color = "black";
    }
    
    public Pixel(int x, int y, String color){
        super(x, y);
        this.color = color;
    }

    public String getColor(){
        return color;
    }
    
    public void setColor(String color){
        this.color = color;
    }
}