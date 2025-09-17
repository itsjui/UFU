#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, x, a, b;
    scanf("%d", &x);
      if (x > 0 && x <= 15) {
        for (i = 0; i < x; i++) {
          scanf("%d", &a);
          scanf("%d", &b);
          if (a == b) {
            printf("=");
          } else if (a > b) {
            printf(">");
          } else {
            printf("<");
          }
        }
      }
        
  return (0);
}