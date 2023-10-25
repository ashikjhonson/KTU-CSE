/*input file - 1634
* output file - 1634 Is armstrong
*/
package ArmstrongFile;

import java.util.*;
import java.io.*;

class Armstrong 
{
    public static void main(String[] args) 
    {
        File f = null;
        try 
        {
            int sum = 0;
            f = new File("ArmstrongFile/input.txt");
            Scanner sc = new Scanner(f);
            int n = sc.nextInt();
            int x = n, temp = n, digits = 0;

            while(temp>0)
            {
                temp /= 10;
                digits++;
            }

            while(n>0)
            {
                int r = n%10;
                sum += (int)Math.pow(r, digits);
                n/=10;
            }

            String out = String.valueOf(x);

            if(x==sum)
                out += " Is armstrong";
            else
                out += " Is not armstrong";

            BufferedWriter bw = new BufferedWriter(new FileWriter("ArmstrongFile/output.txt"));
            bw.append(out);
            bw.flush();
            bw.close();

            sc.close();
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }
}