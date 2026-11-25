#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int codigo;
    char descricao[40];
    float preco;
} Produto;

FILE *arquivo_dados;
void *arvore_bplus;

int bplus_insert(void *arvore, int chave, long posicao);
int bplus_search(void *arvore, int chave, long *posicao);
void bplus_traverse(void *arvore, void (*callback)(int chave, long posicao));

int insere(Produto p) {
    long posicao;

    if (bplus_search(arvore_bplus, p.codigo, &posicao))
        return 0;

    if (fseek(arquivo_dados, 0, SEEK_END) != 0)
        return 0;

    posicao = ftell(arquivo_dados);
    if (posicao < 0)
        return 0;

    if (fwrite(&p, sizeof(Produto), 1, arquivo_dados) != 1)
        return 0;

    if (!bplus_insert(arvore_bplus, p.codigo, posicao))
        return 0;

    return 1;
}

static void imprimir_produto(int codigo, long posicao) {
    Produto p;

    if (fseek(arquivo_dados, posicao, SEEK_SET) != 0)
        return;
    if (fread(&p, sizeof(Produto), 1, arquivo_dados) != 1)
        return;

    printf("Codigo: %d | Descricao: %s | Preco: %.2f\n",
           p.codigo, p.descricao, p.preco);
}

void busca(int codigo) {
    long posicao;

    if (!bplus_search(arvore_bplus, codigo, &posicao)) {
        printf("Produto nao encontrado.\n");
        return;
    }
    imprimir_produto(codigo, posicao);
}

void lista(void) {
    bplus_traverse(arvore_bplus, imprimir_produto);
}
