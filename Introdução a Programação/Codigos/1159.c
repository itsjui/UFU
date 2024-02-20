#include <stdio.h>
int main()
{
    int x, i, b = 0;
    while (1)
    {
        scanf("%d", &x);
        b = 0;
        if (x == 0)
            break;
        else if (x % 2 == 0)
        {
            for (i = x; i <= x + 8; i += 2)
                b += i;
        }
        else
        {
            for (i = x + 1; i <= x + 9; i += 2)
                b += i;
        }
        printf("%d\n", b);
    }
    return 0;
}