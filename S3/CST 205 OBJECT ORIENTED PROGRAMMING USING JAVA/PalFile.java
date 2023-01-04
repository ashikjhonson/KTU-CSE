// @ Ashik 

import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class PalFile 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        try
        {
            File file = new File("text.txt");
            if(!file.exists())
                file.createNewFile();
                
            File pal = new File("pal.txt");
            if(!pal.exists())
                pal.createNewFile();

            FileInputStream fin = new FileInputStream(file);
            System.out.print("Enter a string: ");
            String s = sc.nextLine();
            FileOutputStream fout = new FileOutputStream(file);

            // Writing string to file 'text.txt'
            int t = s.length(), i=0;
            do
            {
                fout.write(s.charAt(i++));
            }while(i<t);

            Scanner fsc = new Scanner(file);
            String str = fsc.nextLine();
            fsc.close();
            String arr[] = new String[100];
            StringTokenizer st = new StringTokenizer(str); // To split string to words
            i=0; 
            int count=0;
            FileOutputStream fpal = new FileOutputStream(pal);
            System.out.println("\n\n\nInside file 'pal.txt':");
            while(st.hasMoreTokens())
            {
                arr[i] = st.nextToken();
                s = arr[i];
                StringBuilder rev = new StringBuilder(s);
                String sr = rev.reverse().toString();
                String ws = " ";
                if(s.equals(sr)) // In case of palindrome words
                {
                    count++;
                    i=0;
                    t=s.length();
                    do
                    {
                        fpal.write(s.charAt(i++));
                    }while(i<t);
                    fpal.write(ws.charAt(0)); // Adding whitespace btw words
                }
                i++;
            }
            String output = "\nNumber of  Palindrome words in file: "+count;
            BufferedWriter fb = new BufferedWriter(new FileWriter("pal.txt", true));
            fb.append(output); // Appending no. of palindrome words
            fb.flush();
            fb.close();
            FileInputStream finp = new FileInputStream("pal.txt");
            do
            {
                i = finp.read();
                if(i!=-1)
                    System.out.print((char)i);
            }while(i!=-1);
        }   
        catch(FileNotFoundException e)
        {
            System.out.println(e);
        }
        catch(IOException e)
        {
            System.out.println(e);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
