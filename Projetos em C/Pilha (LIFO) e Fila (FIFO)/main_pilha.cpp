#include <iostream>
#include "Pilha.h"

int main() {
    Pilha p;
    std::cout << "--- Demonstracao de Pilha (LIFO) ---" << std::endl;

    std::cout << "\nEmpilhando 10, 20 e 30..." << std::endl;
    p.push(10);
    p.push(20);
    p.push(30);
    p.exibir();

    std::cout << "Elemento no topo: " << p.top() << std::endl;

    std::cout << "\nDesempilhando um elemento..." << std::endl;
    p.pop();
    p.exibir();
    std::cout << "Novo elemento no topo: " << p.top() << std::endl;

    std::cout << "\nDesempilhando todos os elementos..." << std::endl;
    while(!p.estaVazia()){
        std::cout << "Removido: " << p.top() << std::endl;
        p.pop();
    }
    p.exibir();
    
    std::cout << "\n--- Fim da Demonstracao ---" << std::endl;

    return 0;
}
