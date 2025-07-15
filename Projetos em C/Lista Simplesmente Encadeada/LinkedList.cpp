#include "LinkedList.h"
#include <iostream>

// Implementação do construtor
LinkedList::LinkedList() : topo(nullptr) {}

// Implementação do destrutor
LinkedList::~LinkedList() {
    Node* atual = topo;
    while (atual != nullptr) {
        Node* proximo = atual->next;
        delete atual;
        atual = proximo;
    }
}

bool LinkedList::estaVazia() const {
    return topo == nullptr;
}

void LinkedList::inserir(int data) {
    Node* novoNode = new Node;
    novoNode->data = data;
    novoNode->next = topo;
    topo = novoNode;
}

void LinkedList::exibir() const {
    if (estaVazia()) {
        std::cout << "Lista: (vazia)" << std::endl;
        return;
    }

    Node* atual = topo;
    std::cout << "Lista: ";
    while (atual != nullptr) {
        std::cout << atual->data << " -> ";
        atual = atual->next;
    }
    std::cout << "NULL" << std::endl;
}

bool LinkedList::buscar(int data) const {
    Node* atual = topo;
    while (atual != nullptr) {
        if (atual->data == data) {
            return true;
        }
        atual = atual->next;
    }
    return false;
}

bool LinkedList::remover(int data) {
    if (estaVazia()) {
        return false;
    }

    // Caso 1: O nó a ser removido é o primeiro (topo)
    if (topo->data == data) {
        Node* temp = topo;
        topo = topo->next;
        delete temp;
        return true;
    }

    // Caso 2: O nó a ser removido está no meio ou no fim da lista
    Node* anterior = topo;
    Node* atual = topo->next;

    while (atual != nullptr) {
        if (atual->data == data) {
            anterior->next = atual->next;
            delete atual;
            return true;
        }
        anterior = atual;
        atual = atual->next;
    }

    return false;
}
