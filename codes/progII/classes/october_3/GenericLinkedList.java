package october_3;

public class GenericLinkedList<T> {
    private Node<T> first;
    private int size;

    // Construtor para inicializar a list encadeada vazia
    public GenericLinkedList() {
        this.first = null;
        this.size = 0;
    }

    // Classe interna Node que representa um nó na list
    private static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    // Método para add um element no final da list
    public void add(T element) {
        Node<T> newNode = new Node<>(element);
        if (first == null) {
            first = newNode;
        } else {
            Node<T> current = first;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        size++;
    }

    // Método para obter o size da list
    public int size() {
        return size;
    }

    // Método para verificar se a list está vazia
    public boolean isEmpty() {
        return size == 0;
    }

    // Método para print os elements da list
    public void print() {
        Node<T> current = first;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    // Método para remove um element da list
    public void remove(T element) {
        if (first == null) {
            return;
        }

        if (first.data.equals(element)) {
            first = first.next;
            size--;
            return;
        }

        Node<T> current = first;
        while (current.next != null && !current.next.data.equals(element)) {
            current = current.next;
        }

        if (current.next != null) {
            current.next = current.next.next;
            size--;
        }
    }
}
