package september_26;

public class Test {
    public static void main(String[] args){
        Drawer<String> stringDrawer = new Drawer<>("Drawer");
        String stringContent = stringDrawer.getContent();

        Drawer<Integer> integerDrawer = new Drawer<>(23);
        int integerContent = integerDrawer.getContent();

    }
}
