## Operações Implementadas

A implementação se baseia em recursividade para percorrer e manipular a árvore.

* **`inserir(int data)`**: Adiciona um novo elemento à árvore na posição correta, de modo a manter a propriedade da ABB.
    * *Complexidade Média:* $O(\log n)$
* **`percursoEmOrdem()`**: Percorre a árvore utilizando o método "Em-Ordem" (In-Order Traversal), que visita os nós em ordem crescente de valor. Isso serve como uma forma de verificar se a árvore foi construída corretamente.
    * *Complexidade:* $O(n)$
* **`mostrarFolhas()`**: Resolve o exercício proposto no arquivo `P2_Exemplo.pdf` (Questão 3). A função percorre a árvore e imprime o valor de todos os **nós folha**, que são os nós que não possuem filhos nem à esquerda, nem à direita.
    * *Complexidade:* $O(n)$
* **Destrutor `~BinarySearchTree()`**: Percorre a árvore e libera toda a memória alocada para os nós, evitando vazamentos de memória.

## Como Compilar e Executar

Como o projeto está separado em múltiplos arquivos, você precisa compilar todos os arquivos `.cpp` juntos. Use o seguinte comando:

```bash
# Comando para compilar o projeto
g++ main.cpp BinarySearchTree.cpp -o bst_demo

# Comando para executar o programa de demonstração
./bst_demo
