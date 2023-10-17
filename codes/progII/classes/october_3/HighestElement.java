package october_3;

import java.util.Collection;

public class HighestElement {
    public static <T extends Comparable<T>> T getHighestElement(Collection<T> collection) {
        if (collection.isEmpty()) {
            throw new IllegalArgumentException("Empty collection");
        }

        T highest = null;

        for (T element : collection) {
            if (highest == null || element.compareTo(highest) > 0) {
                highest = element;
            }
        }

        return highest;
    }
}
