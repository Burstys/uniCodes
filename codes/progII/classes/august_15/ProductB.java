package august_15;

public class ProductB implements IProduct{
    private String name;
    private double price;

    public ProductB(){
        name = "";
        price = 0.0;
    }

    public ProductB(String name, double price){
        this.name = name;
        this.price = price;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}
