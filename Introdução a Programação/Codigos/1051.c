int main(){
    float s = 0.0, i;
    scanf("%f", &s);
    
    if(s >= 0 && s <= 2000.00){
        printf("Isento\n");
    }
    
    if(s >= 2000.01 && s <= 3000.00){
        s = s - 2000;
        printf("R$ %.2f\n", s*0.08);
    }
    
    if(s >= 3000.01 && s <= 4500.00){
        i = 1000 * 0.08;
        i += (s - 3000.00) * 0.18;
        printf("R$ %.2f\n", i);
    }
    
    if(s > 4500.00){
        i = 1000 * 0.08;
        i += 1500 * 0.18;
        i += (s - 4500.00) * 0.28;
        printf("R$ %.2f\n", i);
    }
    return 0;
}