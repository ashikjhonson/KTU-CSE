class value
{
    int a, b;
    value(int m, int n)
    {
        a =-1;
        b =-2;
    }
}

class reference
{
    int a, b;
    reference(int m, int n)
    {
        a = m;
        b = n;
    }
    void reset(reference r)
    {
        r.a = 0;
        r.b = 0;
    }
}

public class callByValue {
    public static void main(String[] args) {
        int a = 2, b= 3;

        System.out.println("Call by value");
        System.out.println("Values: "+a+" "+b);
        value v = new value(a,b);
        System.out.println("Values: "+a+" "+b);

        System.out.println("\nReference");
        reference c = new reference(a, b);
        System.out.println("Values: "+c.a+" "+c.b);
        c.reset(c);
        System.out.println("Values: "+c.a+" "+c.b);
    }
}
