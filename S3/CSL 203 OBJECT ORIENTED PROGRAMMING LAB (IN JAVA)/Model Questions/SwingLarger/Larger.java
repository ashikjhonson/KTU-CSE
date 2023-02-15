package SwingLarger;

import javax.swing.*;
import java.awt.event.*;

public class Larger extends JFrame implements ActionListener{
    JTextField num1, num2, res;
    JButton calc;

    Larger()
    {
        setTitle("Larger");

        num1 = new JTextField();
        num1.setBounds(20, 20, 180, 30);
        add(num1);
        JLabel number1 = new JLabel("Number1");
        number1.setBounds(60, 60, 100, 30);
        add(number1);

        num2 = new JTextField();
        num2.setBounds(260, 20, 180, 30);
        add(num2);
        JLabel number2 = new JLabel("Number2");
        number2.setBounds(280, 60, 100, 30);
        add(number2);

        res = new JTextField();
        res.setBounds(150, 140, 150, 30);
        add(res);
        JLabel rest = new JLabel("Result");
        rest.setBounds(90,135,50,30);
        add(rest);

        calc = new JButton("Calculate");
        calc.setBounds(170,185,100,30);
        add(calc);
        calc.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(460,300);
        setLayout(null);
        setVisible(true);
        
    }

    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource()==calc)
        {
            try {
                int a = Integer.parseInt(num1.getText());
                int b = Integer.parseInt(num2.getText());
                int l = a>b?a:b;
                res.setText(String.valueOf(l));
            } catch (Exception ex) {
                System.out.println(ex);
            }
        }
    }

    public static void main(String[] args) {
        new Larger();
    }
    
}
