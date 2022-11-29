//Java program to reverse a number
//By navendu c

import java.util.Scanner;
class Reverse{
    public static void main(String a[])
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number to reverse\n");
        int num = input.nextInt();
        int temp = num;
        int rem = 0;
        int result = 0;
        while(num>0)
        {
            rem = num%10;
            result = ((result*10)+rem);
            num/=10;
        }
        System.out.println("Reverse of "+temp+" is "+result);
    }
}
