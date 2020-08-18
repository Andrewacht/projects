package sample.gui.scenes.Rekeningen.Betaal;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;


import javafx.scene.Scene;
import javafx.scene.control.Label;

public class rBetaal {
    private static sample.gui.scenes.Home Home;

    @FXML
    private Label rBetaalSaldo;
    public static void main(String[] args){
        Home.getBalB();}

    public void initialize(){
        rBetaalSaldo.setText(String.valueOf(Home.getBalB()));
    }
    
    public void logout(){
        System.out.println("Naar login");
        SceneSwitcher.getInstance().loadScene("Login", "cs");
    }
    
    public void Overmaken(){
        System.out.println("Naar Overmakenbetaal");
        SceneSwitcher.getInstance().loadScene("Overmakenbetaal","cs");
    }
    public void Opnemen(){
        System.out.println("Naar opnemen");
        SceneSwitcher.getInstance().loadScene("Opnemen","cs");
    }

    public void Terug(){
        SceneSwitcher.getInstance().loadScene("Home", "cs");
    }

}
