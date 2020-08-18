package sample.gui.scenes;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;
import javafx.scene.control.PasswordField;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.scene.control.Label;


public class Login {
    int Attempts = 3;
    String pw = ("1111");
    @FXML
    private TextField txtPassword;

    @FXML
    private Label lblLabel;

    @FXML
    private Label Timer;



    public void loginCheck(ActionEvent event) {
        if(txtPassword.getText().equals(pw)){
           SceneSwitcher.getInstance().loadScene("Home");

        }
        else{
            lblLabel.setText("Login failed!");
            lblLabel.setTextFill(Color.rgb(210, 39, 30));
            Attempts--;


            if(Attempts !=0) {
                Timer.setText("U heeft nog " + Attempts + " pogingen.");
            }
            else{

                lblLabel.setText("Je hebt te vaak geprobeerd");
                Attempts = 3;






                    }
                }

            }









        public void logout(){
        System.out.println("Naar login");
        SceneSwitcher.getInstance().loadScene("login", "cs");
    }


    }

