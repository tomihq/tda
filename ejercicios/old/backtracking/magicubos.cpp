#include <iostream>
#include <vector>
#include <math.h>
bool esCuadradoMagico(std::vector<std::vector<int>> &matriz, int n)
{
    int suma = 0;
    // Chequeo todas filas -> Si la suma de toda la fila es mayor a la previamente calculada entonces arrojo false.
    for (int i = 0; i < n; i++)
    {
        int suma_interna = 0;
        for (int j = 0; j < n; j++)
        {
            suma_interna += matriz[i][j]; // Fila 1 Columna 1, Fila 1 Columna 2, Fila 1 Columna 3..
            if (j == n - 1)
            { // ya sume todo
                if (suma == 0)
                {
                    suma = suma_interna;
                }
                else if (suma != suma_interna)
                {
                    return false;
                }
            }
        }
    }

    // Chequeo todas las diagonales -> Acá por suerte ya tengo la suma "global" por lo tanto necesito ver que las dos diagonales no sean diferentes a la suma global de las filas. No me fijo ni siquiera si las diagonales son diferentes porque todas deberian sumar igual que la fila, columna o lo que sea para agregarse.
    int suma_interna_izq_der = 0;
    int suma_interna_der_izq = 0;
    for (int i = 0; i < n; i++)
    {
        suma_interna_izq_der += matriz[i][i];
        suma_interna_der_izq += matriz[i][n - i - 1];

        if (i == n - 1)
        { // ya sume todo
            if (suma != suma_interna_izq_der || suma != suma_interna_der_izq)
            {
                return false;
            }
        }
    }
    // Chequeo todas las columnas -> Acá por suerte ya tengo la "suma" global por lo tanto lo unico que hago es comparar la suma interna con la suma de las filas.
    for (int i = 0; i < n; i++)
    {
        int suma_interna = 0;
        for (int j = 0; j < n; j++)
        {
            suma_interna += matriz[j][i]; // Fila 1 Columna 1, Fila 2 Columna 1, Fila 3 Columna 1..
            if (j == n - 1)
            { // ya sume todo
                if (suma == 0)
                {
                    suma = suma_interna;
                }
                else if (suma != suma_interna)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void generarCuadradoMagico(int n, int i, int j, std::vector<std::vector<int>> &matriz, std::vector<bool> &usado, int &mejorSuma, int sumaExacta)
{
    if (i == n)
    {
        if (esCuadradoMagico(matriz, n))
        {
            int sumaActual = 0;
            for (size_t i = 0; i < matriz.size(); ++i)
            {
                for (size_t j = 0; j < matriz[i].size(); ++j)
                {
                    sumaActual += matriz[i][j];
                }
            }
            if (sumaActual > mejorSuma)
            {
                mejorSuma = sumaActual;
                std::cout << "Nuevo mejor cuadrado mágico encontrado con suma: " << mejorSuma << "\n";
                for (size_t i = 0; i < matriz.size(); ++i)
                {
                    for (size_t j = 0; j < matriz[i].size(); ++j)
                    {
                        std::cout << matriz[i][j] << " ";
                    }
                    std::cout << "\n";
                }
            }
        }
        if(mejorSuma != sumaExacta) return; 
        return;
    }

    int fila = (j + 1 == n) ? i + 1 : i;
    int columna = (j + 1) % n;

    for (int num = 1; num <= n * n; ++num)
    {
        if (!usado[num - 1])
        { // si todavia no use el numero, lo utilizo.
            matriz[i][j] = num;
            usado[num - 1] = true;
            generarCuadradoMagico(n, fila, columna, matriz, usado, mejorSuma, sumaExacta);
            usado[num - 1] = false;
        }
    }
}

int main()
{
    int n;
    std::cout << "Ingrese el orden del Cuadrado Mágico: ";
    std::cin >> n;
    int solucion = (pow(n, 3) + n) / 2;
    std::cout << "posible solucion" << std::endl;

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n, 0));
    std::vector<bool> usado(n * n, false);
    int mejorSuma = 0;

    generarCuadradoMagico(n, 0, 0, matriz, usado, mejorSuma, solucion);

    return 0;
}
