/* Salário	Percentual de Reajuste
0 - 400.00              15%
400.01 - 800.00         12% 
800.01 - 1200.00        10%
1200.01 - 2000.00        7%
Acima de 2000.00         4% */

int main(){
    double s, r, p;
    s = r = p = 0;
    scanf("%lf", &s);
    if(s <= 400.00){
        r = s * 0.15;
        p = 15;
    }else if(s <= 800.00){
        r = s * 0.12;
        p = 12;
    }else if(s <= 1200.00){
        r = s * 0.10;
        p = 10;
    }else if(s <= 2000.00){
        r = s * 0.07;
        p = 7;
    }else{
        r = s * 0.04;
        p = 4;
    }
    printf("Novo salario: %.2lf\n", s + r);
    printf("Reajuste ganho: %.2lf\n", r);
    printf("Em percentual: %.0lf %%\n", p);
    return 0;
}