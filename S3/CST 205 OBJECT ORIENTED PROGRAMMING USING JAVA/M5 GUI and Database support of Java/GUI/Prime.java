/*
* @ Author Ashik
*/
import javax.swing.*;
import java.awt.Color;
import java.awt.event.*;

class Prime extends JFrame implements ActionListener
{
    JTextField t;
    JButton submit, result, clear;
    public int flag=0;
    Prime()
    {
        JLabel text = new JLabel("Enter: ");
        text.setBounds(20,20,50,50);
        add(text);

        t = new JTextField();
        t.setBounds(90,20,110, 50);
        add(t);

        submit = new JButton("Submit");
        submit.setBounds(20,90,80, 40);
        add(submit);
        submit.addActionListener(this);

        result = new JButton("Result");
        result.setBounds(110,90,80, 40);
        add(result);
        result.addActionListener(this);

        clear = new JButton("Clear");
        clear.setBounds(200,90,80,40);
        add(clear);
        clear.addActionListener(this);
        
        getContentPane().setBackground(new Color(123,50,250));
        setTitle("Prime checker");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        setSize(330,300);
        setVisible(true);
        setResizable(false);
    }

    public void actionPerformed(ActionEvent e)
    {
        String s=null;
        
        if(e.getSource()==submit)
        {
            int n=1;
            try
            {   
                s = t.getText();
                n = Integer.parseInt(s);
            }
            catch(Exception es)
            {
                t.setText("");
            }
            
            flag = 0 ;
            for(int i = 1; i<=n; i++)
            {
                if(n%i==0)
                    flag=flag+1;
            }
            t.setText("Click Result");
        }

        if(e.getSource()==result)
        {
            if(flag==2)
                t.setText("Prime Number");
            else
                t.setText("Not Prime");
        }

        if(e.getSource()==clear)
            t.setText("");
    }
    public static void main(String args[])
    {
        SwingUtilities.invokeLater(new Runnable()
        {
            public void run()
            {
                new Prime();
            }
        });
    }
}