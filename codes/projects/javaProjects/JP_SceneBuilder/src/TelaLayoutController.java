import javafx.fxml.FXML;
import javafx.scene.control.TextField;

public class TelaLayoutController {
    @FXML
    private TextField entryField;

    @FXML
    private TextField returnField;

    @FXML
    private void convert() {
        String converted = entryField.getText();
        returnField.setText(converted.toUpperCase());
    }

    @FXML
    private void clean() {
        entryField.setText("");
        returnField.setText("");
    }
}
