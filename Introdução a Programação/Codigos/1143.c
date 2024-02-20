#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i,y,z;
    scanf("%d", &x);
    for(i=1; i<=x; i++){
        y = i * i;
        z = i * i * i;
        printf("%d %d %d\n", i, y, z);
    }
    return 0;
}