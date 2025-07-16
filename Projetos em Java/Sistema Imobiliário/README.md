## Estrutura de Classes

O sistema é composto por uma hierarquia de classes que representa diferentes tipos de imóveis:

**`Imovel.java`**: A classe base que contém os atributos e métodos comuns a todos os imóveis, como `endereco` e `preco`. 
* **`Novo.java`**: Uma subclasse de `Imovel`. Representa um imóvel novo e aplica um adicional de 10% sobre o preço base. 
* **`Velho.java`**: Uma subclasse de `Imovel`.Representa um imóvel usado e aplica um desconto de 10% sobre o preço base. 
* **`Corretora.java`**: A classe principal (`main`) que simula o funcionamento do sistema. Ela gerencia uma lista de imóveis e calcula o valor total do seu portfólio. [cite: 4110]

## Conceitos Demonstrados

**Herança:** As classes `Novo` e `Velho` herdam atributos e comportamentos da classe `Imovel`.
* **Polimorfismo:** A classe `Corretora` manipula uma lista de `Imovel`, mas em tempo de execução, os objetos podem ser instâncias de `Novo` or `Velho`. A chamada ao método `getPreco()` executa a versão correta (da superclasse ou da subclasse) dependendo do tipo real do objeto.
**Sobrescrita de Método (`@Override`):** As subclasses `Novo` e `Velho` sobrescrevem o método `getPreco()` para implementar suas lógicas de negócio específicas (adicional e desconto). 

## Como Compilar e Executar

Para compilar todos os arquivos e executar o programa, utilize os seguintes comandos no terminal, dentro da pasta do projeto:

```bash
# Compila todos os arquivos .java
javac *.java

# Executa a classe principal
java Corretora
