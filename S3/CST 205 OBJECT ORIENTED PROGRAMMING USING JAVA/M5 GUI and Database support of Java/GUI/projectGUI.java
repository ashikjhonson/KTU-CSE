import javax.swing.*;
import java.awt.*;

public class projectGUI extends JFrame
{
    JTextField reg, name, m1, m2, m3, check, total, rank;
    JButton submit;
    projectGUI()
    {
        super("Student Management System");
        
        JLabel regn = new JLabel("Reg. No.");
        regn.setBounds(30,20,60,30);
        add(regn);
        reg = new JTextField();
        reg.setBounds(100,20,140,30);
        add(reg);

        JLabel namen = new JLabel("Name");
        namen.setBounds(300,20,60,30);
        add(namen);
        name = new JTextField();
        name.setBounds(350, 20, 210, 30);
        add(name);
        
        JLabel m1n = new JLabel("Mark 1");
        m1n.setBounds(75,110,100,20);
        add(m1n);
        m1 = new JTextField();
        m1.setBounds(30,80,130,30);
        add(m1);

        JLabel m2n = new JLabel("Mark 2");
        m2n.setBounds(275,110,100,20);
        add(m2n);
        m2 = new JTextField();
        m2.setBounds(230,80,130,30);
        add(m2);
        
        JLabel m3n = new JLabel("Mark 3");
        m3n.setBounds(475,110,100,20);
        add(m3n);
        m3 = new JTextField();
        m3.setBounds(430,80,130,30);
        add(m3);

        submit = new JButton("Submit");
        submit.setBounds(230,150,130,30);
        add(submit);

        JLabel checkn = new JLabel("Check");
        checkn.setBounds(170,240,60,25);
        add(checkn);
        check = new JTextField();
        check.setBounds(230,240,130,30);
        add(check);

        JLabel totn = new JLabel("Total Marks");
        totn.setBounds(30,300,70,30);
        add(totn);
        total = new JTextField();
        total.setBounds(120,300,130,30);
        add(total);

        JLabel rankn = new JLabel("Rank");
        rankn.setBounds(310,300,40,30);
        add(rankn);
        rank = new JTextField();
        rank.setBounds(350,300,130,30);
        add(rank);
        
        setSize(610,420);
        setResizable(false);
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new projectGUI();
    }
}
