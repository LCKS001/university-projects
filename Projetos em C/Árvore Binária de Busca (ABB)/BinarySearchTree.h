#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

class BinarySearchTree {
private:
    TreeNode* root;
    
    // Funções auxiliares recursivas (implementadas no .cpp).
    TreeNode* inserirAux(TreeNode* node, int data);
    void percursoEmOrdemAux(TreeNode* node) const;
    void mostrarFolhasAux(TreeNode* node) const;
    void destruirAux(TreeNode* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void inserir(int data);
    void percursoEmOrdem() const;
    void mostrarFolhas() const;
};

#endif //BINARYSEARCHTREE_H
