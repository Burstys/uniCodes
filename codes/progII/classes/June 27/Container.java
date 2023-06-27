public class Container {
    private double interiorVolume;
    private boolean beingUsed;

    public Container(){
        this.interiorVolume = 0.0;
        this.beingUsed = false;
    }

    public Container(double interiorVolume, boolean beingUsed){
        this.interiorVolume = interiorVolume;
        this.beingUsed = beingUsed;
    }

    public double getInteriorVolume(){
        return interiorVolume;
    }

    public boolean isBeingUsed(){
        return beingUsed;
    }

    public boolean occupy(double volume){
        if(volume >= interiorVolume && beingUsed == false) {
            beingUsed = true;
            interiorVolume = volume;
            System.out.println("Interior volume = "+ interiorVolume+ "m²");
            return true;
        }
        if(volume < interiorVolume || beingUsed == true) {
            System.out.println(beingUsed);
            return false;
        }
        return beingUsed;
    }
}
