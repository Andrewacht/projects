/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sqlDB;

import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Andre
 */
public class JavaArduino extends Thread {
    static String result = "";
    static int score;
    static String game;
    static String userName;
    static Gui_scoreInput scoreInput = new Gui_scoreInput();
    static Gui_leaderboards leaderboards = new Gui_leaderboards();
    static Arcade64 arcade64 = new Arcade64();

    public static void setScore(int score) {
        JavaArduino.score = score;
    }

    public static int getScore() {
        return score;
    }
    
    public static void setGame(String game) {
        JavaArduino.game = game;
    }

    public static String getGame() {
        return game;
    }
    
    public static void setUserName(String userName) {
        JavaArduino.userName = userName;
    }

    public static String getUserName() {
        return userName;
    }
    
    public void run() {
        arcade64.setVisible(true);
        while(true){
        SerialPort comPort = SerialPort.getCommPorts()[0];
        comPort.openPort();
        comPort.setBaudRate(2000000);
        comPort.addDataListener(new SerialPortDataListener() {
            @Override
            public int getListeningEvents() {
                return SerialPort.LISTENING_EVENT_DATA_AVAILABLE;
            }

            @Override
            public void serialEvent(SerialPortEvent event) {
                if (event.getEventType() != SerialPort.LISTENING_EVENT_DATA_AVAILABLE) {
                    return;
                }
                byte[] newData = new byte[comPort.bytesAvailable()];
                comPort.readBytes(newData, newData.length);
                for (byte bit : newData) {
                    result = result + (char) bit;
                }
                System.out.println(result);
                if (result.contains("snake")){
                String result_game = result.substring(0, 5);
                String resultScore = result.substring(6);
                setScore(Integer.parseInt(resultScore));
                if (getScore() == 0){

                }
                else{
                
                setGame(result_game);
                leaderboards.dispose();
                scoreInput.setVisible(true);
                scoreInput.jTextField1.setText(Integer.toString(getScore()));
                scoreInput.jTextField4.setText(getGame());
                }
            }

            }
        });

  

             
            result = "";   //passwordCorrect = true;
        }
        }
    }

