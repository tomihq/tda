def mas_a_la_izquierda(arr):
    if len(arr) == 1:
        return True  
    
    mitad = len(arr) // 2
    izq = arr[0:mitad]
    der = arr[mitad:]

    suma_izq = sum(izq)
    suma_der = sum(der)

    if suma_izq <= suma_der:
        return False

    return mas_a_la_izquierda(izq) and mas_a_la_izquierda(der)