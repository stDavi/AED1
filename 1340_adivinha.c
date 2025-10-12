#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// ----------- PILHA -----------
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = 0; }
void push(Stack *s, int x) { s->data[s->top++] = x; }
int popStack(Stack *s) { return s->data[--s->top]; }
int isEmptyStack(Stack *s) { return s->top == 0; }

// ----------- FILA -----------
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) { q->front = q->rear = 0; }
void enqueue(Queue *q, int x) { q->data[q->rear++] = x; }
int dequeue(Queue *q) { return q->data[q->front++]; }
int isEmptyQueue(Queue *q) { return q->front == q->rear; }

// ----------- FILA DE PRIORIDADE (MAX HEAP SIMPLES) -----------
typedef struct {
    int data[MAX];
    int size;
} PQueue;

void initPQueue(PQueue *pq) { pq->size = 0; }
void pushPQ(PQueue *pq, int x) {
    int i = pq->size++;
    pq->data[i] = x;
    while (i > 0 && pq->data[i] > pq->data[(i - 1) / 2]) {
        int tmp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}
int popPQ(PQueue *pq) {
    int ret = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < pq->size && pq->data[l] > pq->data[largest]) largest = l;
        if (r < pq->size && pq->data[r] > pq->data[largest]) largest = r;
        if (largest == i) break;
        int tmp = pq->data[i];
        pq->data[i] = pq->data[largest];
        pq->data[largest] = tmp;
        i = largest;
    }
    return ret;
}
int isEmptyPQ(PQueue *pq) { return pq->size == 0; }

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Stack s; Queue q; PQueue pq;
        initStack(&s); initQueue(&q); initPQueue(&pq);

        int possibleStack = 1, possibleQueue = 1, possiblePQ = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                if (possibleStack) push(&s, x);
                if (possibleQueue) enqueue(&q, x);
                if (possiblePQ) pushPQ(&pq, x);
            } else {
                if (possibleStack) {
                    if (isEmptyStack(&s) || popStack(&s) != x) possibleStack = 0;
                }
                if (possibleQueue) {
                    if (isEmptyQueue(&q) || dequeue(&q) != x) possibleQueue = 0;
                }
                if (possiblePQ) {
                    if (isEmptyPQ(&pq) || popPQ(&pq) != x) possiblePQ = 0;
                }
            }
        }

        int count = possibleStack + possibleQueue + possiblePQ;
        if (count == 0) printf("impossible\n");
        else if (count > 1) printf("not sure\n");
        else if (possibleStack) printf("stack\n");
        else if (possibleQueue) printf("queue\n");
        else printf("priority queue\n");
    }
    return 0;
}
