#include "Playlist.h"
#include <iostream>

Playlist::Playlist() : cursor(nullptr) {}

Playlist::~Playlist() {
    if (estaVazia()) {
        return;
    }
    
    // Quebra o link circular para poder percorrer e deletar
    MusicNode* ultimo = cursor->prev;
    ultimo->next = nullptr;

    MusicNode* atual = cursor;
    while (atual != nullptr) {
        MusicNode* proximo = atual->next;
        delete atual;
        atual = proximo;
    }
}

bool Playlist::estaVazia() const {
    return cursor == nullptr;
}

void Playlist::incluir(int musicaID) {
    MusicNode* novoNode = new MusicNode;
    novoNode->musicaID = musicaID;

    if (estaVazia()) {
        cursor = novoNode;
        cursor->next = cursor;
        cursor->prev = cursor;
    } else {
        novoNode->next = cursor;
        novoNode->prev = cursor->prev;
        cursor->prev->next = novoNode;
        cursor->prev = novoNode;
    }
}

void Playlist::exibir() const {
    if (estaVazia()) {
        std::cout << "Playlist esta vazia." << std::endl;
        return;
    }

    MusicNode* atual = cursor;
    std::cout << "Playlist: [ ";
    do {
        std::cout << atual->musicaID << " ";
        atual = atual->next;
    } while (atual != cursor);
    std::cout << "]" << std::endl;
}

std::string Playlist::procurar(int musicaID) const {
    if (estaVazia()) {
        return "Musica nao encontrada (playlist vazia).";
    }

    MusicNode* temp = cursor;
    int posicao = 1;
    do {
        if (temp->musicaID == musicaID) {
            return "Codigo " + std::to_string(musicaID) + " - musica " + std::to_string(posicao);
        }
        temp = temp->next;
        posicao++;
    } while (temp != cursor);

    return "Musica com ID " + std::to_string(musicaID) + " nao encontrada.";
}

void Playlist::tocarProxima() {
    if (!estaVazia()) {
        cursor = cursor->next;
    }
}

void Playlist::tocarAnterior() {
    if (!estaVazia()) {
        cursor = cursor->prev;
    }
}

void Playlist::statusAtual() const {
    if (estaVazia()) {
        std::cout << "Nenhuma musica tocando (playlist vazia)." << std::endl;
    } else {
        std::cout << "Tocando agora: Musica " << cursor->musicaID << std::endl;
    }
}
