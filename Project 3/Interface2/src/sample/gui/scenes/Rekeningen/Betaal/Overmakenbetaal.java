package sample.gui.scenes.Rekeningen.Betaal;;
import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

//OVERMAKEN VAN BETAAL NAAR SPAARREKENING

public class Overmakenbetaal {


    private static sample.gui.scenes.Home Home;

    @FXML
    private Label rBetaalSaldo;
    @FXML
    private Label rSpaarSaldo;
    @FXML
    private Button maxSaldo;
    public static void main(String[] args) {
        Home.getBalB();
        Home.getBalS();
    }

    public void initialize() {
        rBetaalSaldo.setText(String.valueOf(Home.getBalB()));
        rSpaarSaldo.setText(String.valueOf(Home.getBalS()));
        maxSaldo.setText(String.valueOf(Home.getBalB()));
    }

    public void logout() {
        System.out.println("Naar login");
        SceneSwitcher.getInstance().loadScene("Login", "cs");
    }
    public void Honderd(){

        if(Home.getBalB()-100<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() + 100);
            Home.setBalB(Home.getBalB() - 100);

            initialize();
            System.out.println("Bedrag over gemaakt");
        }


    }
    public void Vijftig(){

        if(Home.getBalB()-50<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() + 50);
            Home.setBalB(Home.getBalB() - 50);

            initialize();
            System.out.println("Bedrag over gemaakt");
        }
    }

    public void Twintig(){

        if(Home.getBalB()-20<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() + 20);
            Home.setBalB(Home.getBalB() - 20);

            initialize();
            System.out.println("Bedrag over gemaakt");
        }
    }

    public void maxSaldo(){

        if(Home.getBalB()-Home.getBalB()<0){
            System.out.println("Onvoldoende saldo");
        }
        else {
            Home.setBalS(Home.getBalS() + Home.getBalB());
            Home.setBalB(Home.getBalB() - Home.getBalB());

            initialize();
            System.out.println("Bedrag over gemaakt");
        }
    }

    public void Terug(){
        SceneSwitcher.getInstance().loadScene("rBetaal", "cs");
    }

    }
