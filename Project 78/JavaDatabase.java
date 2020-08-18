/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sqlDB;

import java.sql.DriverManager;
import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import com.mysql.jdbc.Driver;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;
import static sqlDB.JavaArduino.userName;

/**
 *
 * @author Andre
 */
public class JavaDatabase extends Thread {

    String names[] = new String[5];
    int scores[] = new int[5];

    static String firstPlaceName;
    static String secondPlaceName;
    static String thirdPlaceName;
    static String fourthPlaceName;
    static String fifthPlaceName;

    static int firstPlaceScore;
    static int secondPlaceScore;
    static int thirdPlaceScore;
    static int fourthPlaceScore;
    static int fifthPlaceScore;

    public static void setFirstPlaceName(String name) {
        JavaDatabase.firstPlaceName = name;
    }

    public static String getFirstPlaceName() {
        return firstPlaceName;
    }

    public static void setSecondPlaceName(String name) {
        JavaDatabase.secondPlaceName = name;
    }

    public static String getSecondPlaceName() {
        return secondPlaceName;
    }

    public static void setThirdPlaceName(String name) {
        JavaDatabase.thirdPlaceName = name;
    }

    public static String getThirdPlaceName() {
        return thirdPlaceName;
    }

    public static void setFourthPlaceName(String name) {
        JavaDatabase.fourthPlaceName = name;
    }

    public static String getFourthPlaceName() {
        return fourthPlaceName;
    }

    public static void setFifthPlaceName(String name) {
        JavaDatabase.fifthPlaceName = name;
    }

    public static String getFifthPlaceName() {
        return fifthPlaceName;
    }

    public static void setFirstPlaceScore(int score) {
        JavaDatabase.firstPlaceScore = score;
    }

    public static int getFirstPlaceScore() {
        return firstPlaceScore;
    }

    public static void setSecondPlaceScore(int score) {
        JavaDatabase.secondPlaceScore = score;
    }

    public static int getSecondPlaceScore() {
        return secondPlaceScore;
    }

    public static void setThirdPlaceScore(int score) {
        JavaDatabase.thirdPlaceScore = score;
    }

    public static int getThirdPlaceScore() {
        return thirdPlaceScore;
    }

    public static void setFourthPlaceScore(int score) {
        JavaDatabase.fourthPlaceScore = score;
    }

    public static int getFourthPlaceScore() {
        return fourthPlaceScore;
    }

    public static void setFifthPlaceScore(int score) {
        JavaDatabase.fifthPlaceScore = score;
    }

    public static int getFifthPlaceScore() {
        return fifthPlaceScore;
    }

    static int count;
    static String newNameQuery = "";

    public static void setNameQuery(String Query) {
        JavaDatabase.newNameQuery = Query;
    }

    public static String getNameQuery() {
        return newNameQuery;
    }
    static String newScoreQuery = "";

    public static void setScoreQuery(String Query) {
        JavaDatabase.newScoreQuery = Query;
    }

    public static String getScoreQuery() {
        return newScoreQuery;
    }

    public static void setNewScore(int game, int score, String name) {
        JavaDatabase.setNameQuery("INSERT INTO users "
                + "VALUES ('" + name + "')");
        JavaDatabase.setScoreQuery(("INSERT INTO scores (scoreID, userName, gameID, score)")
                + "VALUES (" + (count + 1) + ", ('" + name + "'), " + game + ", " + score + ")");

        //System.out.println(getQuery());
    }
    // init database constants
    Connection conn;

    public void run() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            System.out.println("Driver Loaded");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/arcadescoreboard?serverTimezone=UTC", "root", "ssmj8809");
            //Database Name - testDB, Username - "root", Password - ""
            System.out.println("Connected...");
        } catch (Exception e) {
            e.printStackTrace();
        }
        while (true) {
            try {
                //2. Create a statement
                Statement myStmt = conn.createStatement();
                //3. Execute SQL query
                ResultSet myRs = myStmt.executeQuery("select count(*) COUNT from scores");
                //4. Proces the result set
                while (myRs.next()) {
                    //System.out.println(myRs.getInt("COUNT"));
                    count = myRs.getInt("Count");
                }

            } catch (Exception e) {
                e.printStackTrace();
            }

            if (getNameQuery() != "") {
                try {
                    Statement st = conn.createStatement();
                    st.executeUpdate(getNameQuery());
                    setNameQuery("");
                    JavaArduino.setScore(0);
                    JavaArduino.setUserName("");
                } catch (SQLException ex) {
                    setNameQuery("");
                    JavaArduino.setScore(0);
                    JavaArduino.setUserName("");
                    System.err.println(ex.getMessage());
                }
            } else {
            }

            if (getScoreQuery() != "") {
                try {
                    Statement st = conn.createStatement();
                    st.executeUpdate(getScoreQuery());
                    setScoreQuery("");
                    JavaArduino.setScore(0);
                    JavaArduino.setUserName("");
                } catch (SQLException ex) {
                    setScoreQuery("");
                    JavaArduino.setScore(0);
                    JavaArduino.setUserName("");
                    System.err.println(ex.getMessage());
                }
            } else {
            }
            //SELECT scores.score, games.name AS game, users.name as player FROM scores, users, games
            //WHERE scores.userID = users.userID
            //AND scores.gameID = games.gameID
            //ORDER BY scores.score DESC
            //LIMIT 5;
            if (JavaArduino.result.contains("top5")) {

                try {
                    //2. Create a statement
                    Statement myStmt = conn.createStatement();
                    //3. Execute SQL query
                    ResultSet myRs = myStmt.executeQuery("SELECT score, userName FROM scores "
                            + "WHERE scores.gameID = 1 "
                            + "ORDER BY score DESC "
                            + "LIMIT 5;");
                    //4. Proces the result set
                    int i = 0;
                    while (myRs.next()) {

                        //System.out.println(myRs.getString("userName"));
                        names[i] = myRs.getString("userName");
                        // System.out.println(myRs.getString("score"));
                        scores[i] = myRs.getInt("score");
                        i++;
                    }

                    JavaArduino.result = "";
                    setFirstPlaceName(names[0]);
                    setSecondPlaceName(names[1]);
                    setThirdPlaceName(names[2]);
                    setFourthPlaceName(names[3]);
                    setFifthPlaceName(names[4]);
                    
                    setFirstPlaceScore(scores[0]);
                    setSecondPlaceScore(scores[1]);
                    setThirdPlaceScore(scores[2]);
                    setFourthPlaceScore(scores[3]);
                    setFifthPlaceScore(scores[4]);
                    
                    JavaArduino.leaderboards.setVisible(true);
                    
                    JavaArduino.leaderboards.jTextField3.setText(getFirstPlaceName());
                    JavaArduino.leaderboards.jTextField4.setText(getSecondPlaceName());
                    JavaArduino.leaderboards.jTextField5.setText(getThirdPlaceName());
                    JavaArduino.leaderboards.jTextField6.setText(getFourthPlaceName());
                    JavaArduino.leaderboards.jTextField7.setText(getFifthPlaceName());
                    
                    JavaArduino.leaderboards.jTextField8.setText(Integer.toString(getFirstPlaceScore()));
                    JavaArduino.leaderboards.jTextField9.setText(Integer.toString(getSecondPlaceScore()));
                    JavaArduino.leaderboards.jTextField10.setText(Integer.toString(getThirdPlaceScore()));
                    JavaArduino.leaderboards.jTextField11.setText(Integer.toString(getFourthPlaceScore()));
                    JavaArduino.leaderboards.jTextField12.setText(Integer.toString(getFifthPlaceScore()));

                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

        }
    }
}
