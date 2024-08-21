#include <vector>
#include <iostream>
#include <chrono>
using namespace std; 
using namespace std::chrono; 
long long nroCombinatorio(int n, int k, vector<vector<long long>>& memo){
    if(k == 0 || k == n) return 1; 
    return nroCombinatorio(n-1, k-1, memo) + nroCombinatorio(n-1, k, memo);
}

int main() {
    auto start = high_resolution_clock::now();
    long n = 0; 
    long k = 0; 
    cout << "" << endl;
    cout << "Ingrese n" << endl; 
    cin >> n; 
    cout << "Ingrese k" << endl;
    cin >> k; 
    vector<vector<long long>> memo(n+1, vector<long long>(k+1, -1));
    long long res = nroCombinatorio(n, k, memo);
    cout << res; 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "El tiempo de ejecucion es: " << duration.count() << " milisegundos" << std::endl;
    return 0;
}