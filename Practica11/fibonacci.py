# Práctica 11 - Recursividad
# Fibonacci recursivo con memorización (versión sencilla)

memoria = {}

def fibonacci(n):
    if n in memoria:
        return memoria[n]

    if n == 0:
        resultado = 0
    elif n == 1:
        resultado = 1
    else:
        resultado = fibonacci(n-1) + fibonacci(n-2)

    memoria[n] = resultado
    return resultado


posiciones = [7, 21, 40, 71, 94]

for p in posiciones:
    print("Fibonacci en la posición", p, "es:", fibonacci(p))
