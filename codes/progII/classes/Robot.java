
public class Robot {
    public String name;
    public Location location;
    
    public Robot(){
        this.name = " ";
        location = new Location();
    }
    public Robot(String name, Location location){
        this.name = name;
        this.location = location; 
    }
    public void moveRight(){
        location.setCoordinateX(location.getCoordinateX()+1);
    }
    public void moveLeft(){
        location.setCoordinateX(location.getCoordinateX()-1);
    }
    public void moveUp(){
        location.setCoordinateY(location.getCoordinateY()+1);
    }
    public void moveDown(){
        location.setCoordinateY(location.getCoordinateY()-1);
    }
    public void teletransport(Location newLocation){
        location = newLocation;
    }
    public void showLocation(){
        location.getCoordinateX();
        location.getCoordinateY();
    }
    public Location getLocation(){
        return location;
    }
    public boolean collide(Robot robot2) {
        return location.getCoordinateX() == robot2.getLocation().getCoordinateX() &&
               location.getCoordinateY() == robot2.getLocation().getCoordinateY();
    }
}