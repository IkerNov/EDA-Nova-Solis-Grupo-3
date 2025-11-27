#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    if (!nuevo) return NULL;
    nuevo->dato = valor;
    nuevo->anterior = nuevo;
    nuevo->siguiente = nuevo;
    return nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = crearNodo(valor);

    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    if (!inicio) return;

    struct Nodo *temp = inicio;
    printf("Circular: ");
    do {
        printf("%d <-> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);
    printf("(vuelve al inicio)\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;

    do {
        if (actual->dato == valor) {
            if (actual->siguiente == actual) {
                free(actual);
                *inicio = NULL;
                return;
            }

            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;

            if (actual == *inicio)
                *inicio = actual->siguiente;

            free(actual);
            return;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);
}

void liberarCircular(struct Nodo *inicio) {
    if (!inicio) return;

    struct Nodo *actual = inicio;
    struct Nodo *sig;

    do {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    } while (actual != inicio);
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuantos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerCircular(inicio);
    }

    printf("Valor a eliminar: ");
    scanf("%d", &eliminarValor);
    eliminarCircular(&inicio, eliminarValor);

    recorrerCircular(inicio);

    liberarCircular(inicio);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
