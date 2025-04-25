'''
    Precondición: Es un grafo dirigido acíclico. De lo contrario, no tiene sentido hacer un orden topológico porque es una dependencia circular.
    Ej.: A -> B -> C -> A como para hacer A necesito A, B y C no tiene sentido
    Idea: 
        1. Usar DFS pero ligeramente modificado. 
        2. Tengo que hacer un for para recorrer todas las ramas del grafo, no solo con un nodo inicial.
        3. Cada nodo va a estar "en progreso" cuando entra a dfs, y vamos a tener dos casos.
            a. Vamos a recorrer todos los vecinos llamados w. 
                Si llegue a un vecino que ya estaba en progreso entonces hay un ciclo.
                Si no está visitado hago dfs y si termina devuelvo true. 
        4. Cuando salga del for ponemos que el in progress ahora es false, y que ese nodo ya fue visitado.
'''
graph = [[1, 3], [2], [1], [0], [5], [4]]
def is_acyclic_graph(graph):
    n = len(graph)
    visited = [False] * n;
    in_progress = [False] * n;

    for i in range(n):
        if not visited[i]:
            if(dfs(i, visited, in_progress, graph)):
                print("No es acíclico")
                return False
    print("Es acíclico")
    return True


def dfs(start, visited, in_progress, graph): 
    in_progress[start] = True 
    for w in graph[start]:
        if in_progress[w]:    
            return True 
        if not visited[w]:
            if dfs(w, visited, in_progress, graph):
                return True 
    in_progress[start] = False 
    visited[start] = True 
    return False 

is_acyclic_graph(graph)
