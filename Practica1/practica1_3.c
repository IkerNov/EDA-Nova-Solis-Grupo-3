#include <stdio.h>

int main() {
    int n;
    int arreglo[100];
    int i;
    int temp;

    printf("Cuantos numeros vas a ingresar? (1 a 100): ");
    scanf("%d", &n);

    while (n <= 0 || n > 100) {
        printf("Cantidad no valida, escribe de nuevo: ");
        scanf("%d", &n);
    }

    printf("Escribe los %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    // invertir el arreglo (intercambiar posiciones)
    for (i = 0; i < n / 2; i++) {
        temp = arreglo[i];
        arreglo[i] = arreglo[n - 1 - i];
        arreglo[n - 1 - i] = temp;
    }

    printf("\nEl arreglo invertido es:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
