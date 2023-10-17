package october_10;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ConvertC {
    public static void main(String[] args) {
        try {
            FileReader fileReader = new FileReader("archive.txt");
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            //processa o arquivo

            bufferedReader.close();



        }
        catch(IOException e) {
            if(e.getClass()==java.io.FileNotFoundException.class){
                System.out.println("Archive doensn't exist\n");
            }
            else if(e.getClass()==java.io.IOException.class){
                System.out.println("Input/outut error\n");
            }
            else if(e.getClass()==java.nio.channels.ClosedByInterruptException.class){
                System.out.println("Temporalily unavailable resource\n");
            }
            else{
                System.out.println("Error: "+ e.getMessage());
            }
        }
    }
}
