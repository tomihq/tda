graph = [
    [(1, 2), (2, 3)], # (nodo con que conecta (indice), peso) 
    [(2, 1)],          
    [(3, 4)],          
    [(0, 3)]                 
]
def bellman_ford(graph, start): 
    V = len(graph)
    dist = [float('inf')] * V
    dist[start] = 0

    for _ in range(V-1):
        for u in range(V):
            for v, peso in graph[u]:
                if(dist[u] + peso < dist[v]):
                    dist[v] = dist[u] + peso; 

    # Detecto ciclos negativos
    for u in range(V): 
        for v, peso in graph[u]:
            if(dist[u] + peso < dist[v]):
                print("Hay ciclo negativo");
                return None; 

    return dist 

print(bellman_ford(graph, start=1))
'''
    Con start = 1 (nodo 2) esperamos:
    Al 0 (nodo 1): 8 (porque pasa por el nodo 2, 3, 4 (indices 1, 2, 3))
    Al 1 (nodo 2): 0 porque es el mismo desde donde inicia.
    y así sucesivamente
'''
