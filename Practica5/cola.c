#include <stdio.h>

#define MAX 5

struct Cola {
    int datos[MAX];
    int frente;
    int final;
};

void inicializarCola(struct Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacia.\n");
}

int colaLlena(struct Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(struct Cola *c) {
    return c->frente > c->final;
}

void enqueue(struct Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: la cola esta llena.\n");
    } else {
        c->final++;
        c->datos[c->final] = valor;
        printf("Se inserto %d en la cola.\n", valor);
    }
}

int dequeue(struct Cola *c) {
    if (colaVacia(c)) {
        printf("Error: la cola esta vacia.\n");
        return -1;
    } else {
        int valor = c->datos[c->frente];
        c->frente++;
        return valor;
    }
}

void mostrarCola(struct Cola *c) {
    printf("Estado de la cola: ");
    if (colaVacia(c)) {
        printf("vacia\n");
        return;
    }

    for (int i = c->frente; i <= c->final; i++) {
        printf("%d ", c->datos[i]);
    }
    printf("\n");
}

int main() {
    struct Cola cola;
    int n, valor;

    inicializarCola(&cola);

    printf("Cuantos elementos quieres encolar? (max 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(&cola);
    }

    printf("\nCuantos elementos quieres desencolar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int eliminado = dequeue(&cola);
        if (eliminado != -1) {
            printf("Salio: %d\n", eliminado);
        }
        mostrarCola(&cola);
    }

    return 0;
}
