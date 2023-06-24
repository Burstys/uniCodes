
public class Location {
    private float coordinateX;
    private float coordinateY;
    
    public Location(){
        this.coordinateX = 0;
        this.coordinateY = 0;
    }
    
    public Location(float x, float y){
        this.coordinateX = x;
        this.coordinateY = y;
    }
    
    public float getCoordinateX (){
        return coordinateX;
    }
    
    public void setCoordinateX (float coordinateX){
        this.coordinateX = coordinateX;
    }
    
    public float getCoordinateY (){
        return coordinateY;
    }
    
    public void setCoordinateY (float coordinateY){
        this.coordinateY = coordinateY;
    }
    
    public void setLocation(float coordinateX, float coordinateY){
        this.coordinateX = coordinateX;
        this.coordinateY = coordinateY;
    }
}
