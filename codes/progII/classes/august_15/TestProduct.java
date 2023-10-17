package august_15;

public class TestProduct {
    public static void main(String[] args) {
        // Create a purchased product
        IProduct purchasedProduct = new ProductB("ProductB1", 50.0);

        // Process the cost and potentially convert to a manufactured product
        IProduct processedProduct = ProductManager.processCost(purchasedProduct);

        // Display the results
        System.out.println("Original Product:");
        System.out.println("Name: " + purchasedProduct.getName());
        System.out.println("Price: " + purchasedProduct.getPrice());

        System.out.println("\nProcessed Product:");
        System.out.println("Name: " + processedProduct.getName());
        System.out.println("Price: " + processedProduct.getPrice());

        if (processedProduct instanceof IProductManufactured) {
            IProductManufactured manufacturedProduct = (IProductManufactured) processedProduct;
            int numIngredients = manufacturedProduct.getIngredientsAmount();
            System.out.println("Number of Ingredients: " + numIngredients);
            for (int i = 0; i < numIngredients; i++) {
                IProduct ingredient = manufacturedProduct.getIngredients(i);
                System.out.println("Ingredient " + (i + 1) + ": " + ingredient.getName());
            }
        }
    }
}