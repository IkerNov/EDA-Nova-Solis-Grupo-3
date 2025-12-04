# Practica 12 - Bottom Up (Programación Dinámica)
# Fibonacci usando una tabla desde abajo hacia arriba

def fibonacci_bottom_up(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    tabla = [0, 1]  # casos base

    for i in range(2, n + 1):
        tabla.append(tabla[i-1] + tabla[i-2])

    return tabla[n]


# Prueba básica
posiciones = [7, 21, 40]
for p in posiciones:
    print("Bottom-Up -> Fibonacci en", p, "=", fibonacci_bottom_up(p))
