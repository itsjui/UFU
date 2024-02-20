#include <stdio.h>

int main()
{
    int a, b, c1, c2;

    a = 0;
    b = 0;
    c1 = 1;
    c2 = 0;

    scanf("%d %d", &a, &b);
    if ((1 < a < 20) && (b < 100000))
    {
        for (c1 = 1; c1 <= b; c1++)
        {
            c2++;
            if (c2 == a)
            {
                printf("%d\n", c1);
                c2 = 0;
            }
            else
            {
                printf("%d ", c1);
            }
        }
    }
    return 0;
}
