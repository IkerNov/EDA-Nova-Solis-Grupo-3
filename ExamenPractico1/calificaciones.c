// Archivo: ExamenPractico1/calificaciones.c
#include <stdio.h>
#include <stdlib.h>  // Para usar malloc(), realloc() y free()

int main() {
    int n, i, agregar;
    float *calificaciones; // Puntero para guardar las calificaciones
    float suma = 0;

    // 1. Pedir al usuario cuántos estudiantes desea registrar
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // 2. Reservar memoria dinámicamente con malloc()
    calificaciones = (float*) malloc(n * sizeof(float));

    // Verificar si malloc falló
    if (calificaciones == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // 3. Capturar calificaciones y calcular el promedio inicial
    for (i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    printf("Promedio inicial: %.2f\n", suma / n);

    // 4. Preguntar si desea agregar más estudiantes
    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &agregar);

    // 5. Si el usuario quiere agregar más, usar realloc()
    if (agregar > 0) {
        int nuevo_tamano = n + agregar;

        // Reasignar memoria
        float *temp = (float*) realloc(calificaciones, nuevo_tamano * sizeof(float));

        // Verificar si realloc falló
        if (temp == NULL) {
            printf("Error: no se pudo reasignar memoria.\n");
            free(calificaciones);
            return 1;
        }

        calificaciones = temp; // Actualizar el puntero si realloc fue exitoso

        // Capturar nuevas calificaciones y sumarlas
        for (i = n; i < nuevo_tamano; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        n = nuevo_tamano; // Actualizar el número total de estudiantes
    }

    // 6. Mostrar todas las calificaciones y el promedio final
    printf("\n=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }

    printf("Promedio general: %.2f\n", suma / n);

    // 7. Liberar la memoria utilizada
    free(calificaciones);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
