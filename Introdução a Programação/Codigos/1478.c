void gerarMatriz(unsigned int n){
    unsigned int i,j,meio;
    int**mat;

    meio=(n/2);

    mat=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        mat[i]=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        for(j=i;j<n-i;j++)
            mat[j][i]=i+1;

    for(i=0;i<meio;i++)
        mat[n-i-1][n-i-1]=mat[i][i];

    for(i=(n-1);i>meio;i--)
        for(j=n-i;j<n;j++)
            mat[i][j]=n-i;

    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            mat[j][i]=mat[i][j];

    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++)
            printf("%3d ",mat[i][j]);
        printf("%3d\n", mat[i][j]);
    }
    printf("\n");

    for(i=0;i<n;i++)
        free(mat[i]);
    free(mat);
}

int main()
{
    unsigned int n;
    scanf("%u",&n);
    while(n){
        gerarMatriz(n);
        scanf("%u",&n);
    }
    return 0;
}