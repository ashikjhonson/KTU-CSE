import java.util.*;
import java.io.*;

class FilePrime
{
	public static void main(String [] args)
	{
		FileInputStream fin = null;
		String prime = "";
		try
		{
			fin = new FileInputStream("Java/FilePrime/input.txt");
			Scanner sc = new Scanner(fin);
			int a = sc.nextInt();
			int b = sc.nextInt();
			System.out.println("'input.txt' contains: "+a+", "+b);
			for(int i=a; i<=b; i++)
			{
				int flag = 0;
				for(int j=2; j<=i/2&&flag==0; j++)
				{
					if(i%j==0)
						flag+=1;
				}
				if(flag==0)
				{
					prime += String.valueOf(i) + " ";
				}
			}
			BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt",false));
			bw.append(prime);	
			bw.flush();
			bw.close();
			sc.close();
			
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}

