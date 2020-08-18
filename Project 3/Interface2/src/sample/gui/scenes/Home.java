package sample.gui.scenes;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;

import javafx.scene.control.Label;

public class Home {
    private static double balB = 209.48;                //Declare ze voor het eerst hier want hier vul ik de saldo's voor het eerst in.
    private static double balS = 1409.22;
    @FXML
    private Label balanceB; //Saldo betaal rekening

    @FXML
    private Label balanceS; //Saldo spaar rekening


    public void initialize(){
        balanceS.setText(String.valueOf(balS));         //Ik maak gebruik van Doubles maar voor setText (Functie van Fxml) heb je strings nodig.
        balanceB.setText(String.valueOf(balB));}        // hiervoor gebruik je dus String.valueOf. Dit zet de variabele om in een String


    public void logout(){
        System.out.println("Naar login");
        SceneSwitcher.getInstance().loadScene("Login", "cs");
    }
    public void rBetaal(){
        System.out.println("Naar betaal rekening.");
        SceneSwitcher.getInstance().loadScene("rBetaal","cs");
    }
    public void rSpaar(){
        System.out.println("Naar spaar rekening.");
        SceneSwitcher.getInstance().loadScene("rSpaar","cs");
    }

    public static double getBalB() {                                //Setters En getters
        return balB;
    }

    public static void setBalB(double balB) {
        Home.balB = balB;
    }

    public static double getBalS(){
        return balS;
    }

    public static void setBalS(double balS){
        Home.balS = balS;
    }

}
