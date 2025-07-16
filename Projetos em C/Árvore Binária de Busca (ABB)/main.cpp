#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;
    std::cout << "--- Demonstracao de Arvore Binaria de Busca ---" << std::endl;
    std::cout << "\nInserindo valores na arvore: 50, 30, 70, 20, 40, 60, 80, 35, 45..." << std::endl;
    bst.inserir(50);
    bst.inserir(30);
    bst.inserir(70);
    bst.inserir(20);
    bst.inserir(40);
    bst.inserir(60);
    bst.inserir(80);
    bst.inserir(35);
    bst.inserir(45);
    std::cout << std::endl;
    bst.percursoEmOrdem();
    bst.mostrarFolhas();
    std::cout << "\n--- Fim da Demonstracao ---" << std::endl;
    return 0;
}
