package august_15;

import java.util.List;
import java.util.ArrayList;

public class ProductManager {
    public static IProduct processCost(IProduct product) {
        if (product instanceof ProductB) {
            ProductB purchasedProduct = (ProductB) product;
            String productName = purchasedProduct.getName();
            String[] ingredients = getIngredients(productName);
            
            if (ingredients != null) {
                double manufacturedCost = 0.0;
                for (String ingredient : ingredients) {
                    double ingredientCost = getPurchaseCost(ingredient);
                    manufacturedCost += ingredientCost;
                }

                if (manufacturedCost < purchasedProduct.getPrice()) {
                    List<IProduct> ingredientList = new ArrayList<>();
                    ingredientList.add(new ProductB(productName, purchasedProduct.getPrice()));

                    for (String ingredient : ingredients) {
                        ingredientList.add(new ProductB(ingredient, getPurchaseCost(ingredient)));
                    }

                    return new ProductM(productName, ingredientList);
                }
            }
        }
        return product;
    }

    public static String[] getIngredients(String productName) {
        if (productName.equals("ProdutoFabricado1")) {
            return new String[]{"Ingrediente1", "Ingrediente2"};
        } else if (productName.equals("ProdutoFabricado2")) {
            return new String[]{"Ingrediente3", "Ingrediente4"};
        }
        return null;
    }

    public static double getPurchaseCost(String productName) {
        if (productName.equals("ProdutoComprado1")) {
            return 10.0;
        } else if (productName.equals("ProdutoComprado2")) {
            return 20.0;
        }
        return 0.0;
    }
}