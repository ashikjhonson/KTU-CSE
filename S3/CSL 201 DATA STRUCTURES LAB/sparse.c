/*
*C Program to represent a sparse matrix in triple form
*Date : 23/10/2022
*Editor : VS Code 
*By Ashik Jhonson
*/
#include <stdio.h>
#define max 10
struct 
{
    int row;
    int col;
    int value;
}sp[max];

void read(int row, int col, int matrix[5][5])
{
    printf("Enter elements\n");
    for(int i=0; i<row; i++)
    for(int j=0; j<col; j++)
    {
        scanf("%d",&matrix[i][j]);
    }
}

void display(int row, int col, int matrix[5][5])
{
     for(int i=0; i<row; i++)
    {
    for(int j=0; j<col; j++)
        printf("%d\t",matrix[i][j]);
    printf("\n");
    }
    printf("\n");
}

void sparse(int row, int col, int matrix[5][5])
{   
    int k=1, t_value=0;
    for(int i=0; i<row; i++)
    for(int j=0; j<col; j++)
    {
        if(matrix[i][j]!=0)
        {
            t_value++;
            sp[k].value= matrix[i][j];
            sp[k].row= i;
            sp[k].col= j;
            k++;
        }
    }
    sp[0].value = t_value;
    sp[0].row= row;
    sp[0].col= col;
    for(int k=0; k<=t_value; k++)
    {
        printf("%d\t%d\t%d\t\n",sp[k].row, sp[k].col, sp[k].value);
    }
}

int main()
{
    int row, col, matrix[5][5];
    printf("Enter rows & cols of matrix: ");
    scanf("%d%d",&row,&col);
    read(row, col, matrix); //Read matrix
    display(row, col, matrix); //Display matrix
    printf("Sparse matrix represenation in triple form\n");
    sparse(row, col, matrix); //Sparse matrix operation
    return 0;
}