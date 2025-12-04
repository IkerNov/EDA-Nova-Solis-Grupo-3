# Practica 12 - Divide & Conquer
# Implementación básica de QuickSort

def quicksort(lista):
    if len(lista) <= 1:
        return lista

    pivote = lista[0]  # pivote simple
    menores = []
    mayores = []

    for x in lista[1:]:
        if x <= pivote:
            menores.append(x)
        else:
            mayores.append(x)

    return quicksort(menores) + [pivote] + quicksort(mayores)


# Prueba básica
valores = [10, 5, 2, 8, 3, 9, 1]
print("Lista original:", valores)
print("Lista ordenada:", quicksort(valores))
