package sample.gui.scenes.Rekeningen.Spaar;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class rSpaar {
    private static sample.gui.scenes.Home Home;

    @FXML
    private Label rBetaalSaldo;
    @FXML
    private Label rSpaarSaldo;

    public static void main(String[] args){
        Home.getBalB();}

    public void initialize(){

        rSpaarSaldo.setText(String.valueOf(Home.getBalS()));
    }

    public void logout(){
        System.out.println("Naar login");
        SceneSwitcher.getInstance().loadScene("Login", "cs");
    }

    public void Overmaken(){
        System.out.println("Naar OvermakenSpaar");
        SceneSwitcher.getInstance().loadScene("OvermakenSpaar","cs");
    }

    public void Terug(){
        SceneSwitcher.getInstance().loadScene("Home", "cs");
    }
}
