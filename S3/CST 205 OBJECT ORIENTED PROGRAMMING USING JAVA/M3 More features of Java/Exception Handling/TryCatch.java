import java.util.Random;
class TryCatch
{
    public static void main(String[] args) 
    {
        Random r = new Random();
        int a = 4;
        for(int  i =0; i<10; i++)
        {
            int b = r.nextInt(2);

            try 
            {
            int c = a/b;
            System.out.println(b);
            } 
            catch (ArithmeticException e) {
                System.out.println("Division by zero not possible.");
               System.out.println("  B value generated is "+b+" by java.util.Random class\n");
            }

        }
    }
}