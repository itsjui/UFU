#include <stdio.h>
int main (void) {
int i,a;
while(scanf("%d", &a), a) {
for (i = 1; i <= a; i++) {
printf("%d%c", i, i == a ? '\n' : ' ');
}
}
return 0;
}