#include<stdio.h>
 
int main()
{
    char S1[30], S2[30], S3[30];
 
    scanf("%s %s %s", S1, S2, S3);
 
    if(!strcmp(S1, "vertebrado") && !strcmp(S2, "ave") && !strcmp(S3, "carnívoro"))
    {
        printf("aguia\n");
    }
 
    if(!strcmp(S1, "vertebrado") && !strcmp(S2, "ave") && !strcmp(S3, "onívoro"))
    {
        printf("pomba\n");
    }
 
    return 0;
}