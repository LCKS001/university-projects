## Estrutura de Classes

O sistema é composto por uma hierarquia de classes que representa diferentes tipos de imóveis:

* [cite_start]**`Imovel.java`**: A classe base que contém os atributos e métodos comuns a todos os imóveis, como `endereco` e `preco`. 
* **`Novo.java`**: Uma subclasse de `Imovel`. [cite_start]Representa um imóvel novo e aplica um adicional de 10% sobre o preço base. [cite: 4105, 6715]
* **`Velho.java`**: Uma subclasse de `Imovel`. [cite_start]Representa um imóvel usado e aplica um desconto de 10% sobre o preço base. [cite: 4105, 6717]
* **`Corretora.java`**: A classe principal (`main`) que simula o funcionamento do sistema. [cite_start]Ela gerencia uma lista de imóveis e calcula o valor total do seu portfólio. [cite: 4110]

## Conceitos Demonstrados

* [cite_start]**Herança:** As classes `Novo` e `Velho` herdam atributos e comportamentos da classe `Imovel`. [cite: 4106, 4108]
* **Polimorfismo:** A classe `Corretora` manipula uma lista de `Imovel`, mas em tempo de execução, os objetos podem ser instâncias de `Novo` or `Velho`. A chamada ao método `getPreco()` executa a versão correta (da superclasse ou da subclasse) dependendo do tipo real do objeto.
* [cite_start]**Sobrescrita de Método (`@Override`):** As subclasses `Novo` e `Velho` sobrescrevem o método `getPreco()` para implementar suas lógicas de negócio específicas (adicional e desconto). [cite: 4107, 4109]

## Como Compilar e Executar

Para compilar todos os arquivos e executar o programa, utilize os seguintes comandos no terminal, dentro da pasta do projeto:

```bash
# Compila todos os arquivos .java
javac *.java

# Executa a classe principal
java Corretora
