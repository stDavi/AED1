#include <stdio.h>
#include <string.h>

#define MAX_EXPR 1000
#define MAX_PILHA 1000

// ------------------- PILHA -------------------
typedef struct {
    char dados[MAX_PILHA];
    int topo;
} Pilha;

// inicia a pilha (topo começa em 0, ou seja, sem elementos)
void iniciarPilha(Pilha *p) {
    p->topo = 0;
}

// retorna 1 se a pilha está vazia, senão 0
int pilhaVazia(Pilha *p) {
    return (p->topo == 0);
}

// coloca um novo elemento no topo
void empilhar(Pilha *p, char c) {
    p->dados[p->topo] = c;
    p->topo++;
}

// retira e retorna o elemento do topo
char desempilhar(Pilha *p) {
    p->topo--;
    return p->dados[p->topo];
}


// ------------------- VERIFICA EXPRESSÃO -------------------
int verificarExpressao(char expr[]) {
    Pilha p;
    iniciarPilha(&p);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            empilhar(&p, '(');
        } else if (expr[i] == ')') {
            if (pilhaVazia(&p)) {
                return 0; // ')' sem um '(' antes
            }
            desempilhar(&p);
        }
    }
    return pilhaVazia(&p); // se sobrou '(' é incorreto
}

// ------------------- PROGRAMA PRINCIPAL -------------------
int main() {
    char expr[MAX_EXPR];

    // lê linha por linha até o fim da entrada
    while (scanf(" %[^\n]", expr) == 1) {
        if (verificarExpressao(expr)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
