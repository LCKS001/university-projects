O sistema é capaz de:
- Classificar lutadores em categorias de peso específicas.
- Listar todos os oponentes possíveis para um lutador dentro da mesma categoria.
- Sortear aleatoriamente um oponente válido para uma luta.

## Estrutura de Classes

O projeto utiliza uma hierarquia de classes para modelar os diferentes tipos de lutadores:

* **`Lutador.java`**: Uma **classe abstrata** que serve como modelo base para todos os lutadores. Contém atributos comuns como `nome`, `idade` e `peso`, e define os métodos que todas as subclasses devem compartilhar. Não é possível criar um objeto diretamente desta classe.
* **`PesoPena.java`**, **`PesoMedio.java`**, **`MeioPesado.java`**, **`PesoPesado.java`**: Classes concretas que herdam de `Lutador`. Cada uma representa uma categoria de peso específica.
* **`UFC.java`**: A classe principal (`main`) que gerencia a criação dos lutadores, armazena-os em um array e simula a busca e o sorteio de lutas.

## Conceitos Demonstrados

* **Classes Abstratas:** A classe `Lutador` serve como um contrato, garantindo que certos atributos e métodos existam, mas sem poder ser instanciada diretamente.
* **Herança:** As classes de categoria de peso herdam as características da classe `Lutador`.
* **Polimorfismo:** Um array do tipo `Lutador` é usado para armazenar objetos de suas diversas subclasses (`PesoPena`, `PesoMedio`, etc.), permitindo que sejam tratados de forma unificada.
* **Operador `instanceof`:** Utilizado para verificar o tipo real de um objeto em tempo de execução, permitindo a implementação de lógicas específicas para cada categoria.
* **Sobrescrita de Método (`@Override`):** O método `toString()` da classe `Object` é sobrescrito em `Lutador` para fornecer uma representação textual customizada do objeto.
* **Uso de `ArrayList` e `Math.random()`:** A classe `ArrayList` é usada para facilitar a seleção de um oponente aleatório no método de sorteio de lutas.

## Como Compilar e Executar

Para compilar todos os arquivos e executar o programa, utilize os seguintes comandos no terminal, dentro da pasta do projeto:

```bash
# Compila todos os arquivos .java
javac *.java

# Executa a classe principal
java UFC
