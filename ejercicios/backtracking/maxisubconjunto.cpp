#include <iostream>
#include <vector>

std::vector<int> maxi_conjunto; //Esto en realidad deberia ser mas dinamico, deberia ser de longitud k.
int k = 2; 
int n = 3; 
std::vector<std::vector<int>> matriz_valores = {{0, 10, 1}, {1, 2, 0}, {10, 0, 2}};
int mayor_suma = 0; 

//Si k = 2, n = 3 -> {{10, 0, 2}, {0, 10, 1}}
void maxisubconjunto(int decisiones_tomadas, std::vector<int> &solucion_parcial){
    if(decisiones_tomadas > k) return;
    if(decisiones_tomadas == k){
        
         //entonces aca ya arme todos los posibles subconjuntos
         int acum = 0; 
         for(int i = 0; i<k; i++){
            if(i == solucion_parcial[i]){ //Si i = al valor de la fila que esta en el posible subconjunto sumo los valores de esa fila.
                for(int j = 0; j<n; j++){
                    acum += matriz_valores[i][j];
                }
            }
         }
         if(acum > mayor_suma){
            maxi_conjunto = solucion_parcial;
         }
    }else{
        
        int inicio = decisiones_tomadas == 0 ? 0 : solucion_parcial[decisiones_tomadas - 1] + 1;

        for(int i = inicio; i<n; i++){
            solucion_parcial[decisiones_tomadas] = i; 
            maxisubconjunto(decisiones_tomadas+1, solucion_parcial);
        }
    }
}
int main(){
    std::vector<int> solucion_parcial(k);
    maxisubconjunto(0, solucion_parcial);
     for (size_t i = 0; i < maxi_conjunto.size(); ++i) {
                std::cout << maxi_conjunto[i] << " ";
            }
            std::cout << " " << std::endl;
    
    return 0; 
}