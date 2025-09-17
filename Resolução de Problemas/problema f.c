#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
    scanf("%d", &x);
      if (x > 0 && x %100 == 0) {
        printf("YES");
      }else{
          printf("NO");
      }
        
  return (0);
}