/*
Implement a Java program to create a text file and copy the file into
a second file. Also append the number of words in that file. Use
appropriate exception handling techniques.
@Author: Ashik Jhonson
*/

import java.io.*;
import java.util.*;

class FileHandling_copying
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int j=0, i, count =0;
        FileInputStream fin = null, f = null;
        FileOutputStream fout = null;

        try{
            File file1 = new File("one.txt");
            if(!file1.exists())
                file1.createNewFile();

            File file2 = new File("two.txt");
            if(!file2.exists())
                file2.createNewFile();
            
            System.out.println("Enter a string: "); // Reading string from user
            String s = sc.nextLine();

            // Counting the no. of words in string
            StringTokenizer st1 = new StringTokenizer(s);
            while (st1.hasMoreTokens()) 
                {
                    st1.nextToken();
                    count++;
                }
            
            // To write data into 'one.txt'
            fout = new FileOutputStream("one.txt");
            do{
                i = (byte)s.charAt(j);
                fout.write(i);
                j++;
                
            }while(j<s.length());

            // Writing data into 'two.txt' by reading from 'one.txt'
            fin = new FileInputStream("one.txt");
            fout = new FileOutputStream("two.txt");
            do
            {
                i = fin.read();
                if(i!=-1)
                    fout.write(i);
            }while(i!=-1);
            String out = "\nNumber of words: "+count;
            BufferedWriter bw = new BufferedWriter(new FileWriter("two.txt", true));
            bw.append(out);
            bw.flush();
            bw.close();

            // FileInputStream from 'two.txt'
            f = new FileInputStream("two.txt"); 
            System.out.println("\nInside file 'two.txt': ");
            do{
                i = f.read();
                if(i!=-1)
                    System.out.print((char)i);
            }while(i!=-1);
        }
        catch(IOException e)
        {
            System.out.println(e);
        }
        catch(Exception d)
        {
            System.out.println(d);
        }
        finally
        {
            System.out.println("\n\nCompleted execution");
        }
    }
}
