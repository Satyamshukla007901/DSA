#include <stdio.h>

int main()
{
    int t, i, x, y, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &x, &y);
        if (x % 2 == 0 && y % 2 == 0)
        {
            printf("0\n");
        }
        else if (x % 2 == 1 && y % 2 == 0)
        {
            printf("1\n");
        }
        else if (x % 2 == 0 && y % 2 == 1)
        {
            printf("1\n");
        }
        else if (x % 2 == 1 && y % 2 == 1)
        {
            if (x % y == 0 || y % x == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }
        }
    }
    return 0;
}