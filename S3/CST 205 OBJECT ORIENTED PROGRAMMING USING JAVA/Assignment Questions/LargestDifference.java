/*
@ author Jestin
*/
import java.util.Scanner;
class LargestDifference
{
    Scanner sc = new Scanner(System.in);
    int n;
    int a[] ;
    Array(int n)
    { 
        this.n = n;
        a = new int[n];
    }
    void readArr()
    {
        System.out.println("Enter the  elements:");
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
    }
    class Repeat
    {
        int var1,var2;
        void larDifference()
        {
            int diff = a[1] - a[0];
            var1 = a[1];
            var2 = a[0];
            int i, j;
            for (i = 0; i < n; i++)
            {
                for (j = i+1; j < n; j++)
                {        
                    if (a[j] - a[i] > diff) { 
                        diff = a[j] - a[i];
                        var1 = a[j];
                        var2 = a[i];}
                }    
            }
            System.out.println("Maximum difference is " +diff+" with elements "+var1+" and "+var2);
        }
    }
    public static void main(String args[])
    {
       
    Scanner sc=new Scanner(System.in);
    try{
          System.out.println("Enter the number of elements:");
          int n = sc.nextInt();
          Array obj=new Array(n);
          obj.readArr();
          Array.Repeat in = obj.new Repeat();
          in.larDifference();
       }
    catch(Exception e)
       {
          System.out.println(e);
       }
    }
    
}
