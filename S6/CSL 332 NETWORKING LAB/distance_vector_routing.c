#include <stdio.h>
void main()
{
    int i, j, k, n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    int routing[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the distance between %d %d \n", i, j);
            scanf("%d", &routing[i][j]);
        }
    }
    printf("Initial routing table\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", routing[i][j]);
        }
        printf("\n");
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (routing[i][j] > routing[i][k] + routing[k][j])
                {
                    routing[i][j] = routing[i][k] + routing[k][j];
                }
            }
        }
    }
    printf("Updated routing table\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            printf("%d\t", routing[i][j]);
        }
        printf("\n");
    }
}