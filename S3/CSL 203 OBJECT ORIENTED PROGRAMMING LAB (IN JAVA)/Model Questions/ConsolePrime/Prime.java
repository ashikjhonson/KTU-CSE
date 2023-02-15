import java.io.*;

public class Prime {
    public static void main(String[] args) {
        int flag = 0;
        String out = "";
        try {
            int n = Integer.parseInt(args[0]);
            for (int i = 2; i <= n / 2; i++) {
                if (n % i == 0)
                    flag = 1;
                if (flag != 0)
                    break;
            }
            if (flag == 0)
                out += String.valueOf(n) + " is Prime";
            else
                out += String.valueOf(n) + " is not prime";

            BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));
            bw.append(out);
            bw.flush();
            bw.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
