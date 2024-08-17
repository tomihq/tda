/*
    Me dan dos datos un conjunto C = {6, 12, 6} y tengo que armar subconjuntos que en el ultimo nivel den k = 12.

    Posibles rtas: {0, 1, 0}, {1, 0, 1}

    Poda por factibilidad: 
        Si i > cantElementos return
        Si i = cantElementos y la suma es <= k entonces me fijo si esa suma > suma_encontrada. Si lo es la guardo.
    
    Si quiero guardar el subconjunto que lo arma, tengo que armar otro vector (de la misma longitud) que los conjuntos para poder indicando si el numero esta presente o no.

    Es decir: {1, 0, 1} es {6, 0, 6}
*/
#include <iostream>
#include <vector>

std::vector<int> c = {6, 12, 6};
std::vector<int> solucion_c = {0, 0, 0};
int cant = c.size();
int k = 12; 
int mejor_solucion = 0; 

void sumasubconjuntos(int i, int suma, std::vector<int> &solucion_parcial){
    if(i > cant) return; 
    if(suma > k) return; 
    if(i == cant && suma <= k){
        if(suma > mejor_solucion){
            mejor_solucion = suma;
            solucion_c = solucion_parcial; 
        }
    }else{ 
        //caso está en la solucion
        solucion_parcial[i] = 1;
        sumasubconjuntos(i+1, suma + c[i], solucion_parcial);
        //caso no esta en solucion
        solucion_parcial[i] = 0;
        sumasubconjuntos(i+1, suma, solucion_parcial);
    }
}

int main(){
    std::vector<int> sol_parcial = {0, 0, 0};
    sumasubconjuntos(0, 0, sol_parcial);
     for (size_t i = 0; i < solucion_c.size(); ++i) {
        std::cout << solucion_c[i] << " ";
    }
    return 0; 
}