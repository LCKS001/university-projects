#include <iostream>
#include "Playlist.h"

int main() {
    Playlist minhaPlaylist;

    std::cout << "--- Gerenciador de Playlist ---" << std::endl;
    
    std::cout << "\nIncluindo musicas (IDs: 101, 205, 333, 48)..." << std::endl;
    minhaPlaylist.incluir(101);
    minhaPlaylist.incluir(205);
    minhaPlaylist.incluir(333);
    minhaPlaylist.incluir(48);

    minhaPlaylist.exibir();
    
    std::cout << "\nProcurando musicas..." << std::endl;
    std::cout << minhaPlaylist.procurar(333) << std::endl;
    std::cout << minhaPlaylist.procurar(999) << std::endl;

    std::cout << "\n--- Iniciando Player ---" << std::endl;
    minhaPlaylist.statusAtual();
    
    std::cout << "\n>> Avancando para proxima..." << std::endl;
    minhaPlaylist.tocarProxima();
    minhaPlaylist.statusAtual();

    std::cout << ">> Avancando para proxima..." << std::endl;
    minhaPlaylist.tocarProxima();
    minhaPlaylist.statusAtual();
    
    std::cout << "\n<< Voltando para anterior..." << std::endl;
    minhaPlaylist.tocarAnterior();
    minhaPlaylist.statusAtual();

    std::cout << "\n>> Avancando 3x para demonstrar o loop..." << std::endl;
    minhaPlaylist.tocarProxima();
    minhaPlaylist.tocarProxima();
    minhaPlaylist.tocarProxima();
    minhaPlaylist.statusAtual();

    std::cout << "\n--- Fim da Demonstracao ---" << std::endl;

    return 0;
}
