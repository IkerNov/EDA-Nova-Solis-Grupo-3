#include <stdio.h>

#define MAX 5

struct Pila {
    int datos[MAX];
    int tope;
};

void inicializarPila(struct Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacia.\n");
}

int pilaLlena(struct Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(struct Pila *p) {
    return p->tope == -1;
}

void push(struct Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: la pila esta llena.\n");
    } else {
        p->tope++;
        p->datos[p->tope] = valor;
        printf("Se inserto %d en la pila.\n", valor);
    }
}

int pop(struct Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: la pila esta vacia.\n");
        return -1;
    } else {
        int valor = p->datos[p->tope];
        p->tope--;
        return valor;
    }
}

void mostrarPila(struct Pila *p) {
    printf("Estado de la pila: ");
    if (pilaVacia(p)) {
        printf("vacia\n");
        return;
    }

    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}

int main() {
    struct Pila pila;
    int n, valor;

    inicializarPila(&pila);

    printf("Cuantos elementos quieres apilar? (max 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(&pila);
    }

    printf("\nCuantos elementos quieres desapilar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int eliminado = pop(&pila);
        if (eliminado != -1) {
            printf("Salio: %d\n", eliminado);
        }
        mostrarPila(&pila);
    }

    return 0;
}
