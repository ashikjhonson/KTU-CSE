/*
 * JAVA GUI Traffic Light program
 * written by Ashik 
 * 20-12-2022
 */

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class trafficLight extends JFrame implements ActionListener
{
    JRadioButton red, yellow, green;
    trafficLight()
    {
        setTitle("Traffic Light System");
        red = new JRadioButton("Red");
        yellow = new JRadioButton("Yellow");
        green = new JRadioButton("Green");
        ButtonGroup bg = new ButtonGroup();
        bg.add(red);
        bg.add(yellow);
        bg.add(green);
        red.setBounds(50, 100, 100, 20);
        yellow.setBounds(50, 140, 100, 20);
        green.setBounds(50, 180, 100, 20);
        add(red);
        add(yellow);
        add(green);
        red.addActionListener(this);
        yellow.addActionListener(this);
        green.addActionListener(this);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
        setSize(400,400);
        setVisible(true);
    }

    public void paint(Graphics g)
    {
        g.setColor(Color.BLACK);
        g.drawRect(250,110,70,155);
        g.fillRect(250,110,70,155);
        g.drawOval(265, 120, 40, 35);
        g.drawOval(265, 170, 40, 35);
        g.drawOval(265, 220, 40, 35);
        
        if(red.isSelected())
        {
            g.setColor(Color.RED);
            g.fillOval(265, 120, 40, 35);
        }
        else if(yellow.isSelected())
        {
            g.setColor(Color.YELLOW);
            g.fillOval(265, 170, 40, 35);
        }
        else if(green.isSelected())
        {
            g.setColor(Color.GREEN);
            g.fillOval(265, 220, 40, 35);
        }
    }

    public void actionPerformed(ActionEvent e)
    {
        repaint();
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(new Runnable()
        {
            public void run()
            {
                new trafficLight();
            }
        });
    }
}
