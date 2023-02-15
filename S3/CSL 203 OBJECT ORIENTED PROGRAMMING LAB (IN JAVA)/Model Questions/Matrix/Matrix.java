import java.util.*;

class Matrix
{	
	void input(int matrix[][], int m, int n)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter matrix elements");
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				matrix[i][j] = sc.nextInt();
			}
		}
		sc.close();
	}
	
	void output(int matrix[][], int m, int n)
	{
		System.out.println("Entered matrix");
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				System.out.print(matrix[i][j]+"\t");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		MatTranspose mat = new MatTranspose();
		int m, n;
		System.out.print("Enter no. of row(s): ");
		m = sc.nextInt();
		System.out.print("Enter no. of col(s): ");
		n = sc.nextInt();
		int matrix[][] = new int[m][n];
		mat.input(matrix, m, n);
		mat.output(matrix, m, n);
		mat.transpose(matrix, m, n);
		sc.close();
	}
}

class MatTranspose extends Matrix
{	
	void transpose(int matrix[][], int m, int n)
	{
	 
		int trans[][] = new int[n][m];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				trans[i][j] = matrix[j][i];
			}
		}
		
		System.out.println("\n Transpose matrix");
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				System.out.print(trans[i][j]+"\t");
			}
			System.out.println();
		}
	
	}
}
