#include <iostream>
#include <vector>

int p = 5; 
int n = 3;
std::vector<int> canciones_duraciones = {1, 4, 2};
int mejor_combinacion = 0; 
std::vector<int> mejor_set = {};

void procesarCanciones(int i, int sum, std::vector<int> &sol_parcial){
    if(i > n) return; 
    if(sum > p) return; 
    if(i == n){
        if(sum <= p && sum > mejor_combinacion){
            mejor_combinacion = sum; 
            mejor_set = sol_parcial; 
        }
    }
   else{
     sol_parcial[i] = 1;
     procesarCanciones(i+1, sum + canciones_duraciones[i], sol_parcial);
     sol_parcial[i] = 0; 
     procesarCanciones(i+1, sum, sol_parcial);
   }
}

int main(){
    std::vector<int> sol_parcial = {0, 0, 0};
    procesarCanciones(0, 0, sol_parcial);
    std::cout << mejor_combinacion << std::endl;
     for (size_t i = 0; i < mejor_set.size(); ++i) {
        std::cout << mejor_set[i] << " ";
    }
    /* std::cout << "Ingrese los minutos que soporta el CD" << std::endl;
    std::cin >> p; 
    std::cout << "Ingrese la lista de canciones" << std::endl;
    std:: */
    return 0; 
}