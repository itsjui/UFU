#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>

int main(){
  int stu[1001], high[1001];
  int n, m, i, c;

  scanf("%d", &n);

  while(n--){
    scanf("%d", &n);

    for (i = 0; i < m; ++i)
  {
   scanf("%d", &stu[i]);
   high[i] = stu[i];
  }
  
  sort(high, high + m);
  reverse(high, high + m);
  i = 0; c = 0;

  while(i < m)
  {
   if(stu[i] == high[i])
    c++;
   i++;
  }

  printf("%d\n", c);
 }

 return 0;

}