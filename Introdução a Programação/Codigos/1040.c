#include <stdio.h>
int main (){
    float N1, N2, N3, N4, M, E, MF;
    scanf("%f %f %f %f", &N1, &N2, &N3, &N4);
    M = ((N1 * 2) + (N2 * 3) + (N3 * 4)+ N4)/10;
    printf("Media: %.1f\n", M);
    if (M >= 7.0){
        printf("Aluno aprovado.\n");
    }else if (M < 5.0){
        printf("Aluno reprovado.\n");
    }else if (M == 5.0 || M < 6.9){
        printf("Aluno em exame.\n");
        scanf("%f", &E);
        printf("Nota do exame: %.1f\n", E);
        if(E >= 5.0){
            printf("Aluno aprovado.\n");
        }else if(E < 4.9){
            printf("Aluno reprovado\n");
            }   
        MF = (E + M)/2;            
        printf("Media final: %.1f\n", MF);
        
    }
    return 0;
}