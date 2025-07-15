
## Operações Implementadas

A classe `Pilha` oferece as seguintes operações, todas com complexidade de tempo constante:

* [cite_start]**`push(int data)`**: Adiciona um novo elemento no topo da pilha[cite: 1681].
    * [cite_start]*Complexidade:* $O(1)$ [cite: 1843]
* [cite_start]**`pop()`**: Remove o elemento do topo da pilha[cite: 1687].
    * [cite_start]*Complexidade:* $O(1)$ [cite: 1843]
* **`top()`**: Retorna o valor do elemento no topo da pilha sem removê-lo.
    * *Complexidade:* $O(1)$
* **`estaVazia()`**: Verifica se a pilha está vazia.
    * *Complexidade:* $O(1)$
* **Destrutor `~Pilha()`**: Libera toda a memória alocada para os nós, prevenindo vazamentos de memória.

## Como Compilar e Executar

Use o seguinte comando para compilar e executar o programa de demonstração:

```bash
# Comando para compilar o projeto
g++ main_pilha.cpp Pilha.cpp -o stack_demo

# Comando para executar o programa
./stack_demo
