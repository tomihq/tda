/*
    Cuadrado Magico: Un cuadrado magico de orden n es un cuadrado con los numeros {1, ..., n^2} tal que todas sus filas, columnas y las dos diagonales suman lo mismo. 
    El numero que aparece en las filas, columnas y las dos diagonales se llama numero mágico.

    La cantidad de cuadrados magicos que hay es n^2! pues, en un cuadrado magico no se repiten valores, y ademas en cada casillero podemos poner cualquiera de los n^2 valores.

    Por ej: n = 3 tengo numeros del {1, 2, 3, 4, 5, 6, 7, 8, 9} y ahora en el cuadrado de 9 casilleros tengo que colocarlos de tal manera que la suma de sus filas, columnas y diagonales den el mismo numero.

    Ej: [[2, 7, 6], [9, 5, 1], [4, 3, 8]]. Donde (2, 7, 6) es la primera fila, (9, 5, 1) es la segunda y asi sucesivamente.
    
    Chequeos cada vez que pongo un numero:
    Filas suman lo mismo: 
        i = 0 (j=0, j=1, j=2), i = 1 (j=0, j=1, j=2), i = 2 (j=0, j=1, j=2)
    
    Diagonales suman lo mismo: 
        i=0 (j=0), i=1 (j=1), i=2 (j=2)
        i=0 (j=2), i=1 (j=2), i=2 (j=0)

    Columnas suman lo mismo:
        j=0 (i=0, i=1, i=2), j=1 (i=0, i=1, i=2), j=2 (i=0, i=1, i=2)

    Nótese que este es un ejemplo para n = 3. Habria que generalizarlo para cualquier n.

    Entonces la idea seria ir agregando en cada casillero para ir armando el cuadrado magico. Por cada numero que quiero probar, tengo que verificar si efectivamente con ese numero sigue siendo solucion el cuadrado (que las filas, columnas y diagonales den igual). Si no lo es, aplico una poda. 

    Se pide devolver el mayor numero que se consigue con la mejor forma de posicionar los numeros en el cuadrado mágico.
*/
#include <iostream>
#include <vector>

void colocarEnPosicion(const std::vector<std::vector<int>>& matriz, int i, int j, int n){
    if(i == n-1 && j == n-1) return; 

    matriz[i][j] = n; 
    
    if(i == n-1){
       i = 0;
    }else{
        i++;
    }

    if(j == n-1){
        j = 0;
    }else{
        j++; 
    }

}

bool esCuadradoMagico(const std::vector<std::vector<int>>& matriz, int n){
    int suma = 0; 
    //Chequeo todas filas -> Si la suma de toda la fila es mayor a la previamente calculada entonces arrojo false.
    for(int i = 0; i<n; i++){
        int suma_interna = 0; 
        for(int j = 0; j<n; j++){
            suma_interna += matriz[i][j]; //Fila 1 Columna 1, Fila 1 Columna 2, Fila 1 Columna 3..
            if(j == n-1){ //ya sume todo
                if(suma == 0){
                    suma = suma_interna;
                }else if(suma != suma_interna){
                    return false; 
                }
            }
        }
    }


    //Chequeo todas las diagonales -> Acá por suerte ya tengo la suma "global" por lo tanto necesito ver que las dos diagonales no sean diferentes a la suma global de las filas. No me fijo ni siquiera si las diagonales son diferentes porque todas deberian sumar igual que la fila, columna o lo que sea para agregarse.
    int suma_interna_izq_der = 0; 
    int suma_interna_der_izq = 0;
     for(int i = 0; i<n; i++){
            suma_interna_izq_der += matriz[i][i];
            suma_interna_der_izq += matriz[i][n-i-1];
            
            if(i == n-1){ //ya sume todo
                if(suma != suma_interna_izq_der || suma != suma_interna_der_izq){
                        return false; 
                    }
            }
    }
    //Chequeo todas las columnas -> Acá por suerte ya tengo la "suma" global por lo tanto lo unico que hago es comparar la suma interna con la suma de las filas.
     for(int i = 0; i<n; i++){
        int suma_interna = 0; 
        for(int j = 0; j<n; j++){
            suma_interna += matriz[j][i]; //Fila 1 Columna 1, Fila 2 Columna 1, Fila 3 Columna 1..
            if(j == n-1){ //ya sume todo
                if(suma == 0){
                    suma = suma_interna;
                }else if(suma != suma_interna){
                    return false; 
                }
            }
        }
    }

    return true; 
}




int main(){
    int n = 0;
    std::cout << "Ingrese el orden del Cuadrado Mágico" << std::endl;
    std::cin >> n; 
    std::vector<std::vector<int>> matriz = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };
    bool res = esCuadradoMagico(matriz, n);
    std::cout << res << std::endl;
    return 0;
}
