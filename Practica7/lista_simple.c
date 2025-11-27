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

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = crearNodo(valor);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *temp = *cabeza;
    struct Nodo *anterior = NULL;

    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL)
        return;

    if (anterior == NULL) {
        *cabeza = temp->siguiente;
    } else {
        anterior->siguiente = temp->siguiente;
    }

    free(temp);
}

void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    struct Nodo *cabeza = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("¿Qué valor deseas eliminar? ");
    scanf("%d", &eliminarValor);
    eliminar(&cabeza, eliminarValor);

    printf("Lista después de eliminar:\n");
    recorrer(cabeza);

    liberar(cabeza);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
