#include <iostream>
#include <vector> 

std::vector<std::vector<int>> matriz = {{5, 4, 1}, {0, 3, 2}, {1, 0, 5}};
int n = 3;
int menor_suma = 0; 
std::vector<int> mejor_solucion(n, -1);

int sumaParcial(std::vector<int>& solucion_parcial){
    int suma = 0; 
    for (size_t i = 0; i < solucion_parcial.size(); ++i) {
        int j = i % n;
        int k = (j+1) % n; 
        suma+=matriz[j][k];
    }
    return suma; 
}

void rutaMinima(int i, std::vector<int>& solucion_parcial, std::vector<bool>& usados)
{   
    if(i>n) return; 
    if(i == n){
        int suma_parcial = sumaParcial(solucion_parcial);
        if(suma_parcial < menor_suma){ //Poda por factibilidad
            menor_suma = suma_parcial; 
            mejor_solucion = solucion_parcial;
        }
         for (size_t i = 0; i < solucion_parcial.size(); ++i) {
                std::cout << solucion_parcial[i] << " ";
         }
        return; 
    }
    
    for(int k = 0; k < n; k++){
        if(!usados[k]){
            usados[k] = true; 
            solucion_parcial[i] = k;
            
            rutaMinima(i + 1, solucion_parcial, usados);

            usados[k] = false;
        }
        
    }


}

int main(){
    std::vector<int> solucion_parcial(n, -1);
    std::vector<bool> usados(n, false);
    rutaMinima(0, solucion_parcial, usados);
    std::cout << "La permutación que arroja la suma mínima es: ";
     for (size_t i = 0; i < solucion_parcial.size(); ++i) {
        std::cout << solucion_parcial[i] << " ";
    }
    return 0; 
}