package FiboFile;

import java.io.*;
import java.util.Scanner;

public class Fib {

    int fib(int n)
    {
        if(n==0)
            return 0;
        else if(n==2||n==1)
            return 1;
        return fib(n-2) + fib(n-1);
    }

    public static void main(String[] args) {
        Fib f = new Fib();
        FileInputStream fin = null;

        try{
            fin = new FileInputStream("FiboFile/input.txt");
            Scanner sc = new Scanner(fin);
            int a = 0;
            int b = sc.nextInt();
            String fib = "";
            while(a<=b)
            {   
                fib += String.valueOf(f.fib(a))+" ";
                a++;
            }
            File fout = new File("FiboFile/output.txt");
            if(!fout.exists())
            {
                fout.createNewFile();
            }
            BufferedWriter bw = new BufferedWriter(new FileWriter(fout));
            bw.append(fib);
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
