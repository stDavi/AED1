#include <stdio.h>

int main() {
    int n;
    int sudoku[9][9];
    int contador[10];
    int i, j, k, instancia;
    int num, inicioLinha, inicioCol;
    int valido;

    scanf("%d", &n);

    for (instancia = 1; instancia <= n; instancia++) {
        // Lê a matriz 9x9
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        valido = 1; // assume válido

        // Verifica linhas
        for (i = 0; i < 9 && valido; i++) {
            for (k = 1; k <= 9; k++) contador[k] = 0;
            for (j = 0; j < 9; j++) {
                num = sudoku[i][j];
                if (num < 1 || num > 9 || contador[num]) {
                    valido = 0;
                    break;
                }
                contador[num] = 1;
            }
        }

        // Verifica colunas
        for (j = 0; j < 9 && valido; j++) {
            for (k = 1; k <= 9; k++) contador[k] = 0;
            for (i = 0; i < 9; i++) {
                num = sudoku[i][j];
                if (num < 1 || num > 9 || contador[num]) {
                    valido = 0;
                    break;
                }
                contador[num] = 1;
            }
        }

        // Verifica regiões 3x3
        for (inicioLinha = 0; inicioLinha < 9 && valido; inicioLinha += 3) {
            for (inicioCol = 0; inicioCol < 9 && valido; inicioCol += 3) {
                for (k = 1; k <= 9; k++) contador[k] = 0;
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        num = sudoku[inicioLinha + i][inicioCol + j];
                        if (num < 1 || num > 9 || contador[num]) {
                            valido = 0;
                            break;
                        }
                        contador[num] = 1;
                    }
                    if (!valido) break;
                }
            }
        }

        // Saída exatamente como o enunciado pede
        printf("Instancia %d\n", instancia);
        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
