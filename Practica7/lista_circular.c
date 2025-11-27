#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = crearNodo(valor);

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *ultimo = nuevo;
    }
}

void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    struct Nodo *temp = cabeza;
    printf("Lista circular: ");

    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);

    printf("(regresa al inicio)\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL)
        return;

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor) {
            if (actual == *cabeza) {
                *cabeza = actual->siguiente;
                (*ultimo)->siguiente = *cabeza;
            } else if (actual == *ultimo) {
                *ultimo = anterior;
                (*ultimo)->siguiente = *cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);
}

void liberarCircular(struct Nodo *cabeza) {
    if (cabeza == NULL)
        return;

    struct Nodo *actual = cabeza;
    struct Nodo *sig;

    do {
        sig = actual->siguiente;
        free(actual);
        actual = sig;
    } while (actual != cabeza);
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("¿Qué valor deseas eliminar? ");
    scanf("%d", &eliminarValor);

    eliminarCircular(&cabeza, &ultimo, eliminarValor);
    printf("Lista después de eliminar:\n");
    recorrerCircular(cabeza);

    liberarCircular(cabeza);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
