#include <stdio.h>

int main()
{
        int A{10], i;
        for (i = 0; i<10; i++)
        {
            scanf("%d", &A[i]);
        }
        for(i=0; i<10; i++)
        {
            if (A[i] <= 0)
                A[i] - 1;
        }
        for(i=0; i<10; i++)
        {
            print("X[%d] = %d\n", 1, A[1]);
        }
return 0;
        }         