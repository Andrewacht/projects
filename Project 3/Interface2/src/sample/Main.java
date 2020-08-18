package sample;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class Main extends Application {
    private final SceneSwitcher sceneSwitcher = SceneSwitcher.getInstance();

    @Override


    public void start(Stage stage) throws Exception {
        //Start
        sceneSwitcher.addScene("Home", "home.fxml");
        sceneSwitcher.addScene("account", "account.fxml");
        sceneSwitcher.addScene("Login", "Login.fxml");
        //Betaal
        sceneSwitcher.addScene("rBetaal", "Rekeningen/Betaal/rBetaal.fxml");
        sceneSwitcher.addScene("Opnemen", "Rekeningen/Betaal/Opnemen.fxml");
        sceneSwitcher.addScene("Overmakenbetaal", "Rekeningen/Betaal/Overmakenbetaal.fxml");
        //Spaar
        sceneSwitcher.addScene("rSpaar","Rekeningen/Spaar/rSpaar.fxml");
        sceneSwitcher.addScene("OvermakenSpaar", "Rekeningen/Spaar/OvermakenSpaar.fxml");
        stage.setTitle("Home screen");
        stage.setScene(sceneSwitcher.createMainScene(this.getClass()));

        sceneSwitcher.loadScene("Login");


        stage.show();
}


    public static void main(String[] args) {
        launch(args);

    }
}

