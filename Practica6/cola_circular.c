#include <stdio.h>

#define MAX 5

struct ColaCircular {
    int datos[MAX];
    int frente;
    int final;
    int size;
};

void inicializar(struct ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada.\n");
}

int isEmpty(struct ColaCircular *c) {
    return c->size == 0;
}

int isFull(struct ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(struct ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Error: la cola circular esta llena.\n");
    } else {
        c->datos[c->final] = valor;
        c->final = (c->final + 1) % MAX;
        c->size++;
        printf("Encolado: %d\n", valor);
    }
}

int dequeue(struct ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Error: la cola circular esta vacia.\n");
        return -1;
    } else {
        int valor = c->datos[c->frente];
        c->frente = (c->frente + 1) % MAX;
        c->size--;
        return valor;
    }
}

int peek(struct ColaCircular *c) {
    if (isEmpty(c)) {
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(struct ColaCircular *c) {
    printf("Cola circular: ");
    if (isEmpty(c)) {
        printf("vacia\n");
        return;
    }

    int i = c->frente;
    for (int cont = 0; cont < c->size; cont++) {
        printf("%d ", c->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    struct ColaCircular cola;
    inicializar(&cola);

    // Pruebas
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);

    printf("Desencolado: %d\n", dequeue(&cola));
    printQueue(&cola);

    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);

    return 0;
}
