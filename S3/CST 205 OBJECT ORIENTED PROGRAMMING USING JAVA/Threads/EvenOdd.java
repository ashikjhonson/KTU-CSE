class Number
{
    void printnum(String name, int i)
    {
        System.out.println(name+": "+i);
    }
}

class Even extends Thread
{
    Number num;
    String name;
    Even(Number num, String name)
    {
        this.num = num;
        this.name = name;
    }

    public void run()
    {
        synchronized(num)
        {
            for(int i = 0; i<=100; i += 2)
                num.printnum(name, i);
        }
    }
}

class Odd extends Thread
{
    String name;
    Number num;
    Odd(Number num, String name)
    {
        this.num = num;
        this.name = name;
    }

    public void run()
    {
        synchronized(num)
        {
            for(int i = 1; i<100; i+=2)
                num.printnum(name, i);
        }
    }
}

public class EvenOdd 
{
    public static void main(String[] args) 
    {
        Number n = new Number();
        Even e = new Even(n, "Even");
        Odd o = new Odd(n, "Odd");
        e.start();
        o.start();
    }
}