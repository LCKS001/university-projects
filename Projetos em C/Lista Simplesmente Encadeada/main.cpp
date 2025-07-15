#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList lista;

    std::cout << "--- Demonstracao de Lista Simplesmente Encadeada ---" << std::endl;

    lista.exibir();
    std::cout << "A lista esta vazia? " << (lista.estaVazia() ? "Sim" : "Nao") << std::endl;
    
    std::cout << "\nInserindo os valores 10, 20 e 30..." << std::endl;
    lista.inserir(10);
    lista.inserir(20);
    lista.inserir(30);
    lista.exibir();
    
    std::cout << "\nBuscando pelo valor 20: " << (lista.buscar(20) ? "Encontrado" : "Nao encontrado") << std::endl;
    std::cout << "Buscando pelo valor 99: " << (lista.buscar(99) ? "Encontrado" : "Nao encontrado") << std::endl;

    std::cout << "\nRemovendo o valor 20 (elemento do meio)..." << std::endl;
    lista.remover(20);
    lista.exibir();

    std::cout << "\nRemovendo o valor 30 (primeiro elemento)..." << std::endl;
    lista.remover(30);
    lista.exibir();

    std::cout << "\nTentando remover o valor 100 (nao existe)..." << std::endl;
    bool removido = lista.remover(100);
    std::cout << "Elemento 100 foi removido? " << (removido ? "Sim" : "Nao") << std::endl;
    lista.exibir();

    std::cout << "\nRemovendo o valor 10 (ultimo elemento)..." << std::endl;
    lista.remover(10);
    lista.exibir();
    std::cout << "A lista esta vazia? " << (lista.estaVazia() ? "Sim" : "Nao") << std::endl;
    
    std::cout << "\n--- Fim da Demonstracao ---" << std::endl;

    return 0;
}
