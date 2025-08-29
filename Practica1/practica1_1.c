#include <stdio.h>

int main() {
    int n;          // numero de elementos
    int arreglo[100];  // aqui voy a guardar los numeros
    int i;

    printf("Cuantos numeros quieres guardar? (1 a 100): ");
    scanf("%d", &n);

    // validar que el numero este en el rango permitido
    while (n <= 0 || n > 100) {
        printf("Error, debe ser entre 1 y 100, vuelve a escribir: ");
        scanf("%d", &n);
    }

    // pedir los numeros
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &arreglo[i]);
    }

    // mostrar lo que se guardo
    printf("\nGuardaste estos numeros:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
