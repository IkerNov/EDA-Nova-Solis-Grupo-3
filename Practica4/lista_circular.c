#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }
    nuevo->dato = valor;
    nuevo->sig = NULL;
    return nuevo;
}

// Insertar nodo al final de una lista circular
void insertarCircular(struct Nodo **lista, int valor) {
    struct Nodo *nuevo = crearNodo(valor);

    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo; // apunta a sí mismo
    } else {
        struct Nodo *temp = *lista;

        while (temp->sig != *lista) {
            temp = temp->sig;
        }

        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

// Mostrar la lista circular
void mostrarCircular(struct Nodo *lista) {
    if (lista == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    struct Nodo *temp = lista;

    printf("Lista circular: ");
    do {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    } while (temp != lista);

    printf("(vuelve al inicio)\n");
}

// Liberar lista circular
void liberarCircular(struct Nodo *lista) {
    if (lista == NULL) return;

    struct Nodo *actual = lista;
    struct Nodo *siguiente;

    do {
        siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    } while (actual != lista);
}

int main() {
    struct Nodo *lista = NULL;
    int opcion, valor;

    do {
        printf("\n--- MENU LISTA CIRCULAR ---\n");
        printf("1. Insertar al final\n");
        printf("2. Mostrar lista\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa un valor: ");
                scanf("%d", &valor);
                insertarCircular(&lista, valor);
                break;

            case 2:
                mostrarCircular(lista);
                break;

            case 3:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 3);

    liberarCircular(lista);
    return 0;
}
