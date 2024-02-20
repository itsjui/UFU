#include <stdio.h>

int main(){
    int x=0, y=0, z=0, i;

    for(i=0;i<360;i=i+3){
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &z);

        if(i % 3 == 0){
            if(x>y && x>z) printf("%d\n", x);
            if(y>x && y>z) printf("%d\n", y);
            if(z>y && z>x) printf("%d\n", z);
        }
    }

    return 0;
}