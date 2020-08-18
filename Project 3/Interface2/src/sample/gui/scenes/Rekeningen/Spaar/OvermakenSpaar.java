package sample.gui.scenes.Rekeningen.Spaar;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

;

//OVERMAKEN VAN SPAAR NAAR BETAAL

public class OvermakenSpaar {


    private static sample.gui.scenes.Home Home;             //Maak een Home Object aan om vervolgens naar de Set en Get te kunnen reference

    @FXML
    private Label rBetaalSaldo;
    @FXML
    private Label rSpaarSaldo;
    @FXML
    private Button maxSaldo;

    public void initialize() {                                      //initialize runt altjd als je de scene laadt
        rBetaalSaldo.setText(String.valueOf(Home.getBalB()));
        rSpaarSaldo.setText(String.valueOf(Home.getBalS()));
        maxSaldo.setText(String.valueOf(Home.getBalB()));
    }

    public void logout() {
        System.out.println("Naar login");
        SceneSwitcher.getInstance().loadScene("Login", "cs");
    }
    public void Honderd(){                                          //Functie voor bij de knop
                                                                    //Check met getBalS eerst of deze transactie mogelijk is
        if(Home.getBalS()-100<0){                                   //Zo niet Print dit
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() - 100);                     //Anders set je het nieuwe saldo van je spaar door getBalS- het bedrag te doen
            Home.setBalB(Home.getBalB() + 100);                     //en idem voor het nieuwe saldo van je Betaal rekening

            initialize();                                           //hier roep je hem nog een keer aan zodat de labels gerefreshed worden met het nieuwe saldo.
            System.out.println("Bedrag over gemaakt");
        }


    }
    public void Vijftig(){

        if(Home.getBalS()-50<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() - 50);
            Home.setBalB(Home.getBalB() + 50);

            initialize();
            System.out.println("Bedrag over gemaakt");
        }
    }

    public void Twintig(){

        if(Home.getBalS()-20<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() - 20);
            Home.setBalB(Home.getBalB() + 20);

            initialize();
            System.out.println("Bedrag over gemaakt");
        }
    }

    public void maxSaldo(){

        if(Home.getBalS()-Home.getBalS()<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() - Home.getBalS());
            Home.setBalB(Home.getBalB() + Home.getBalS());

            initialize();
            System.out.println("Bedrag over gemaakt");
        }
    }

    public void Terug(){
        SceneSwitcher.getInstance().loadScene("rSpaar", "cs");
    }

    }
