package SecLargest;

class Number
{
    protected int limit;
    Number(int l)
    {
        limit = l;
    }
}

class Compute extends Number
{
    Compute(int limit)
    {
        super(limit);
    }

    void secLargest(int arr[])
    {
        int largest = arr[0];
        int secondLargest = arr[0];
        
        for(int i=1; i<limit; i++)
        {
            if(arr[i]>largest)
            {
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i]>secondLargest)
            {
                secondLargest = arr[i];
            }
        }
        System.out.println("Second largest number is: " + secondLargest);
    }
}

class Main{
    public static void main(String[] args) {
        int arr[] = {10,22,20,2,1};
        int limit = arr.length;

        Compute c = new Compute(limit);
        c.secLargest(arr);
    }
}