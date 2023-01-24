class Thread1 extends Thread
{
    public void run()
    {
        System.out.println("1+2=3");
    }
    public static void main(String[] args) {
        Thread1 t = new Thread1();
        t.start();
    }
}