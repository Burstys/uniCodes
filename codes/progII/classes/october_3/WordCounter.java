package october_3;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class WordCounter {
    public static void main(String[] args) {
        String entries = "D:\\entrada.txt";
        Map<String, Integer> wordFrequencyMap = new HashMap<>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(entries));
            String line;

            while ((line = reader.readLine()) != null) {
                // Converter a linha para minúsculas
                line = line.toLowerCase();

                // Dividir a linha em palavras usando espaços como delimitador
                String[] lineToWords = line.split("\\s+");

                // Iterar pelas palavras da linha
                for (String word : lineToWords) {
                    // Remover pontuação, se necessário
                    word = word.replaceAll("[.,!?;:'\"\\(\\)\\[\\]{}]", "");

                    // Verificar se a palavra já está na lista de palavras
                    if(wordFrequencyMap.containsKey(word)){
                        wordFrequencyMap.put(word, wordFrequencyMap.get(word)+1);
                    }
                    else{
                        wordFrequencyMap.put(word, 1);
                    }
                }
            }

            reader.close();

            // Exibir a frequência das palavras
            for (Map.Entry<String, Integer> entry : wordFrequencyMap.entrySet()) {
                System.out.println(entry.getKey() + ": " + entry.getValue());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
