#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, d;
    scanf("%d" "%d", &n, &d);
    int numero[n];
    int vetor2[n]; 

    for(int i = 0; i < n; i ++){
        scanf("%d", &numero[i]);
    }
    d = d % n;

    for(int i = d; i < n, i+=1){
        vetor2[i] = numero[(i + d) % n];
        printf("%d", vetor2[i]);
    }
    printf("\n");
    
    return 0;
}