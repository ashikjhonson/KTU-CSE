import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class FileHandling 
{
    public static void main(String[] args) throws IOException
    {
        File f = new File("Hello.txt");
        try 
        {
            if(!f.exists())    
                f.createNewFile();
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("File name: "+f.getName()+"\nFile path: "+f.getPath());
        System.out.println("Can read: "+f.canRead());
        System.out.println("Size: "+f.length());

        FileInputStream fin = null;
        FileOutputStream fout = null;

        int i;

        FileWriter fw = new FileWriter(f);
        String str = "Hello, Ashik";
        for(i = 0; i<str.length(); i++)
            fw.write(str.charAt(i));
        fw.close();

        FileReader fr = new FileReader(f);
        BufferedReader br = new BufferedReader(fr);
        String s = br.readLine();
        System.out.println(s);
        fr.close();
        try
        {
            fin = new FileInputStream(f);
            do{
                i=fin.read();
                if(i!=-1)
                    System.out.print((char)i);
            }while(i!=-1);
        }
        catch(Exception e)
        {
            return;
        }
        fin.close();
    }    
}
