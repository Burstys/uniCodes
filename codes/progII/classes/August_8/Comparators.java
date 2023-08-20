package August_8;

import java.util.Comparator;

public class Comparators{
    public static class NameComparator implements Comparator<Developer> {
        @Override
        public int compare(Developer dev1, Developer dev2) {
            return dev1.getName().compareTo(dev2.getName());
        }
    }

    public static class AgeComparator implements Comparator<Developer> {
        @Override
        public int compare(Developer dev1, Developer dev2) {
            return Integer.compare(dev1.getAge(), dev2.getAge());
        }
    }

    public static class SalaryLowestHighestComparator implements Comparator<Developer> {
        @Override
        public int compare(Developer dev1, Developer dev2) {
            return Double.compare(dev1.getSalary(), dev2.getSalary());
        }
    }

    public static class SalaryHighestLowestComparator implements Comparator<Developer> {
        @Override
        public int compare(Developer dev1, Developer dev2) {
            return Double.compare(dev2.getSalary(), dev1.getSalary());
        }
    }
}
