interface printText
{
    void text(String txt);
}

class interfaces1 implements printText
{
    public void text(String txt)
    {
        System.out.println(txt);
    }
    public static void main(String[] args) 
    {
        interfaces1 obj = new interfaces1();
        obj.text("Interface demo");    
    }
}