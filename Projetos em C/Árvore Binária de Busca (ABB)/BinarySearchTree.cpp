#include "BinarySearchTree.h"
#include <iostream>

// Construtor: inicializa a raiz como nula.
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Destrutor: chama a função auxiliar para liberar a memória.
BinarySearchTree::~BinarySearchTree() {
    destruirAux(root);
}

void BinarySearchTree::inserir(int data) {
    root = inserirAux(root, data);
}

void BinarySearchTree::percursoEmOrdem() const {
    std::cout << "Percurso Em-Ordem (valores ordenados): [ ";
    percursoEmOrdemAux(root);
    std::cout << "]" << std::endl;
}

void BinarySearchTree::mostrarFolhas() const {
    std::cout << "Nos folha da arvore: [ ";
    mostrarFolhasAux(root);
    std::cout << "]" << std::endl;
}

TreeNode* BinarySearchTree::inserirAux(TreeNode* node, int data) {
    if (node == nullptr) {
        return new TreeNode(data);
    }

    if (data < node->data) {
        node->left = inserirAux(node->left, data);
    } else if (data > node->data) {
        node->right = inserirAux(node->right, data);
    }
    
    return node;
}

void BinarySearchTree::percursoEmOrdemAux(TreeNode* node) const {
    if (node != nullptr) {
        percursoEmOrdemAux(node->left);
        std::cout << node->data << " ";
        percursoEmOrdemAux(node->right);
    }
}

void BinarySearchTree::mostrarFolhasAux(TreeNode* node) const {
    if (node == nullptr) {
        return;
    }

    if (node->left == nullptr && node->right == nullptr) {
        std::cout << node->data << " ";
    }
    
    mostrarFolhasAux(node->left);
    mostrarFolhasAux(node->right);
}

void BinarySearchTree::destruirAux(TreeNode* node) {
    if (node != nullptr) {
        destruirAux(node->left);
        destruirAux(node->right);
        delete node;
    }
}
