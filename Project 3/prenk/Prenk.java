
package prenk;
import com.fazecast.jSerialComm.*;

/**
 *
 * @author ilhan
 */
public class Prenk {
         private static int money = 10000;

 public static float getmoney() {
        return money;
    }
 
    public static void setmoney(float money) {
        
        if (money > 0)
        {
            Prenk.money = (int) money;
        }
    }
  
    
    
    
  //      -------------------AANPASSRN
    private static int pas = 0; 
    public static int getPas() {
        return pas;
    }
  
  public static void setPas(int pas) {
    Prenk.pas = pas;   }   
        
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
       
// TODO code application logic here
    
        char youShallNotPassword[];
        byte DikkeArray = 0;
        String RFID = "";
        
        
        scherm1 Scherm = new scherm1();
        Scherm.setVisible(true);


        
        SerialPort.getCommPorts();
        
        SerialPort comPort = SerialPort.getCommPorts()[0];
comPort.openPort();
try {
   while (true)
   {
      while (comPort.bytesAvailable() == 0)
         Thread.sleep(20);

      byte[] arduinoData = new byte[comPort.bytesAvailable()];
      comPort.readBytes(arduinoData, arduinoData.length);
      String result = "";
      for (byte temp : arduinoData) {
          result = result + (char) temp;
      }
      
      System.out.println(result);
      if (result.contains("RFID") && pas == 0){
      //    scherm1 Uno = new scherm1();
        //  Uno.setVisible(true);
         //Scherm.dispose();
          pas++;
          
      }
      
      /*
     if (result.contains("Keypad")){
          String key = result.substring(7,8);
          System.out.println(key);
          int a = Integer.valueOf(key);
          youShallNotPassword[DikkeArray] = a;
     }
      */
      if (result.equals("RFID 630ADE2B")){
          
      }
      
      
          
      
   }
} catch (Exception e) { e.printStackTrace(); }
comPort.closePort();
     /*   
        try {
            //1. Get a connection to Database
            Connection myConn = DriverManager.getConnection("", "", "");
            //2. Create a statement
            Statement myStmt = myConn.createStatement();
            //3. Execute SQL query
            ResultSet myRs = myStmt.executeQuery("select * from user");
            //4. Proces the result set
            while (myRs.next()) {
                System.out.println(myRs.getString("last_name") + ", " + myRs.getString("first_name"));
            }
            
        }
        
        catch (Exception e) {
            e.printStackTrace();
        }
    }*/
    
}
}
