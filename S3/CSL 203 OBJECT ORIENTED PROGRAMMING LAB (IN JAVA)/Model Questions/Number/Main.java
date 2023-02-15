interface Number {
  void display();
}

class NoDuplicate implements Number {
  private int[] arr;

  public NoDuplicate(int[] arr) {
    this.arr = arr;
  }

  public void display() {
    int[] temp = new int[arr.length];
    int index = 0;
    for (int i = 0; i < arr.length; i++) {
      boolean isDuplicate = false;
      for (int j = i + 1; j < arr.length; j++) {
        if (arr[i] == arr[j]) {
          isDuplicate = true;
          break;
        }
      }
      if (!isDuplicate) {
        temp[index++] = arr[i];
      }
    }
    int[] result = new int[index];
    for (int i = 0; i < index; i++) {
      result[i] = temp[i];
    }
    System.out.print("NoDuplicate Result: ");
    for (int i : result) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
}

class Sum implements Number {
  private int num;

  public Sum(int num) {
    this.num = num;
  }

  public void display() {
    int sum = 0;
    int temp = num;
    while (temp > 0) {
      int digit = temp % 10;
      sum += digit;
      temp /= 10;
    }
    System.out.println("Sum Result: " + sum);
  }
}

public class Main {
  public static void main(String[] args) {
    int[] arr = { 1, 2, 3, 4, 5, 6, 2, 4, 6 };
    Number number = new NoDuplicate(arr);
    number.display();

    int num = 12345;
    number = new Sum(num);
    number.display();
  }
}

