
#include <stdio.h>

int main(){
  float m[12][12], s = 0;
  int i, j, c;
  char t[5];

  scanf("%d", &c);
  scanf("%c", &t[0]);
  for(i=0;i<12;i++){
    for(j=0;j<12;j++){
      scanf("%f", &m[i][j]);
    }
  }
  for(i=0;i<12;i++){
    for(j=0;j<12;j++){
     if(j == c) s = m[i][j] + s;
       
    }
  }

  if(t[0] == 'S') printf("%.1f\n", s); 
  if(t[0] == 'M') printf("%.1f\n", s/12); 

  return 0;
}