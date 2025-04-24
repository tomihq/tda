from dfs import dfs
'''
    Objetivo: Recorrer cada componente conexa y si todas lo son, el grafo G es conexo.
    1. Recibo grafo en forma de lista de adyacencias. Empiezo desde indice 0 (nodo 1), cada aparicion del nodo luego al final hay que sumarle 1 pues el 0 es el nodo 1.
    2. Empiezo desde un nodo particular, lo guardo como visitado (como voy a recorrer mas de una vez un nodo por el for mas externo, antes de hacer dfs me fijo si no esta en la lista, si no esta hago dfs.) y me fijo sus vecinos. Si el vecino w no esta en la lista hago dfs. Esto indica que el inicio de "dfs" lo tengo que hacer varias veces porque con una única vez recorro los vecinos del primer nodo. 
    3. Al final de todo hago un print de todos los nodos visitados pero sumandoles 1 (un map).
'''
graph = [[1, 3], [2], [1], [0], [5], [4]]

def is_connected_graph(graph): 
    visited = []; 
    for i in range(0, len(graph)):
        if i not in visited: 
            dfs(i, visited, graph)
    if(len(visited) == len(graph)):
        print("El grafo G es conexo pues sus componentes conexas lo son");
    else:
        print("No es conexo")


is_connected_graph(graph)