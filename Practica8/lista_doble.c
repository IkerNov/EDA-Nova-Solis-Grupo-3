#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (!nuevo) return NULL;
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = crearNodo(valor);
    if (*inicio != NULL) {
        nuevo->siguiente = *inicio;
        (*inicio)->anterior = nuevo;
    }
    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = crearNodo(valor);
    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }
    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *temp = inicio;
    printf("Adelante: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->dato);
        if (temp->siguiente == NULL) break;
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    printf("Atras: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->dato);
        temp = temp->anterior;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;

    while (temp != NULL && temp->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    if (temp->anterior != NULL)
        temp->anterior->siguiente = temp->siguiente;
    else
        *inicio = temp->siguiente;

    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;

    free(temp);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuantos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("¿Cuantos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("Valor a eliminar: ");
    scanf("%d", &eliminarValor);
    eliminar(&inicio, eliminarValor);

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
