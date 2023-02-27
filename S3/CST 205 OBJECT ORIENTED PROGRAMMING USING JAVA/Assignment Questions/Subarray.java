//Java program to generate subarrays of specified size of the given array
//By Navendu C 
import java.util.Scanner;

class Subarray{
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

  //create and read array
  System.out.println("Enter array size");
  int size = s.nextInt();
  int arr[] = new int[size];
  System.out.println("Enter array elements");
  for(int i = 0;i<size;i++){
    arr[i] = s.nextInt();
  }

  //find subarray
  System.out.println("Enter subarray size");
  int sub = s.nextInt();
  int current_pos = 0;
  int begin_pos = 0; //store the beginning position of next subarray

  System.out.println("The subarrays are: ");
  for(begin_pos=0;begin_pos+sub<=size;begin_pos++){
    current_pos = begin_pos; //assigning the begin position of next subarray to current position
    for(int i = 0;i<sub;i++){
      System.out.print(arr[current_pos]+" ");
      current_pos++;
      }
    System.out.println(" ");
    }
 }
  

}
