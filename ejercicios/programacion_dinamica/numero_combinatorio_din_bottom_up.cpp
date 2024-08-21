#include <vector>
#include <iostream>
#include <chrono>
using namespace std; 
using namespace std::chrono; 

int min(int i, int k) {
    if(i>k) return k; //O(1)
    return i; 
}

long long nroCombinatorio(int n, int k, vector<vector<long long>>& memo){
    for(int i = 1; i<=n; i++){
        memo[i][0] = 1;     //O(n)
    }

    for(int j = 0; j<=k; j++){ //O(k)
        memo[j][j] = 1;
    }

    for(int i = 2; i<=n; i++){ //O(n)
        for(int j = 1; j<=min(i-1, k); j++){ //O(k) -> Pues si fuese i-1, iria hasta n, pero si n es estrictamente mas grande que k, estallaria.
            memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
        }
    }

    //O(1 + n+k+(n*k)) = O(n+k + 1) = O(n*k) -> TEMPORAL
    //O(1 + 1 + n*k) = O(n*k) -> ESPACIAL

    return memo[n][k];

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