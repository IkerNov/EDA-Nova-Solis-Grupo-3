#include <stdio.h>

int main() {
    int n;
    int arreglo[100];
    int i;

    int suma = 0;
    int minimo, maximo;
    int posMin = 0, posMax = 0;
    float promedio;

    printf("Cuantos numeros vas a ingresar? (1 a 100): ");
    scanf("%d", &n);

    while (n <= 0 || n > 100) {
        printf("Cantidad no valida, escribe de nuevo: ");
        scanf("%d", &n);
    }

    printf("Escribe los %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
        suma = suma + arreglo[i];

        if (i == 0) {  // el primer numero sirve para iniciar minimo y maximo
            minimo = arreglo[i];
            maximo = arreglo[i];
        }
        else {
            if (arreglo[i] < minimo) {
                minimo = arreglo[i];
                posMin = i;
            }
            if (arreglo[i] > maximo) {
                maximo = arreglo[i];
                posMax = i;
            }
        }
    }

    promedio = (float) suma / n;

    printf("\nLa suma es: %d\n", suma);
    printf("El promedio es: %.2f\n", promedio);
    printf("El minimo es: %d (posicion %d)\n", minimo, posMin);
    printf("El maximo es: %d (posicion %d)\n", maximo, posMax);

    return 0;
}
