#include <stdio.h>

int main(void) {
    // Se creo un arreglo llamado 'a' con 5 números: 2, 4, 6, 8 y 10
    int a[5] = {2, 4, 6, 8, 10};
    
    // Se hixo un puntero 'p' que apunta al primer número del arreglo
    int *p = a; 

    // Imprime el segundo número del arreglo (que es 4)
    printf("1) a[1] = %d\n", a[1]);

    // Imprime el cuarto número del arreglo usando punteros (8)
    printf("2) *(a+3) = %d\n", *(a+3));

    // Imprime el número al que apunta 'p' (que es 2) y luego mueve 'p' al siguiente número
    printf("3) *p++ = %d\n", *p++);

    // Mueve 'p' al siguiente número antes de imprimirlo y luego lo muestra (6)
    printf("4) *++p = %d\n", *++p);

    // Imprime el número que está una posición después de donde apunta 'p' (8)
    printf("5) p[1] = %d\n", p[1]);

    // Avanza el puntero 'p' dos números más y muestra el valor que apunta ahora (10)
    printf("6) *(p+=2) = %d\n", *(p+=2));

    // Calcula cuántos números avanzó 'p' desde el inicio del arreglo (4 posiciones)
    printf("7) p - a = %ld\n", p - a);

    return 0;
}
