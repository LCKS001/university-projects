#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "MusicNode.h"
#include <string>

class Playlist {
private:
    MusicNode* cursor; 

public:
    Playlist();
    ~Playlist();

    bool estaVazia() const;
    void incluir(int musicaID);
    std::string procurar(int musicaID) const;
    void exibir() const;
    void tocarProxima();
    void tocarAnterior();
    void statusAtual() const;
};

#endif //PLAYLIST_H
