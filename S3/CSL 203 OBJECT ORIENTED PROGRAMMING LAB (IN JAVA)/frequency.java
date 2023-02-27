import java.util.Scanner;
class frequency
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = sc.nextLine();
        System.out.print("\nEnter a character to be checked: ");
        char a = sc.next().charAt(0);
        int count = 0;
        for(int i =0; i<s.length(); i++)
        {
            if(s.charAt(i)==a)
                count++;
        }
        System.out.println("Frequency: "+count);
    }
}
