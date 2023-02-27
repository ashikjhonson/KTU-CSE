import java.util.Scanner;

class ageException extends Exception{
}

public class userDefinedEx
{
    public static void main(String[] args) throws ageException
    {    
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your age: ");
        int age = sc.nextInt();
        try
        {
            if(age<18)
                throw new ageException();
            System.out.println("Welcome");
        }
        catch(ageException a)
        {
            System.out.println("Under age!, 18+ only");
        }
    }
}
