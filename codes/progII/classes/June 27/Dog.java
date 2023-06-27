public class Dog{
    private String name;
    private String race;

    public String getName(){
        return name;
    }

    public String getRace(){
        return race;
    }

    public void setName(String name){
        this.name = name;
    }
    
    public void setRace(String race){
        this.race = race;
    }

    public Dog(){
        this.name = " ";
        this.race = " ";
    }
    public Dog(String name){
        this.name = name;
        this.race = "unknown";
    }

    public Dog(String name, String race){
        this.name = name;
        this.race = race;
    }

    public void bark(){
        System.out.println("Auau");
    }
    public void repeatBark(int amount){
        for(int i = 0; i < amount; i++){
            if (i<0){
                System.out.println("Error");
            }
            if (i>100){
                System.out.println("Invalid parameter");
            }
            else {
                bark();
            }    
        }
    }
}


