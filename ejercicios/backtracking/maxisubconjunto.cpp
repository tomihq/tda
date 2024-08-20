#include <iostream>
#include <vector>

int k = 2; //O(log k) = O(1)
int n = 3; //O(log n) = O(1)
std::vector<std::vector<int>> matriz_valores = {
    {1, 2, 3},
    {0, 4, 2},
    {0, 0, 6},
}; //O(n^2)

int mayor_suma = 0; //O(log mayor_suma) => O(1)
std::vector<int> maxi_conjunto;

int calcular_suma_submatriz(const std::vector<int>& indices) {
    int suma = 0; //O(1)
    for (size_t i = 0; i < indices.size(); ++i) {    
        for (size_t j = i; j < indices.size(); ++j) {
            if (i == j) {
                // Sumar el elemento diagonal una sola vez
                suma += matriz_valores[indices[i]][indices[j]]; //O(1)
            } else {
                // Sumar una sola vez cada par de elementos simétricos
                suma += matriz_valores[indices[i]][indices[j]] * 2; //O(1)
            }
        }
    }
    return suma;
}


void generar_combinaciones(int start, int depth, std::vector<int>& current_combination) {
    if (depth == k) {
        int suma_actual = calcular_suma_submatriz(current_combination);
        if (suma_actual > mayor_suma) {
            mayor_suma = suma_actual;
            maxi_conjunto = current_combination;
        }
        return;
    }

    for (int i = start; i < n; ++i) { // 0 hasta n -> O(n^k * (n + n^2)) -> O(n^k)
        current_combination[depth] = i;
        generar_combinaciones(i + 1, depth + 1, current_combination);
    }
}

int main() {
    std::vector<int> current_combination(k); //O(k)
    generar_combinaciones(0, 0, current_combination);

    std::cout << "La combinación de filas que maximiza la suma es: ";
    for (int i : maxi_conjunto) {
        std::cout << i + 1 << " "; // +1 para representar filas en formato 1-indexado
    }
    std::cout << std::endl;

    std::cout << "La mayor suma es: " << mayor_suma << std::endl;

    return 0;
}

//Espacial: O(n^2 + k) = O(n^2).
//Temporal: O(k^n)