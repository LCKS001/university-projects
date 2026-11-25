# Guia definitivo para P2 - Estrutura de Arquivos

Este guia reúne os padrões que mais aparecem nas provas antigas de P2. O objetivo é que você saiba reconhecer o assunto pela primeira frase do enunciado e execute a técnica correspondente sem improvisar.

## 1. Mentalidade da prova

Cada questão geralmente pertence a uma destas categorias:

1. Conceito teórico.
2. Cálculo de capacidade de uma página ou bloco.
3. Simulação manual de tabela hash.
4. Inserção, remoção ou divisão em árvore B/B+.
5. Implementação em C de busca, inserção, intercalacao ou índice.
6. Construção de árvore de Huffman.

Antes de começar a resolver:

- Circule o que é grau, ordem, nível, altura e número máximo de chaves.
- Anote os tamanhos em bytes.
- Distinga índice de hash de índice de árvore.
- Escreva o que representa a cabeça da lista: chave, offset/posição ou próximo.
- Sempre faça pelo menos uma verificação final da quantidade de chaves e dos ponteiros.

---

# 2. Estruturas essenciais

## 2.1 Registro de dados

Quando o arquivo armazenar um registro completo:

```c
typedef struct {
    long chave;
    char dados[1000];
} Registro;
```

Padrão de leitura sequencial:

```c
while (fread(&registro, sizeof(Registro), 1, dados) == 1) {
    long offset = ftell(dados) - sizeof(Registro);
}
```

O índice guarda normalmente apenas a chave e o offset:

```c
insertKey(indice, registro.chave, offset);
```

## 2.2 Registro de índice hash

```c
typedef struct {
    char chave[8];
    unsigned long posicaoDados;
    unsigned long proximo;
} RegistroHash;
```

Campos:

- `chave`: identificador armazenado no registro.
- `posicaoDados`: posição ou offset no arquivo principal.
- `proximo`: índice/offset do próximo registro no encadeamento.

O ponteiro nulo é normalmente `0`.

## 2.3 Página de árvore B

```c
typedef struct {
    int qt;
    int chaves[N];
    int valores[N];
    int filhos[N + 1];
} Pagina;
```

Cada chave separadora no nó interno possui relações com os filhos:

```text
filhos[0] | chaves[0] | filhos[1] | chaves[1] | filhos[2]
```

Em folhas, os ponteiros `filhos` são nulos, representados por `0`.

## 2.4 Estrutura clássica de hash externa

```text
Posição primária:
[chave | posição no arquivo de dados | próximo]

Área de colisão:
[chave | posição no arquivo de dados | próximo]
```

Exemplo de cadeia:

```text
posição primária 5 -> registro 27 -> registro 38 -> registro 49 -> 0
```

---

# 3. Árvore B

## 3.1 Conceitos

Uma árvore B possui:

- Nós internos com chaves separadoras.
- Nós internos com ponteiros para filhos.
- Dados ou referências distribuídos na estrutura conforme a implementação.
- Todos os nós folha no mesmo nível.
- Nós não raiz com ocupação mínima.

O grau costuma ser informado de duas formas:

### Forma 1: grau = número máximo de ponteiros

Exemplo: grau 5 possui:

- máximo 5 filhos;
- máximo 4 chaves por nó;
- mínimo 2 filhos/chaves conforme a variante.

### Forma 2: grau = número máximo de chaves

Exemplo: grau 4 possui:

- máximo 3 chaves;
- máximo 4 filhos;
- mínimo 2 chaves no nó não raiz.

Sempre confira a definição utilizada no enunciado.

## 3.2 Inserção

Passos:

1. Localizar a folha correta.
2. Inserir em ordem.
3. Se houver excesso de chaves, dividir.
4. Promover uma chave ao pai.
5. Repetir a divisão no pai quando necessário.
6. Se a raiz dividir, criar nova raiz.

Pseudocódigo:

```c
if (folhaCheia) {
    separarFolha(p1, p2);
    promoverChaveAoPai();
} else {
    inserirEmOrdemNaFolha();
}
```

## 3.3 Remoção

Há três casos principais:

### Caso 1: chave está em folha

- Remova a chave diretamente.
- Se a folha ficar abaixo do mínimo, redistribua com o irmão.
- Se não houver chave suficiente para redistribuir, faça fusão.

### Caso 2: chave está em nó interno

- Substitua pela antecessora ou sucessora.
- Remova da folha de origem essa chave substituta.
- Rebalanceie se necessário.

### Caso 3: irmão insuficiente

- Faça fusão com irmão e chave separadora.

## 3.4 Split de página cheia

Considere uma página de no máximo `N` chaves já cheia e uma nova chave maior que todas.

```c
int temporaria[N + 1];

// Copiar as N chaves antigas.
// Inserir novaChave no final.

int m = (N + 1) / 2;

*chavePromovida = temporaria[m];

p1.qt = m;
p2.qt = (N + 1) - m;

copiar temporaria[0..m-1] para p1;
copiar temporaria[m..N] para p2;
```

Garanta que:

- os filhos de ambas as folhas sejam `0`;
- valores correspondentes acompanhem as chaves;
- o pai receba chave e, se necessário, novo filho.

O split garante aproximadamente metade das chaves em cada novo nó e mantém o mínimo de ocupação dos nós não raiz.

## 3.5 Máximo de chaves por altura

Se a raiz contém no máximo `N` chaves e cada nó no nível seguinte contém no máximo `N` chaves:

```text
nível 1: N
nível 2: N * (N + 1)
nível 3: N * (N + 1)^2
```

Mais genericamente:

```text
máximo = N * (N + 1)^(altura - 1)
```

---

# 4. Árvore B+

## 4.1 Diferenças para a árvore B

| Característica | Árvore B | Árvore B+ |
|---|---|---|
| Chaves nos nós internos | Sim | São separadores |
| Dados reais | Internos e folhas | Apenas folhas |
| Consulta sequencial | Mais difícil | Folhas encadeadas |
| Percurso em intervalo | Pode subir/descer bastante | Percorre folhas em sequência |

## 4.2 Consultas favoritas

Árvore B/B+:

- igualdade;
- intervalo;
- menor/maior;
- `ORDER BY`;
- prefixos de ordenação.

Hash:

- igualdade exata;
- busca pela chave completa;
- não suporta intervalo ou sequência de forma eficiente;
- não mantém a ordem natural das chaves.

---

# 5. Tabela hash

## 5.1 Função modular

```c
int h(int chave) {
    return chave % 11;
}
```

### Como contar colisões

Uma colisão ocorre toda vez que o índice já está ocupado.

Exemplo:

```text
10 % 11 = 10
21 % 11 = 10
32 % 11 = 10
```

As inserções `21` e `32` são duas colisões adicionais.

Não confunda:

- número de chaves inseridas;
- número de colidências;
- tamanho das listas.

## 5.2 Encadeamento externo

Insere-se o novo elemento no início da lista:

```c
novo->proximo = tabela[h].proximo;
tabela[h].proximo = indiceNovo;
```

Modelo com 11 posições primárias e área de colisão:

```text
tabela[i]:
[chave | valor/offset | próximo]

área de colisão:
[chave | valor/offset | próximo]
```

### Simulação manual

Para cada chave:

1. Calcule `h(k)`.
2. Se a posição estiver vazia, guarde a chave nela.
3. Se estiver ocupada:
   - escreva o novo registro na próxima posição livre da área de colisão;
   - faça `novo.proximo = tabela[h].proximo`;
   - faça `tabela[h].proximo = posiçãoLivre`.

Exemplo:

```text
posição 7 vazia:
7: 18, próximo = 0

29 colide em 7:
12: 29, próximo = 0
7: 18, próximo = 12

40 colide em 7:
13: 40, próximo = 12
7: 18, próximo = 13
```

## 5.3 Hash com área de colisão já existente

Busca:

```c
offset = h(chave) * sizeof(RegistroHash);
fi.seek(index, offset, SEEK_SET);

while (1) {
    registro = readRecord(fi);

    if (strcmp(registro.chave, chave) == 0)
        achou();

    if (registro.proximo == 0)
        naoAchou();

    fi.seek(index, registro.proximo * sizeof(RegistroHash), SEEK_SET);
}
```

## 5.4 Contagem da maior lista

```c
for (cada posição primária i) {
    tamanho = 0;
    atual = i;

    while (atual != 0) {
        ler registro atual;
        tamanho++;
        atual = registro.proximo;
    }

    if (tamanho > maior)
        maior = tamanho;
}
```

---

# 6. Compactação de hash

O problema típico pede mover registros da área de colisão para posições vazias dentro da tabela, reconstruindo os encadeamentos.

Algoritmo:

```text
para cada chave na área de colisão:
    posHash = h(chave)
    procura o primeiro espaço vazio na própria tabela
    move registro para esse espaço
    procura a cabeça da lista em posHash
    reorganiza ponteiros
```

Código esquemático:

```c
for (posição na área de colisão) {
    r = lerRegistro(posição);

    pv = encontrarPrimeiraPosicaoVazia();
    r.proximo = 0;
    gravarRegistro(pv, r);

    p = h(r.chave);

    atual = &tabela[p];
    while (atual->proximo != 0)
        atual = buscar(atual->proximo);

    atual->proximo = pv;
}
```

Apague todos os ponteiros antigos antes de reconstruir encadeamentos.

---

# 7. Intercalação de arquivos

## 7.1 Diferença: registros de `a1` que não estão em `a2`

```c
while (!feof(a1) && !feof(a2)) {
    if (strcmp(s1, s2) == 0) {
        ler s1;
        ler s2;
    } else if (strcmp(s1, s2) < 0) {
        escrever s1;
        ler s1;
    } else {
        ler s2;
    }
}

copiar o restante de a1;
```

## 7.2 Interseção

Escreva apenas quando `strcmp(s1, s2) == 0`.

## 7.3 União

Escreva o menor elemento e avance o arquivo correspondente. Se forem iguais, escreva uma vez e avance ambos.

Complexidade:

```text
O(n1 + n2)
```

---

# 8. Índices clustering

Um índice clustering guarda a primeira posição de cada valor do campo de agrupamento.

```c
typedef struct {
    unsigned int codigoMunicipio;
    unsigned int posicao;
} IndiceClustering;
```

Algoritmo:

```c
codigoAnterior = 0;
primeiraLeitura = true;
rewind(dados);

while ((registro = leRegistro(dados)) != NULL) {
    codigo = getCodMunicipio(registro);

    if (primeiraLeitura || codigo != codigoAnterior) {
        posicao = ftell(dados) - tamanhoRegistro;
        salvarIndice(codigo, posicao);
        codigoAnterior = codigo;
        primeiraLeitura = false;
    }
}
```

Tamanho estimado:

```text
5700 municípios * (4 bytes + 4 bytes) = 45600 bytes
```

---

# 9. Cálculo de tamanho de página

## 9.1 Fórmula para páginas com ponteiros

Se `N` é o número máximo de chaves:

```text
Tamanho = N * TamanhoValor
        + (N + 1) * TamanhoPonteiroBloco
        + N * TamanhoPonteiroRegistro
        + metadados
```

Exemplo:

```text
V = 9 bytes
Pr = 7 bytes
Pb = 6 bytes

n * 6 + (n - 1) * 9 + (n - 1) * 7 <= 512
6n + 16n - 16 <= 512
22n <= 528
n <= 24
```

## 9.2 Número máximo e mínimo

Se `n` é o número máximo de filhos:

- máximo de chaves em um nó: `n - 1`;
- mínimo em nó não raiz: `ceil((n - 1) / 2)`.

Exemplo com `n = 24`:

- máximo: 23 chaves;
- mínimo: 12 chaves.

## 9.3 Página com dados

```text
qt: 4 bytes
N chaves: 4N
N valores: 4N
(N + 1) filhos: 4(N + 1)
```

Logo:

```text
Tamanho = 4 + 4N + 4N + 4N + 4
        = 16N + 8 bytes
```

Para um bloco de 1024 bytes:

```text
16N + 8 <= 1024
N <= 63
```

---

# 10. Altura e quantidade de chaves

## 10.1 Altura em níveis

As provas usam duas convenções:

- raiz no nível 1;
- raiz no nível 0.

Leia o enunciado e não misture as convenções.

Exemplo: raiz no nível 1 e folhas no nível 3 possui:

```text
nível 1: raiz
nível 2: nós intermediários
nível 3: folhas
```

## 10.2 Máximo em árvore cheia

Se a raiz contém `N` chaves e cada nó não raiz contém `N` chaves:

- folhas no nível 3:

```text
N * (N + 1) * (N + 1)
= N * (N + 1)^2
```

Exemplo com `N = 63`:

```text
63 * 64 * 64 = 258048
```

Há pequenas variações porque algumas provas tratam filhos da raiz ou da raiz vazia. Use sempre a estrutura indicada no enunciado.

## 10.3 Split máximo em uma única inserção

Uma inserção pode causar split em todos os níveis até a raiz.

Se folhas estão no nível 7 e raiz no nível 0:

- folha;
- níveis 6, 5, 4, 3, 2 e 1;
- uma nova raiz.

Máximo teórico: 8 novas páginas.

---

# 11. Huffman

## 11.1 Construção

1. Coloque todos os símbolos em uma fila de prioridades ou heap.
2. Remova os dois menores.
3. Crie nó interno com soma das frequências.
4. Coloque o nó de volta.
5. Repita até restar um nó.
6. Percorra com `0` à esquerda e `1` à direita.

Pseudocódigo:

```text
heap = todos os símbolos

while (tamanho(heap) > 1) {
    a = removerMenor(heap)
    b = removerMenor(heap)
    novo = nó(a, b, a.freq + b.freq)
    inserir(heap, novo)
}
```

## 11.2 Por que usar heap

O heap permite encontrar rapidamente as duas menores frequências. Sem heap, busca-se em `O(n)` a cada passo. Com heap binário:

```text
remover menor: O(log n)
inserir: O(log n)
construção completa: O(n log n)
```

## 11.3 Compactado novamente

Um arquivo já compactado tem baixa redundância. Huffman baseado em frequência raramente produz ganho significativo em outra compactação:

- poucas frequências desiguais;
- mais provável que os códigos tenham tamanho semelhante;
- a tabela da árvore pode aumentar o tamanho.

---

# 12. Implementação em C

## 12.1 Índice em árvore B

### Construir índice

```c
void indexaArquivo(const char *nomeDados, const char *nomeIndice) {
    FILE *dados = fopen(nomeDados, "rb");
    void *indice = openTree(nomeIndice);
    Registro r;
    long offset = 0;

    while (fread(&r, sizeof(Registro), 1, dados) == 1) {
        insertKey(indice, r.chave, offset);
        offset += sizeof(Registro);
    }

    closeTree(indice);
    fclose(dados);
}
```

### Buscar registro pelo índice

```c
bool encontrou;
long offset;

encontrou = findKey(indice, chave, &offset);

if (!encontrou) {
    printf("Chave nao encontrada\n");
} else {
    fseek(dados, offset, SEEK_SET);
    fread(&registro, sizeof(Registro), 1, dados);
}
```

### Inserir produto no arquivo e na B+

```c
int insere(Produto p) {
    long pos;

    if (bplus_search(arvore, p.codigo, &pos))
        return 0;

    fseek(arquivoDados, 0, SEEK_END);
    pos = ftell(arquivoDados);

    fwrite(&p, sizeof(Produto), 1, arquivoDados);
    bplus_insert(arvore, p.codigo, pos);

    return 1;
}
```

### Percorrer a B+ em ordem

```c
void imprimir(int chave, long posicao) {
    Produto p;
    fseek(arquivoDados, posicao, SEEK_SET);
    fread(&p, sizeof(Produto), 1, arquivoDados);
    printf("%d %s %.2f\n", p.codigo, p.descricao, p.preco);
}

void lista(void) {
    bplus_traverse(arvore, imprimir);
}
```

## 12.2 Diferença com árvore B

Para cada registro de `arquivo2`:

```c
if (!findKey(indiceArquivo1, registro.chave, &offset)) {
    fwrite(&registro, sizeof(Registro), 1, arquivoSaida);
}
```

Custo esperado:

```text
O(n2 * log_b(n1) + n1 * log_b(n1))
```

Se o índice já existir:

```text
O(n2 * log_b(n1) + k)
```

---

# 13. Erros que derrubam pontos

## Árvore B

- confundir grau com número máximo de chaves;
- esquecer de promover chave;
- esquecer de dividir a raiz;
- deixar filhos não nulos em folha;
- redistribuir incorretamente;
- perder o offset ou valor associado.

## Hash

- contar a chave inicial como colisão;
- esquecer de encadear o novo elemento;
- não inserir na próxima posição livre;
- não zerar ponteiros nulos;
- usar número fora do intervalo da tabela;
- confundir índice primário com posição da área de colisão.

## Cálculos

- esquecer o tamanho dos metadados;
- esquecer `(N + 1)` ponteiros;
- confundir mínimo de nós não raiz;
- usar altura começando em 0 quando a prova considera nível 1.

## Huffman

- atribuir símbolos com frequência diferente a códigos válidos mas não ótimos;
- não somar as menores frequências em cada etapa;
- esquecer que o caminho completo determina o código;
- confundir heap com fila ordenada estática.

---

# 14. Checklist rápido antes de entregar

## Questões teóricas

- definições em uma frase;
- justificativa prática;
- exemplo curto;
- mencionar complexidade apenas quando pedido.

## Hash manual

- escrever h(k) de todas as chaves;
- identificar colisões;
- desenhar posição primária e área de colisão;
- mostrar ponteiros;
- indicar maior lista.

## Árvore manual

- verificar a raiz;
- verificar quantidade máxima;
- verificar ocupação mínima;
- verificar ponteiros;
- verificar ordem crescente;
- verificar todos os filhos no mesmo nível.

## Cálculo de página

- escrever a fórmula completa;
- identificar `N`, `V`, `Pr`, `Pb`;
- substituir os bytes;
- resolver a desigualdade;
- arredondar corretamente.

## Implementação em C

- abrir os arquivos em modo correto;
- testar retorno de `open/fopen`;
- calcular offset antes de ler;
- usar `seek` antes da leitura;
- verificar retorno de `read/fread`;
- fechar arquivos;
- fechar índices antes de fechar dados.

---

# 15. Padrão de resolução por tipo

## "Construa uma tabela hash"

1. Calcule cada módulo.
2. Monte cabeçalho da tabela.
3. Resolva uma chave por vez.
4. Use área de colisão somente quando necessário.
5. Coloque novo registro no início ou no fim conforme o enunciado.
6. Conte colisoes e tamanho máximo.

## "Faça a inserção em árvore B"

1. Procure a folha.
2. Insira em ordem.
3. Divida se ultrapassar capacidade.
4. Promova.
5. Desenhe a estrutura.

## "Faça a remoção"

1. Identifique se está em folha ou interno.
2. Redistribua ou faça fusão.
3. Propague fusões.
4. Redesenhe o resultado.

## "Construa o índice"

1. Abra dados e índice.
2. Leia registros em sequência.
3. Guarde chave.
4. Calcule offset.
5. Insira no índice.
6. Feche tudo.

## "Construa Huffman"

1. Liste frequências.
2. Repita remover dois menores.
3. Insira soma.
4. Gere códigos do caminho.

## "Calcule a ocupação"

1. Escreva fórmula.
2. Substitua valores.
3. Resolva `N`.
4. Calcule máximo ou mínimo.
