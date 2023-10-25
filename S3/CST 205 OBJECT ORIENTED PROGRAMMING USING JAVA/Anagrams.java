import java.util;
public class Anagrams
{
       public static void main(String[] args)
    {
        String s = "silent";
        String t = "listen";
        char[] se = new char[10];
        char[] te = new char[10];

        for(int i=0; i<s.length();i++)
        se[i]=s.charAt(i);

        for(int i=0; i<t.length();i++)
        te[i]=t.charAt(i);

    }
}