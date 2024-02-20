#include <stdio.h>
int main()
{
    int N, x, z = 1;
    scanf("%d", &N);
    for (x = N; x >= 1; x--)
        z *= x;
    printf("%d\n", z);
   
    return 0;
}