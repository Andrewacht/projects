package sqlDB;

import com.fazecast.jSerialComm.*;

import java.sql.*;

public class Driver {
        private static float Sal = 1000;

        public static float getSal() {
            return Sal;
    }
 
        public static void setSal(float Sal) {
            Driver.Sal = Sal;
    }
    
     //geldOpnemen geldOpgenomen  = new geldOpnemen();
    //int s = geldOpgenomen.getGeldOpgenomen();
    private static int pas = 0;

    public static int getPas() {
        return pas;
    }
  
  public static void setPas(int pas) {
    Driver.pas = pas;   }   
        
    public static void main(String[] args) {
        char passwordEntered[];
        byte arrayPosition = 0;
        String RFID = "";
        


        GUI gui = new GUI();
          gui.setVisible(true);
        
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
          tweedeScherm TweedeScherm = new tweedeScherm();
          TweedeScherm.setVisible(true);
          gui.dispose();
          pas++;
          
      }
      
      
     /* if (result.contains("Keypad")){
          String key = result.substring(7,8);
          System.out.println(key);
          int a = Integer.valueOf(key);
          passwordEntered[arrayPosition] = a;
     }*/
      
      if (result.equals("RFID 690BDE2B")){
          
      }
      
      
          
      
   }
} catch (Exception e) { e.printStackTrace(); }
comPort.closePort();
        
        try {
            //1. Get a connection to Database
            Connection myConn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mybank", "root", "ssmj8809");
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
        
    }
    
}
