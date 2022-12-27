import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Calculator extends JFrame implements ActionListener
{
    JButton numButtons[] = new JButton[10];
    JButton funButtons[] = new JButton[7];
    JButton add, sub, mul, div, dec, clr, eql;
    JTextField textfield;
    JPanel panel;

    double num1=0, num2=0, result=0;
    char op;

    Calculator()
    {
        super("Calculator");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // TextField
        textfield = new JTextField();
        textfield.setBounds(10,25,200,40);
        textfield.setEditable(false);
        add(textfield);

        // Function Buttons
        add = new JButton("+");
        sub = new JButton("-");
        mul = new JButton("*");
        div = new JButton("/");
        dec = new JButton(".");
        clr = new JButton("C");
        eql = new JButton("=");
        funButtons[0] = add;
        funButtons[1] = sub;
        funButtons[2] = mul;
        funButtons[3] = div;
        funButtons[4] = dec;
        funButtons[5] = clr;
        funButtons[6] = eql;


        for(int i = 0; i<10; i++)
        {
            numButtons[i] = new JButton(String.valueOf(i));
            numButtons[i].addActionListener(this);
            numButtons[i].setFocusable(false);
            if(i<7)
            {
                funButtons[i].addActionListener(this);
                funButtons[i].setFocusable(false);
            }
        }


        eql.setBounds(200,25,50,40);
        add(eql);


        panel = new JPanel();
        panel.setBounds(10,70,240,160);
        panel.setLayout(new GridLayout(4,4));

        panel.add(numButtons[1]);
        panel.add(numButtons[2]);
        panel.add(numButtons[3]);
        panel.add(add);
        panel.add(numButtons[4]);
        panel.add(numButtons[5]);
        panel.add(numButtons[6]);
        panel.add(sub);
        panel.add(numButtons[7]);
        panel.add(numButtons[8]);
        panel.add(numButtons[9]);
        panel.add(div);
        panel.add(dec);
        panel.add(numButtons[0]);
        panel.add(clr);
        panel.add(mul);
        add(panel);


        setSize(270,300);
        setLayout(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new Calculator();
    }

    public void actionPerformed(ActionEvent e)
    {

    }
}
