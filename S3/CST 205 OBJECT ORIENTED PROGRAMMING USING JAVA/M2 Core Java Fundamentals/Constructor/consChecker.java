class Cons
{
    Cons()
    {
        this(1);
        System.out.println("Inside non parameterized");
    }
    Cons(int a)
    {
        this(a, 3);
        System.out.println("Inside one parameterized");
    }
    Cons(int b, int c)
    {
        System.out.println("Inside two paramterized constructor. Sum = "+(b+c));
    }
}

public class consChecker {
    public static void main(String[] args) {
        Cons r = new Cons();
    }
}
