package July_4;

import java.time.LocalDate;

public class Patient {
    private double ID;
    private String name;
    private LocalDate birth;


    public LocalDate BirthDate() {
        return LocalDate.of(0, 0, 0);
    }

    public LocalDate BirthDate(int year, int month, int day) {
        return LocalDate.of(year, month, day);
    }

    /*public double getID(){
        return ID;
    }

    public void setID(double id) {
        this.ID = id;
    }

    public String getName(){
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public LocalDate getBirth() {
        return birth;
    }

    public void setBirth(LocalDate birth) {
        this.birth = birth;
    }*/

    public Patient() {
        this.ID = 0;
        this.name = "";
        this.birth = BirthDate();
    }

    public Patient(double ID, String name, LocalDate BirthDate) {
        this.ID = ID;
        this.name = name;
        this.birth = BirthDate;
    }

}