#include <vector>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int min(int i, int k) {
    return (i > k) ? k : i;
}

long long nroCombinatorio(int n, int k) {
    vector<long long> prev(k + 1, 0);
    vector<long long> curr(k + 1, 0);

    prev[0] = 1;

    for (int i = 1; i <= n; i++) {
        curr[0] = 1;
        for (int j = 1; j <= min(i, k); j++) {
            curr[j] = prev[j - 1] + prev[j];
        }
        swap(prev, curr); 
    }

    return prev[k];
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
    long long res = nroCombinatorio(n, k);
    cout << res; 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "El tiempo de ejecucion es: " << duration.count() << " milisegundos" << std::endl;
    return 0;
}
