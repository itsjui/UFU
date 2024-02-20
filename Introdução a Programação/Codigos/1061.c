#include <stdio.h>
#include<stdlib.h>

int main() {
 
    int di, hi, mi, si;
    int df, hf, mf, sf;
    
    scanf("Dia %d", &di);
    scanf(" %d : %d : %d", &hi, &mi, &si);
    scanf(" Dia %d", &df);
    scanf(" %d : %d : %d", &hf, &mf, &sf);
    
    if (sf < si) {
        mf--;
        sf += 60;
    }
    
    if (mf < mi) {
        hf--;
        mf += 60;
    }
    
    if (hf < hi) {
        df--;
        hf += 24;
    }
    
    printf("%d dia(s)\n", (df-di));
    printf("%d hora(s)\n", (hf-hi));
    printf("%d minuto(s)\n", (mf-mi));
    printf("%d segundo(s)\n", (sf-si));
    
    return 0;
}
