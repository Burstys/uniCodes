package august_15;

import java.util.List;
import java.util.ArrayList;

public class ProductM implements IProductManufactured {
    private String name;
    private List<IProduct>ingredients;

    public ProductM(){
        name = "";
        ingredients = new ArrayList<IProduct>();
    }

    public ProductM(String name, List<IProduct> ingredients){
        this.name = name;
        this.ingredients = ingredients;
    }

    @Override
    public String getName(){
        return name;
    }

    @Override
    public double getPrice(){
        double totalCost = 0.0;
        for(IProduct ingredient : ingredients){
            totalCost += ingredient.getPrice();
        }
        return totalCost;
    }

    @Override
    public int getIngredientsAmount() {
        return ingredients.size();
    }

    @Override
    public IProduct getIngredients(int amount) {
        if (amount >= 0 && amount < ingredients.size()) {
            return ingredients.get(amount);
        }
        return null;
    }



}



