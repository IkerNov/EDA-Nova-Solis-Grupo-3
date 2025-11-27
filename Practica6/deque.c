#include <stdio.h>

#define MAX 5

struct Deque {
    int datos[MAX];
    int front;
    int size;
};

void inicializarDeque(struct Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado.\n");
}

int isEmpty(struct Deque *d) {
    return d->size == 0;
}

int isFull(struct Deque *d) {
    return d->size == MAX;
}

int rearIndex(struct Deque *d) {
    return (d->front + d->size - 1) % MAX;
}

void insert_front(struct Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: deque lleno.\n");
    } else {
        d->front = (d->front - 1 + MAX) % MAX;
        d->datos[d->front] = valor;
        d->size++;
        printf("Insertado al frente: %d\n", valor);
    }
}

void insert_rear(struct Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: deque lleno.\n");
    } else {
        int rear = (d->front + d->size) % MAX;
        d->datos[rear] = valor;
        d->size++;
        printf("Insertado al final: %d\n", valor);
    }
}

int delete_front(struct Deque *d) {
    if (isEmpty(d)) {
        printf("Error: deque vacio.\n");
        return -1;
    }
    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return valor;
}

int delete_rear(struct Deque *d) {
    if (isEmpty(d)) {
        printf("Error: deque vacio.\n");
        return -1;
    }
    int rear = rearIndex(d);
    int valor = d->datos[rear];
    d->size--;
    return valor;
}

int peek_front(struct Deque *d) {
    if (isEmpty(d)) return -1;
    return d->datos[d->front];
}

int peek_rear(struct Deque *d) {
    if (isEmpty(d)) return -1;
    return d->datos[rearIndex(d)];
}

void printDeque(struct Deque *d) {
    printf("Deque: ");
    if (isEmpty(d)) {
        printf("vacio\n");
        return;
    }

    int i = d->front;
    for (int c = 0; c < d->size; c++) {
        printf("%d ", d->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    struct Deque d;
    inicializarDeque(&d);

    // Pruebas
    insert_front(&d, 10);
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    insert_front(&d, 30);
    insert_rear(&d, 40);

    printDeque(&d);

    printf("delete_front: %d\n", delete_front(&d));
    printf("delete_rear: %d\n", delete_rear(&d));
    printDeque(&d);

    insert_front(&d, 50);
    insert_rear(&d, 60);
    printDeque(&d);

    return 0;
}
