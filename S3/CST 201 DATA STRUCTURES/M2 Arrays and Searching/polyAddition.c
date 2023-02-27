#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
} p1[10], p2[10], p3[10];

void displayPoly(struct poly p[], int t)
{
    for (int i = 0; i < t; i++)
    {
        if (p[i].expo == 0)
        {
            printf("%d ", p[i].coeff);
            continue;
        }
        if (i + 1 == t)
            printf("%dX^%d ", p[i].coeff, p[i].expo);
        else
            printf("%dX^%d + ", p[i].coeff, p[i].expo);
    }
}

int readPoly(struct poly p[])
{
    int t, i;
    printf("\n\n Enter the total number of terms in the polynomial:");
    scanf("%d", &t);
    printf("\n Enter the COEFFICIENT and EXPONENT (in DESCENDING ORDER)\n");
    for (i = 0; i < t; i++)
    {
        scanf("%d", &p[i].coeff);
        scanf("%d", &p[i].expo);
    }
    return (t);
}

int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[])
{
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2)
    {
        if (p1[i].expo == p2[j].expo)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expo > p2[j].expo)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }
    while (i < t1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
    while (j < t2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    return (k);
}

int main()
{
    int t1, t2, t3;

    t1 = readPoly(p1);
    displayPoly(p1, t1);

    t2 = readPoly(p2);
    displayPoly(p2, t2);

    t3 = addPoly(p1, p2, t1, t2, p3);
    printf(" \n\n Resultant polynomial after addition : ");
    displayPoly(p3, t3);

    return 0;
}
