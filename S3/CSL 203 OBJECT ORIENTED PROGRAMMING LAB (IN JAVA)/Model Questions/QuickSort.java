class QuickSort
{
    public static void sort(int arr[])
    {
        quickSort(arr,0, arr.length-1);
    }

    public static void quickSort(int arr[], int l, int h)
    {
        if(l<h)
        {
            int pivot = partition(arr,l,h);
            quickSort(arr, l, pivot-1);
            quickSort(arr, pivot+1, h);
        }
    }

    public static int partition(int arr[], int l, int h)
    {
        int pivot = arr[h];
        int i=l-1;
        for(int j=l; j<h; j++)
        {
            if(arr[j]<pivot)
            {
                i++;
                swap(arr,i,j);
            }
        }
        swap(arr,i+1,h);
        return i+1;
    }

    private static void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void display(int arr[])
    {
        for(int i=0; i<arr.length; i++)
            System.out.print("  "+arr[i]);
        System.out.println();
    }

    public static void main(String[] args) {
        int arr[] = {1,0,-2,3,4,-5};
        display(arr);
        sort(arr);
        display(arr);
    }
}