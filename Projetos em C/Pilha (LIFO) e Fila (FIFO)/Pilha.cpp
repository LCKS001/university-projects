#include "Pilha.h"
#include <iostream>
#include <stdexcept>

Pilha::Pilha() : topo(nullptr) {}

Pilha::~Pilha() {
    while (!estaVazia()) {
        pop();
    }
}

bool Pilha::estaVazia() const {
    return topo == nullptr;
}

void Pilha::push(int data) {
    Node* novoNode = new Node;
    novoNode->data = data;
    novoNode->next = topo;
    topo = novoNode;
}

void Pilha::pop() {
    if (estaVazia()) {
        throw std::runtime_error("Erro: pop em uma pilha vazia.");
    }
    Node* temp = topo;
    topo = topo->next;
    delete temp;
}

int Pilha::top() const {
    if (estaVazia()) {
        throw std::runtime_error("Erro: top em uma pilha vazia.");
    }
    return topo->data;
}

void Pilha::exibir() const {
     if (estaVazia()) {
        std::cout << "Pilha: (vazia)" << std::endl;
        return;
    }

    Node* atual = topo;
    std::cout << "Pilha: ";
    while (atual != nullptr) {
        std::cout << atual->data << " | ";
        atual = atual->next;
    }
    std::cout << std::endl;
}
