## Conceitos Demonstrados

Este projeto é uma vitrine para as seguintes competências em Java:

* **Programação Orientada a Objetos:**
    * **Herança:** Uma classe base `Aluno` com subclasses `AlunoRegular` e `AlunoEspecial`.
    * **Polimorfismo:** Manipulação de diferentes tipos de alunos através da referência da superclasse `Aluno`.
    * **Sobrescrita de Métodos (`@Override`):**
        * `toString()`: Para uma representação textual customizada dos objetos.
        * `equals()` e `hashCode()`: Essencial para o funcionamento correto de coleções como `List.contains()`, `HashSet` e `HashMap`. Sobrescrever `equals()` sem `hashCode()` quebra o contrato do `Object` e pode levar a comportamentos inesperados em coleções baseadas em hash.
* **Java Collections Framework:**
    * **`Set`**: Usado para receber os dados brutos, garantindo que não haja entradas duplicadas.
    * **`Map`**: Usado para indexar os alunos por seu `id` único, permitindo buscas rápidas ($O(1)$ em média).
    * **`List`**: Usada para criar uma versão ordenada dos alunos para exibição.
    * **`Iterator`**: Utilizado para percorrer a coleção `Set` de forma segura, como exigido no exercício.
* **Interface `Comparable`:**
    * A classe `Aluno` implementa `Comparable<Aluno>`, permitindo que listas de alunos sejam ordenadas naturalmente por nome usando `Collections.sort()`.
* **Processamento de Strings:**
    * Uso do método `String.split("#")` para extrair dados de uma string formatada.
* **Tratamento de Exceções:**
    * Lançamento de uma `RuntimeException` para lidar com dados de entrada inválidos (tipos de aluno desconhecidos).

## Como Compilar e Executar

Para compilar todos os arquivos e executar o programa, utilize os seguintes comandos no terminal:

```bash
# Compila todos os arquivos .java
javac *.java

# Executa a classe principal
java SistemaAlunos
