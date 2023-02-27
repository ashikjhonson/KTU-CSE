package SwingPrime;

import javax.swing.*;
import java.awt.event.*;

public class Prime extends JFrame implements ActionListener
{
    JTextField num, res;
    JButton cal;
    Prime()
    {
        super("Prime number checker");
        
        JLabel number = new JLabel("Number");
        number.setBounds(20,13,50,20);
        add(number);
        num = new JTextField();
        num.setBounds(90,10,200,30);
        add(num);

        JLabel result = new JLabel("Result");
        result.setBounds(20, 63, 50, 20);
        add(result);
        res = new JTextField();
        res.setBounds(90,60,200,30);
        add(res);

        cal = new JButton("Calculate");
        cal.setBounds(120, 120, 100, 30);
        add(cal);
        cal.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(350,220);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        int flag = 0;
        if(e.getSource()==cal)
        {
            try {
                int n = Integer.parseInt(num.getText());
                for (int i = 2; i <= n / 2; i++) {
                    if (n % i == 0)
                        flag = 1;
                    if (flag != 0)
                        break;
                }
                if(flag==0)
                    res.setText("Prime");
                else
                    res.setText("Not prime");
                    
            } catch (Exception ex) {
                System.out.println(ex);
            }
        }
    }

    public static void main(String[] args) {
        new Prime();
    }
}
