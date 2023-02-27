class Num
{
    void printnum(String name, int i)
    {
        System.out.println(name+": "+i);
    }
}

class Evenn extends Thread
{
    Num num;
    String name;
    Evenn(Num num, String name)
    {
        this.num = num;
        this.name = name;
    }

    public void run()
    {
        synchronized(num)
        {
            for(int i = 0; i<=100; i+=2)
                num.printnum(name, i);
        }
    }
}

class Oddn extends Thread
{
    String name;
    Num num;

    Oddn(Num num, String name)
    {
        this.num = num;
        this.name = name;
    }

    public void run()
    {
        synchronized(num)
        {
            for(int i =1; i<100; i++)
                num.printnum(name, i);
        }
    }
}

class NumTest
{
    public static void main(String[] args) {
        Num num = new Num();
        Evenn e =new Evenn(num, "Even");
        Oddn o = new Oddn(num, "Odd");
        e.start();
        o.start();
    }
}