#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR 1000

// ------------------- NÓ DA PILHA -------------------
typedef struct Node {
    char valor;
    struct Node *prox;
} Node;

// ------------------- PILHA -------------------
typedef struct {
    Node *topo;
} Pilha;

// inicia a pilha (vazia)
void iniciarPilha(Pilha *p) {
    p->topo = NULL;
}

// retorna 1 se a pilha está vazia, senão 0
int pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

// empilha um elemento (insere no topo)
void empilhar(Pilha *p, char c) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (!novo) {
        printf("Erro de memória\n");
        exit(1);
    }
    novo->valor = c;
    novo->prox = p->topo;
    p->topo = novo;
}

// desempilha um elemento e retorna o valor
char desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        return '\0'; // caso não haja elementos
    }
    Node *remover = p->topo;
    char val = remover->valor;
    p->topo = remover->prox;
    free(remover);
    return val;
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
                return 0; // ')' sem '(' correspondente
            }
            desempilhar(&p);
        }
    }
    return pilhaVazia(&p); // se sobrou '(' → incorreto
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
