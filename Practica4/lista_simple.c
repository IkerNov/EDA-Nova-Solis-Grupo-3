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

void insertarInicio(struct Nodo **lista, int valor) {
    struct Nodo *nuevo = crearNodo(valor);
    nuevo->sig = *lista;
    *lista = nuevo;
}

void mostrarLista(struct Nodo *lista) {
    printf("Lista: ");
    while (lista != NULL) {
        printf("%d -> ", lista->dato);
        lista = lista->sig;
    }
    printf("NULL\n");
}

void liberarLista(struct Nodo *lista) {
    struct Nodo *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->sig;
        free(temp);
    }
}

int main() {
    struct Nodo *lista = NULL;
    int opcion, valor;

    do {
        printf("\n--- MENU LISTA SIMPLE ---\n");
        printf("1. Insertar al inicio\n");
        printf("2. Mostrar lista\n");
        printf("3. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa un valor: ");
                scanf("%d", &valor);
                insertarInicio(&lista, valor);
                break;
            case 2:
                mostrarLista(lista);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 3);

    liberarLista(lista);
    return 0;
}
