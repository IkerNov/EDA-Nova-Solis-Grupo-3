# Practica 10 - Algoritmo Greedy (Cambio de monedas)
# Version sencilla

def greedy_cambio(cantidad, monedas):
    resultado = []
    
    for moneda in monedas:
        while cantidad >= moneda:
            cantidad -= moneda
            resultado.append(moneda)

    return resultado


# Prueba
monedas = [50, 20, 10, 5, 1]
cambio = 87

print("Monedas disponibles:", monedas)
print("Cambio a regresar:", cambio)
print("Resultado:", greedy_cambio(cambio, monedas))
