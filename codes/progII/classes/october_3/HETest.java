package october_3;

import java.util.ArrayList;

public class HETest {
     public static void main(String[] args) {
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(10);
        numbers.add(5);
        numbers.add(20);
        numbers.add(8);

        Integer highestNumber = HighestElement.getHighestElement(numbers);
        System.out.println("The highest number in the list: " + highestNumber);

        ArrayList<String> words = new ArrayList<>();
        words.add("maçã");
        words.add("banana");
        words.add("laranja");

        String biggestWord = HighestElement.getHighestElement(words);
        System.out.println("The biggest word in the list: " + biggestWord);
    }
}

