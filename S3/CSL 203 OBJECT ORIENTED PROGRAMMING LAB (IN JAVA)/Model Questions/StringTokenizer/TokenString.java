package StringTokenizer;
import java.util.*;

public class TokenString 
{
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(sc.nextLine());
        System.out.print("Entered numbers --> ");
        while(st.hasMoreTokens())
        {
            int i = Integer.parseInt(st.nextToken());
            sum += i;
            System.out.print("\t"+i);
        }
        System.out.println("\nSum of numbers = "+sum);
        sc.close();
    }    
}
