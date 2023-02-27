#include <stdio.h>

struct mat
{
    int val, row, col;
}sp[10];

void main()
{
    int mat[5][5];
    int m, n;

    // Reading matrix
    printf("Enter rows & cols of matrix: ");
    scanf("%d%d",&m,&n);

    printf("Enter matrix: \n");  
    
    for(int i =0 ; i< m; i++)
    {
        for(int j=0;j<n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    // Printing entered matrix
    printf("\nEntered matrix:\n");  
    
    for(int i =0 ; i< m; i++)
    {
        for(int j=0;j<n; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    // Sparse implementation 
    int k =1, total=0;
    for(int i =0; i<m; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(mat[i][j]!=0)
            {
                total++;
                sp[k].row = i;
                sp[k].col = j;
                sp[k].val = mat[i][j];
                k++;
            }
        }
    }
    sp[0].row = m;
    sp[0].col = n;
    sp[0].val = total;
    printf("\nSparse matrix representation\n"); 
    for(int i =0; i<=total; i++)
    {
        printf("%d\t%d\t%d\n",sp[i].row,sp[i].col, sp[i].val);
    }
}