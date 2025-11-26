#include <stdio.h>

int main() {
    int NC, N, h;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);

        int count[231] = {0};  // alturas de 0 a 230 (vamos usar só 20 a 230)

        for (int i = 0; i < N; i++) {
            scanf("%d", &h);
            count[h]++;
        }

        int first = 1;
        for (int i = 20; i <= 230; i++) {
            while (count[i]--) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
