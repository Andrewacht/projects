package sqlDB;

import com.fazecast.jSerialComm.*;

import java.sql.*;

public class Driver {
        
    public static void main(String[] args) {
        JavaDatabase javaDatabase = new JavaDatabase();
      JavaArduino javaArduino = new JavaArduino();
      javaDatabase.start();
        javaArduino.start();
        


    }
}
