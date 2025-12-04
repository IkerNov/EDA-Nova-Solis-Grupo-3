# Practica 10 - Insertion Sort
# Implementacion sencilla para ordenar una lista

def insertion_sort(lista):
    for i in range(1, len(lista)):
        valor = lista[i]
        j = i - 1

        while j >= 0 and lista[j] > valor:
            lista[j + 1] = lista[j]
            j -= 1

        lista[j + 1] = valor

    return lista


# Prueba
numeros = [8, 3, 5, 2, 9, 1]
print("Lista original:", numeros)
print("Lista ordenada:", insertion_sort(numeros))
