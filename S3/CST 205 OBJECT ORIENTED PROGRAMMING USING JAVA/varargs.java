public class varargs 
{
    static void vaTest(int...v)
    {
        System.out.println("Number of args: "+v.length+" Contents: ");;
        for(int x:v)
            System.out.print(x+ " ");
        System.out.println("\n");
    }
    public static void main(String[] args) 
    {
        //System.out.println("Hi");
        int n1[] = {1,2,3};
        int n2[]= {4};
        int n3[] = {};
        vaTest(n1);
        vaTest(n2);
        vaTest(n3);
    }
}
