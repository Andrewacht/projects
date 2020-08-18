package sample.gui.scenes.Rekeningen.Betaal;;
import cz.kamenitxan.sceneswitcher.SceneSwitcher;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

//OPNEMEN VAN BETAAL NAAR SPAARREKENING

public class Opnemen {


    private static sample.gui.scenes.Home Home;

    @FXML
    private Label rBetaalSaldo;


    @FXML
    private Button maxSaldo;
    public static void main(String[] args) {
        Home.getBalB();

    }

    public void initialize() {
        rBetaalSaldo.setText(String.valueOf(Home.getBalB()));

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

            Home.setBalB(Home.getBalB() - 100);

            initialize();
            System.out.println("Een Bedrag van " +100+ " is gepint");
        }


    }
    public void Vijftig(){

        if(Home.getBalB()-50<0){
            System.out.println("Onvoldoende saldo");
        }
        else {

            Home.setBalB(Home.getBalB() - 50);

            initialize();
            System.out.println("Een Bedrag van " +50+ " is gepint");
        }
    }

    public void Twintig(){

        if(Home.getBalB()-20<0){
            System.out.println("Onvoldoende saldo");
        }
        else {

            Home.setBalB(Home.getBalB() - 20);

            initialize();
            System.out.println("Een Bedrag van " +20+ " is gepint");
        }
    }

    public void maxSaldo(){

        if(Home.getBalB()-Home.getBalB()<0){
            System.out.println("Onvoldoende saldo");
        }
        else {

            Home.setBalB(Home.getBalB() - Home.getBalB());

            initialize();
            System.out.println("Een Bedrag van " +Home.getBalB()+ " is gepint");
        }
    }

    public void Terug(){
        SceneSwitcher.getInstance().loadScene("rBetaal", "cs");
    }

}
