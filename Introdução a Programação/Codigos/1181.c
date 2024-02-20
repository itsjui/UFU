#include <stdio.h>
 
int main()
{
    float M[2][2];
    int i, j;
 
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            scanf("%f", &M[i][j]);
        }
    }
 
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%.1f ", M[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}