#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

// Declaração da classe LinkedList, que gerencia as operações da lista.
class LinkedList {
private:
    Node* topo;

public:
    // Construtor: inicializa uma lista vazia.
    LinkedList();
    // Destrutor: libera toda a memória alocada pela lista.
    ~LinkedList();
    void inserir(int data);
    bool remover(int data);
    bool buscar(int data) const;
    void exibir() const;
    bool estaVazia() const;
};

#endif //LINKEDLIST_H
