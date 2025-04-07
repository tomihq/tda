#include <iostream>
#include <vector>
void backtracking(int i, int k, std::vector<int>* conj, std::vector<int>* solution){
    if(k < 0 || i >= conj->size() ) return; 
    if(k == 0) {
        for (int n : *solution) std::cout << n << " ";
        std::cout << std::endl;
        return;
    }
    solution -> push_back((*conj)[i]);
    backtracking(i+1, k-(*conj)[i], conj, solution);
    solution->pop_back();
    backtracking(i+1, k, conj, solution);
}

int main(){
    int k = 0; 
    std::cout << "Ingrese el k deseado: "; 
    std::cin >> k;
    std::vector<int> conj = {1, 1, 2, 3, 4};
    std::vector<int> solution = {};

    backtracking(0, k, &conj, &solution);
    return 0;
}
