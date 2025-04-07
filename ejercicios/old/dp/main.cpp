#include <iostream>
#include <vector>

long long fibo(int n, std::vector<long long>& memo){
    if(memo[n] != 0) return memo[n];
    
    if(n == 0) return 0;
    if(n == 1) return 1;

    memo[n] = fibo(n-1, memo) + fibo(n-2, memo);
    return memo[n];
}

int main(){
    int n = 0; 
    std::cout << "Ingrese el numero que quiere calcular Fibonacci: " << std::endl;
    std::cin >> n;
    std::vector<long long> memo(n+1, 0); //O(n)
    long long res = fibo(n, memo);
    std::cout << "Su numero de Fibonacci es: ";
    std::cout << res;
    return 0; 
}