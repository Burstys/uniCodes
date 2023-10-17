package october_3;

public class WordFrequency {
    private String palavra;
    private int frequencia;

    public WordFrequency(String palavra) {
        this.palavra = palavra;
        this.frequencia = 1;
    }
    
    public String getPalavra() {
        return palavra;
    }
    
    public int getFrequencia() {
        return frequencia;
    }
    
    public void incrementarFrequencia() {
        frequencia++;
    }
}
    

