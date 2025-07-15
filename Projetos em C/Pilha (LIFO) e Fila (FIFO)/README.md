# Implementação de Pilha (Stack) em C++

Este projeto contém a implementação de uma **Pilha** (Stack) utilizando uma lista encadeada como estrutura base. [cite_start]Uma pilha segue a política de acesso **LIFO (Last-In, First-Out)**, o que significa que o último elemento adicionado é o primeiro a ser removido.

É uma estrutura de dados essencial, usada em gerenciamento de chamadas de funções (call stack), algoritmos de backtracking, funcionalidades de "desfazer" (undo), entre outros.

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
