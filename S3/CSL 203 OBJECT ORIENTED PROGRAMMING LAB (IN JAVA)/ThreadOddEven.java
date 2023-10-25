package Thread;

class Number
{
    void printnum(String name, int i)
    {
        System.out.println(name+"- "+i);
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
            for(int i=0; i<101; i+=2)
                num.printnum(name, i);
        }
    }
}

class Odd extends Thread
{
    Number num;
    String name;
    Odd(Number num, String name)
    {
        this.num = num;
        this.name = name;
    }

    public void run()
    {
        synchronized(num)
        {
            for(int i=1; i<100; i+=2)
                num.printnum(name, i);
        }
    }
}

class OddEven
{
    public static void main(String[] args) {
        Number num = new Number();
        Even e = new Even(num, "even");
        Odd o = new Odd(num, "odd");
        e.start();
        o.start();
    }
}