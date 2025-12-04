# Practica 12 - Top Down (Memorización)
# Fibonacci usando recursividad y un diccionario para guardar resultados

memoria = {}

def fibonacci_top_down(n):
    if n in memoria:
        return memoria[n]

    if n == 0:
        resultado = 0
    elif n == 1:
        resultado = 1
    else:
        resultado = fibonacci_top_down(n-1) + fibonacci_top_down(n-2)

    memoria[n] = resultado
    return resultado


# Prueba básica
posiciones = [7, 21, 40]
for p in posiciones:
    print("Top-Down -> Fibonacci en", p, "=", fibonacci_top_down(p))
