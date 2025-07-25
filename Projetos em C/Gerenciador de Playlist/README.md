
## Estrutura de Dados

- **`MusicNode`**: Cada nó da lista armazena o ID da música (`musicaID`) e dois ponteiros: `next` para o próximo nó e `prev` para o nó anterior.
- **`Playlist`**: A classe que gerencia a lista. Ela utiliza um único ponteiro (`cursor`) que aponta para a música "atualmente selecionada", a partir da qual todas as operações de navegação e manipulação são realizadas.

## Operações Implementadas

A classe `Playlist` oferece as seguintes operações:

**`incluir(int musicaID)`**: Adiciona uma nova música à playlist. A nova música é inserida antes da música atual no cursor.
    * *Complexidade:* $O(1)$
**`procurar(int musicaID)`**: Busca por uma música na playlist e retorna sua posição relativa.
    * *Complexidade:* $O(n)$
* **`exibir()`**: Mostra todas as músicas na playlist, em ordem, a partir da música atual.
    * *Complexidade:* $O(n)$
* **`tocarProxima()` / `tocarAnterior()`**: Simula a navegação na playlist, avançando ou retrocedendo o cursor.
    * *Complexidade:* $O(1)$
* **`statusAtual()`**: Mostra qual música está selecionada no cursor.
    * *Complexidade:* $O(1)$

## Como Compilar e Executar

Compile todos os arquivos `.cpp` juntos para criar o executável.

```bash
# Comando para compilar o projeto
g++ main.cpp Playlist.cpp -o playlist_demo

# Comando para executar o programa de demonstração
./playlist_demo
