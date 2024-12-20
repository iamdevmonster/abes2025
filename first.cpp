#include <stdio.h>
int main()
{
    int n = 5;

    for (int i = 0; i < 2 * n - 1; i++)
    {

        int c;
        if (i < n)
        {
            c = 2 * (n - i) - 1;
        }
        else
        {
            c = 2 * (i - n + 1) + 1;
        }

        for (int j = 0; j < c; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < 2 * n - c; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}