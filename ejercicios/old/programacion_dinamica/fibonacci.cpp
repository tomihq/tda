#include <iostream>
#include <vector>

long long fibo(long long n, std::vector<long long>& memo){
    if(memo[n] != -1){
        return memo[n]; 
    }
    if(n == 0) return 0; 
    if(n == 1) return 1;
    memo[n] = fibo(n-1, memo) + fibo(n-2, memo);
    return memo[n]; 
}

int main() {
    int n = 0; 
    std::cout << n; 
    std::cout << "Ingrese el numero que quiere calcular: " << std::endl; 
    std::cin >> n;
    std::vector<long long> memo(n+1, -1);
    long long res = fibo(n, memo); 
    std::cout << "El resultado de fibonacci es: "; 
    std::cout << res; 
    return 0; 
}