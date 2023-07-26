package July_4;

import java.time.LocalDate;

public class Query {
    private LocalDate date;
    private Patient patient;

    /*public LocalDate getDate(){
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public Patient getPatient(){
        return patient;
    }

    public void setPatient(Patient patient) {
        this.patient = patient;
    }*/
    
    public Query(LocalDate date, Patient pacient) {
        this.date = date;
        this.patient = pacient;
    }
}
