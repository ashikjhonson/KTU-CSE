package GUI;
import javax.swing.*;
public class frame extends JFrame
{
    JLabel jl;
    frame()
    {
        super("Frame");
        jl = new JLabel("Hi", JLabel.CENTER);
        jl.setBounds(150, 150, 20, 20);
        add(jl);
        setSize(300,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public static void main(String[] args) {
        new frame();
    }
}
