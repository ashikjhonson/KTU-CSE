#include <stdio.h>

struct poly
{
    int coeff;
    int exp;
} p1[10], p2[10], p3[10];

int t1, t2, t3;
int a = 0, b = 0, c = 0;

void readpoly1(int t)
{
    printf("Enter coefficient and exponent in the equation in descending order of it's exponents below\n");
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }
}

void readpoly2(int t)
{
    printf("Enter coefficient and exponent in the equation in descending order of it's exponents below\n");
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);
    }
}

int addpoly()
{
    while (a < t1 && b < t2)
    {
        if (p1[a].exp == p2[b].exp)
        {
            p3[c].exp = p1[a].exp;
            p3[c].coeff = p1[a].coeff + p2[b].coeff;
            a++;
            b++;
        }
        else if (p1[a].exp > p2[b].exp)
        {
            p3[c].exp = p1[a].exp;
            p3[c].coeff = p1[a].coeff;
            a++;
        }
        else
        {
            p3[c].exp = p2[b].exp;
            p3[c].coeff = p2[b].coeff;
            b++;
        }
        c++;
    }
    while (a < t1)
    {
        p3[c].exp = p1[a].exp;
        p3[c].coeff = p1[a].coeff;
        a++;
        c++;
    }
    while (b < t2)
    {
        p3[c].exp = p2[b].exp;
        p3[c].coeff = p1[b].coeff;
        b++;
        c++;
    }
    return c;
}

void display(struct poly p[10], int t)
{
    if (t > 0)
    {
        for (int i = 0; i < t - 1; i++)
            printf("%dY^(%d) + ", p[i].coeff, p[i].exp);
        printf("%dY^(%d) ", p[t - 1].coeff, p[t - 1].exp);
    }
    printf("\n");
}

void main()
{
    printf("Enter no. of terms in poly 1\n");
    scanf("%d", &t1);
    readpoly1(t1);

    printf("Enter no. of terms in poly 2\n");
    scanf("%d", &t2);
    readpoly2(t2);

    t3 = addpoly();

    printf("\n-------------poly 1-------------\n");
    display(p1, a);
    printf("\n-------------poly 2-------------\n");
    display(p2, b);
    printf("\n-------------Sum----------------\n");
    display(p3, t3);
}