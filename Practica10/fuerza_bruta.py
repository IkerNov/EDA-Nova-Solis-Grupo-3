# Practica 10 - Fuerza bruta para encontrar contraseña
# Version sencilla para un estudiante

import itertools

def fuerza_bruta_contraseña(longitud, contraseña_real):
    digitos = "0123456789"

    for combinacion in itertools.product(digitos, repeat=longitud):
        intento = "".join(combinacion)
        if intento == contraseña_real:
            return intento

    return None


# Pruebas con 4, 8 y 10 dígitos
print("Buscando contraseña de 4 dígitos...")
print("Encontrada:", fuerza_bruta_contraseña(4, "1234"))

print("Buscando contraseña de 8 dígitos...")
print("Encontrada:", fuerza_bruta_contraseña(8, "12345678"))

print("Buscando contraseña de 10 dígitos...")
print("Encontrada:", fuerza_bruta_contraseña(10, "0123456789"))
