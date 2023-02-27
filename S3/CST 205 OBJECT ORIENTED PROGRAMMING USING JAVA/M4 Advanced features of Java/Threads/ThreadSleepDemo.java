public class ThreadSleepDemo {
    public static void main(String[] args)
    {
        Thread t = Thread.currentThread();
        System.out.println(t+"Thread sleeping for 5 seconds(5000ms)");
        try 
        {
            Thread.sleep(5000);
        } 
        catch (InterruptedException e) {
            
            e.printStackTrace();
        }
        System.out.println("After 5 seconds");
    }
}
