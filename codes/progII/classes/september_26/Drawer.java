package september_26;

public class Drawer<C> {
    private C content;

    public Drawer(){
        content = null;
    }
    public Drawer(C content){
        this.content = content;
    }
    public void setContent(C content){
        this.content = content;
    }
    public C getContent(){
        return content;
    }

    public static <E extends Number> E sum(E[] vet){
        E sum = null;
        for(E e : vet){
            sum = sum + e;
        }
        return sum;
    }
}
