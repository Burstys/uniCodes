package october_3;

public class GLLTest {
    public static void main(String[] args) {
        GenericLinkedList<Integer> list = new GenericLinkedList();
        list.add(1);
        list.add(2);
        list.add(3);

        System.out.println("list's size: " + list.size());
        System.out.println("list's elements: ");
        list.print();

        list.remove(2);
        System.out.println("Element removed:");
        list.print();
    }
}
