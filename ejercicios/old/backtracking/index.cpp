/* Tengo que irme de viaje. Necesito cargar un CD que acepta máximo k segundos y necesito cargar las canciones más largas.

Como es comun en backtracking, la idea es que las canciones tengan una duracion pero a nivel codigo las tengo que manejar con 1 y 0 de si estan cargadas o no.

Ejemplo: c = [3, 5, 2] a medida que hago la solucion parcial deberia ser algo asi [1, 0, 0] o [0, 1, 0] donde el 1 indica que la canción está en el subconjunto. Ahora, notése que cuando tengo que sumar las duraciones necesito mapear el elemento que quiero agregar o no, para ver cual es la duración que le agrega.

El ejercicio pide devolver que suma (en tiempo) es la mejor, y qué array en 1's y 0's es la mejor opcion para el CD.

Una de las podas que podemos hacer es que: 
    1. Si voy a exceder los k segundos a la hora de agregar otra cancion, no hago nada. Solamente vuelvo.
    2. Si la suma que tengo (en tiempo) es menor o igual a k segundos pero es mayor a otra que ya encontré, entonces esta combinacion es mejor y ocupa más tiempo.

Recordemos que el Backtracking es una tecnica de fuerza bruta que lo que hacemos basicamente es hacer dos llamados recursivos simulanteamente que es lo que "se puede entender" como que armamos un árbol.
Las dos llamadas recursivas tienen las siguientes particularidades:
    1. En la primera enviamos la informacion tal cual nos llega, no hacemos nada pero si quitamos el elemento que era protagonista del paso recursivo.
    2. En la segunda enviamos la informacion, quitando el elemento que era protagonista del paso recursivo y sumamos la duracion que tuvimos hasta ese momento.

    En codigo empezamos teniendo todo vacio (tiempo 0), y tenemos que ir agregando contando cuantos niveles bajamos hasta un maximo.

Esta solucion es por FACTIBILIDAD.
Si quisieramos una solucion por OPTIMALIDAD, deberiamos apenas encontramos una solucion nos fijamos si las otras sumando todas las canciones que faltan si superan a la solucion encontrada sigo, sino, corto ahi.

*/
#include <iostream>
#include <vector>
int k;
int n;
std::vector<int> mayor_arr_duracion;
std::vector<int> duraciones = { 2, 4, 5 };
int mayor_duracion = 0;

void cd(int sum, int nivel, std::vector<int> sol_parcial){
    if(sum > k) return; 
    if(nivel == n){ //Solucion candidata.
        if(sum <= k && sum > mayor_duracion){
            mayor_duracion = sum; 
            mayor_arr_duracion = sol_parcial;
        }
    }else {
        sol_parcial[nivel] = 1;
        cd(sum + duraciones[nivel], nivel+1, sol_parcial);
        sol_parcial[nivel] = 0;
        cd(sum, nivel+1, sol_parcial);
    }
}


int main(){
    std::cout << "Ingrese la duración maxima del CD" << std::endl;
    std::cin >> k;
    std::cout << "Ingrese la cantidad de canciones que quiere contemplar" << std::endl;
    std::cin >> n;
    cd(0, 0, {0, 0, 0});
    std::cout << "Array" << std::endl;
     for (size_t i = 0; i < mayor_arr_duracion.size(); ++i) {
        std::cout << mayor_arr_duracion[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Mayor Duracion: ";
    std::cout << mayor_duracion;
}
