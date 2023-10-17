package august_15;

public interface IProductManufactured extends IProduct{
    int getIngredientsAmount();
    IProduct getIngredients(int amount);
}
