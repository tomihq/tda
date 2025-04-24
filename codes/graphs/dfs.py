'''
    1. Recibo grafo en forma de lista de adyacencias. Empiezo desde indice 0 (nodo 1), cada aparicion del nodo luego al final hay que sumarle 1 pues el 0 es el nodo 1.
    2. Empiezo desde un nodo particular, lo guardo como visitado y me fijo sus vecinos. Si el vecino w no esta en la lista hago dfs. 
    3. Al final de todo hago un print de todos los nodos visitados pero sumandoles 1 (un map).
'''

graph = [[1, 3], [2], [1], [0], [5], [4]]
def main(graph):
    visited = []; 
    dfs(0, visited, graph);
    result = list(map(lambda x: x + 1, visited))
    print(result);

def dfs(start, visited, graph): 
    visited.append(start)
    for w in graph[start]:
        if w not in visited:
            dfs(w, visited, graph)

main(graph)