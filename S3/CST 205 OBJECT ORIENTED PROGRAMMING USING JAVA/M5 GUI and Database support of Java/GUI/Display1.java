import java.awt.Color;

import javax.swing.JFrame;
public class Display1 {
    public static void main(String[] args) {
        JFrame jf = new JFrame();
        jf.setTitle("Welcome Page");
        jf.setVisible(true);
        jf.setSize(300,300);
        jf.setResizable(false);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.getContentPane().setBackground(new Color(123,50,250));
    }
}