/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prenk;

import java.awt.event.WindowEvent;

//import java.sql.Connection;
//import java.sql.DriverManager;
//import java.sql.ResultSet;
//import java.sql.SQLException;
//import java.sql.Statement;



/**
 *
 * @author poepert
 */
public class saldo extends javax.swing.JFrame {

    /**
     * Creates new form saldo
     */
    public saldo() {
        initComponents();
      //  saldoAmount sal = new saldoAmount();
      //float amount = sal.getSal();
        //String s = Integer.toString(amount);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jBack3 = new javax.swing.JButton();
        jSaldoField = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("EL BANKO");

        jBack3.setText("terug");
        jBack3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jBack3ActionPerformed(evt);
            }
        });

        jSaldoField.setEditable(false);
        jSaldoField.setText(" ");
        jSaldoField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jSaldoFieldActionPerformed(evt);
            }
        });

        jLabel2.setText("€");

        jLabel3.setText("Uw saldo");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(140, Short.MAX_VALUE)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 235, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(25, 25, 25))
            .addGroup(layout.createSequentialGroup()
                .addGap(66, 66, 66)
                .addComponent(jLabel3)
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jBack3)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jSaldoField, javax.swing.GroupLayout.PREFERRED_SIZE, 83, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(140, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(31, 31, 31)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 82, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jSaldoField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3))
                .addGap(72, 72, 72)
                .addComponent(jBack3)
                .addGap(44, 44, 44))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jBack3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jBack3ActionPerformed
            scherm2 gui6 = new scherm2();
            gui6.setVisible(true);
            dispose();        // TODO add your handling code here:
    }//GEN-LAST:event_jBack3ActionPerformed
 //private void jPanel1InputMethodTextChanged(java.awt.event.InputMethodEvent evt) {                                               
   // TODO add your handling code here:
   // }                                              
 
    private void jSaldoFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jSaldoFieldActionPerformed
jSaldoField.setText(String.valueOf(Prenk.getmoney()));         // TODO add your handling code here:
    }//GEN-LAST:event_jSaldoFieldActionPerformed


    private void jSaldoFieldInputMethodTextChanged(java.awt.event.InputMethodEvent evt) {                                                   
      // TODO add your handling code here:
    }                                                  

    private void jSaldoFieldComponentShown(java.awt.event.ComponentEvent evt) {                                           
        // TODO add your handling code here:
    }                                          

    private void jSaldoFieldMouseDragged(java.awt.event.MouseEvent evt) {                                         
       // TODO add your handling code here:
    }                                        

    private void jSaldoFieldMouseMoved(java.awt.event.MouseEvent evt) {                                       
Prenk prenk = new Prenk();
 
float money = prenk.getmoney();
// System.out.println(q);
//String s = Integer.toString(amount);
//System.out.println(amount);
jSaldoField.setText(String.valueOf(Prenk.getmoney()));        // TODO add your handling code here:
    }          
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
       Prenk.getmoney();
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(saldo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(saldo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(saldo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(saldo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new saldo().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jBack3;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JTextField jSaldoField;
    // End of variables declaration//GEN-END:variables

}