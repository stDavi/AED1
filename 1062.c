#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        while (1) {
            int desired[1000];
            scanf("%d", &desired[0]);

            if (desired[0] == 0) { 
                printf("\n");
                break;
            }

            for (int i = 1; i < N; i++)
                scanf("%d", &desired[i]);

            int stack[1000];
            int top = -1;
            int next = 1;         // próximo vagão que chega de A
            int possible = 1;     // assume que é possível até provar o contrário

            for (int i = 0; i < N; i++) {
                int want = desired[i];

                while (next <= N && (top == -1 || stack[top] != want)) {
                    stack[++top] = next++;
                }

                if (stack[top] == want) {
                    top--; // remove da pilha
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
