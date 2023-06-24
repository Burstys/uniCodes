public class RobotVarargs {
    private String name;
    private Location location;

    public RobotVarargs(String name, Location... locations) {
        this.name = name;
        if (locations.length > 0) {
            this.location = locations[0];
        } else {
            this.location = new Location();
        }
    }

    public RobotVarargs() {
        this.name = " ";
        this.location = new Location();
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
    public boolean collide(RobotVarargs... otherRobotVarargs) {
        for (RobotVarargs initialRobotVarargs : otherRobotVarargs) {
            if (location.getCoordinateX() == initialRobotVarargs.getLocation().getCoordinateX() &&
                    location.getCoordinateY() == initialRobotVarargs.getLocation().getCoordinateY()) {
                return true;
            }
        }
        return false;
    }
}
