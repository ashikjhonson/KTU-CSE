class Super
{
    public interface isPositiveNum
    {
        boolean isPositive(int n);
    }
}

class sub implements Super.isPositiveNum
{
    public boolean isPositive(int n)
    {
        return n>0?true:false;
    }
}
public class NestedInterface {
    public static void main(String[] args) {
        sub obj = new sub();
        System.out.println("10 is positive: "+obj.isPositive(10));
        System.out.println("0 is positive: "+obj.isPositive(0));
        System.out.println("-10 is positive: "+obj.isPositive(-10));
    }
}
