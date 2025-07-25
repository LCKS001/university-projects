
## Estrutura de Dados

A Lista Simplesmente Encadeada é uma coleção de `Nós` (Nodes) que, juntos, representam uma sequência.

* **`Node`**: Cada nó na lista contém dois campos:
    * `data`: O valor armazenado no nó (neste caso, um `int`).
    * `next`: Um ponteiro para o próximo nó na sequência. O ponteiro do último nó aponta para `nullptr`.
* **`LinkedList`**: A classe que gerencia o conjunto de nós. Ela mantém um ponteiro para o primeiro nó da lista, comumente chamado de `head` ou, em português, `topo`.

## Operações Implementadas

A classe `LinkedList` oferece as seguintes operações:

* **`inserir(int data)`**: Insere um novo elemento no início da lista.
    * *Complexidade:* $O(1)$
* **`remover(int data)`**: Busca na lista o primeiro nó que contém o valor especificado e o remove. Retorna `true` se a remoção foi bem-sucedida e `false` caso contrário.
    * *Complexidade:* $O(n)$
* **`buscar(int data)`**: Verifica se um elemento existe na lista. Retorna `true` se o elemento for encontrado e `false` caso contrário.
    * *Complexidade:* $O(n)$
* **`exibir()`**: Percorre a lista e imprime todos os seus elementos, do primeiro ao último.
    * *Complexidade:* $O(n)$
* **`estaVazia()`**: Verifica se a lista não contém elementos. Retorna `true` se a lista estiver vazia.
    * *Complexidade:* $O(1)$
* **Destrutor `~LinkedList()`**: Garante que toda a memória alocada para os nós seja liberada quando um objeto `LinkedList` é destruído, evitando vazamentos de memória (memory leaks).

## Como Compilar e Executar

Como o projeto está separado em múltiplos arquivos, você precisa compilar todos os arquivos `.cpp` juntos. Use o seguinte comando:

```bash
# Comando para compilar o projeto
g++ main.cpp LinkedList.cpp -o linkedlist_demo

# Comando para executar o programa de demonstração
./linkedlist_demo
```
