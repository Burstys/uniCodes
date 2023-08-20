package august_15;
import java.util.ArrayList;

public class Test {
    public static void main(String[] args){
        ArrayList<CalculableArea> areas = new ArrayList(5);
        
        Square areaS = new Square(3.0);
        Rectangle areaR = new Rectangle(4.0, 5.0);
        Circle areaC = new Circle(9.0);

        areas.add(areaS);
        areas.add(areaR);
        areas.add(areaC);

        for (int i = 0; i < areas.size(); i++) {
            System.out.println(areas.get(i));
        }

    }
}
