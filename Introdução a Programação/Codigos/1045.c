#include <stdio.h>
int main()
{
    float A, B, C;
    scanf("%f %f %f", &A, &B, &C);
    if (A >= B + C)
    {
        printf("NAO FORMA TRIANGULO\n");
    }
    if ((A * A) == (B * B) + (C * C))
    {
        printf("TRIANGULO RETANGULO\n");
    }
    if ((A * A) > (B * B) + (C * C))
    {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    if ((A * A) < (B * B) + (C * C))
    {
        printf("TRIANGULO ACUTANGULO\n");
    }
    if (A == B && A == C && B == C)
    {
        printf("TRIANGULO EQUILATERO\n");
    }
    if (A == B || A == C || B == C)
    {
        printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}