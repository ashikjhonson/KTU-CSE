package MyThread;
import java.util.Random;

class Number extends Thread
{
    Random r = new Random();
    public void run()
    {
        for(int i=0; i<10; i++)
        {
            try {
                int n = r.nextInt(100);
                System.out.println("Number generated: "+n);
                if(n%2==0)
                {
                    Fact f = new Fact(n);
                    f.start();
                }
                else
                {
                    Root r =new Root(n);
                    r.start();
                }
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}

class Fact extends Thread
{
    int n;
    Fact(int n)
    {
        this.n = n;
    }
    public void run()
    {
        System.out.println("Factorial: "+n);
    }
}

class Root extends Thread
{
    int n;
    Root(int n)
    {
        this.n = n;
    }
    public void run()
    {
        System.out.println("Root: "+n);
    }
}

class MyThread
{
    public static void main(String[] args) {
        Number nt = new Number();
        nt.start();
    }
}