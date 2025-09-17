#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int f[n + 1]; // índice começa em 1, então usamos n+1

    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }

    for (int i = 1; i <= n; i++) {
        int a = f[i];     // avião A gosta do avião a
        int b = f[a];     // avião a gosta do avião b
        int c = f[b];     // avião b gosta do avião c

        if (c == i) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
