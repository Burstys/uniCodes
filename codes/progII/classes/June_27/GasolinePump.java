package June_27;

public class GasolinePump {
    private double capacity;
    private double pricePerLiter;
    private double soldLiters;
    private double salesValue;

    public GasolinePump() {
        this.capacity = 5000;
        this.pricePerLiter = 5.2;
        this.soldLiters = 0.0;
        this.salesValue = 0.0;
    }

    public double getCapacity(){
        return capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }
    
    public double getPricePerLiter(){
        return pricePerLiter;
    }

    public void setPricePerLiter(double pricePerLiter) {
        this.pricePerLiter = pricePerLiter;
    }

    public double getSoldLiters(){
        return soldLiters;
    }

    public void setSoldLiters(double soldLiters) {
        this.soldLiters = soldLiters;
    }

    public double getSalesValue(){
        return salesValue;
    }

    public void setSalesValue(double salesValues) {
        this.salesValue = salesValues;
    }

    public void fuelLiters(double soldLiters){
        this.capacity -= soldLiters;
        this.soldLiters = soldLiters;
        this.salesValue += soldLiters;
    }

    public void fuelCash(double cash){
        this.soldLiters = cash/pricePerLiter;
        this.salesValue += cash;
        this.capacity -= this.soldLiters;
    }

    public void status(){
        System.out.println(capacity + " liters left");
    }
}
