#include <stdio.h>
int main()
{
    int n[10], i, x;
    scanf("%d", &x);
    for(i=0; i<=9; i++)
    {
        n[i]=x;
        printf("N[%d] = %d\n",i,x);
        x*=2;
    }
    return 0;
}
