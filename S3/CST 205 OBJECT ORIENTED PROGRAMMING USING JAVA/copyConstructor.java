class Rectangle
{
    int length, breadth;
    
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    Rectangle(Rectangle r)
    {
        this.length = r.length;
        this.breadth = r.breadth;
    }

    void printRect()
    {
        System.out.println("\nLength: "+length+"\nBreadth: "+breadth);
    }
}

class copyConstructor
{
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(2,3);
        r1.printRect();
        Rectangle r2 = new Rectangle(r1);
        r2.printRect();
    }
}