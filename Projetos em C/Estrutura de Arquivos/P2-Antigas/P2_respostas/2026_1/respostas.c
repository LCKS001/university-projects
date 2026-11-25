#include <stdio.h>
#include <stdbool.h>

typedef struct {
    long chave;
    char dados[1000];
} Registro;

void *openTree(const char *nomeArquivo);
bool findKey(void *tree, long key, long *offset);
void insertKey(void *tree, long key, long offset);
void closeTree(void *tree);

void indexaArquivo(const char *nomeDados, const char *nomeIndice) {
    FILE *dados = fopen(nomeDados, "rb");
    if (!dados)
        return;

    void *indice = openTree(nomeIndice);
    if (!indice) {
        fclose(dados);
        return;
    }

    Registro registro;
    long offset = 0;
    while (fread(&registro, sizeof(Registro), 1, dados) == 1) {
        insertKey(indice, registro.chave, offset);
        offset += (long)sizeof(Registro);
    }

    closeTree(indice);
    fclose(dados);
}

void imprimeDados(const char *nomeDados, const char *nomeIndice, long chave) {
    void *indice = openTree(nomeIndice);
    FILE *dados = fopen(nomeDados, "rb");
    if (!indice || !dados) {
        if (indice)
            closeTree(indice);
        if (dados)
            fclose(dados);
        return;
    }

    long offset;
    if (findKey(indice, chave, &offset)) {
        if (fseek(dados, offset, SEEK_SET) == 0) {
            Registro registro;
            if (fread(&registro, sizeof(Registro), 1, dados) == 1)
                fwrite(registro.dados, sizeof(registro.dados), 1, stdout);
        }
    } else {
        printf("Chave nao encontrada: %ld\n", chave);
    }

    closeTree(indice);
    fclose(dados);
}

void diferencaArquivos(const char *arquivo1, const char *arquivo2,
                       const char *indiceArquivo1, const char *arquivoSaida) {
    void *indice = openTree(indiceArquivo1);
    FILE *f1 = fopen(arquivo1, "rb");
    FILE *f2 = fopen(arquivo2, "rb");
    FILE *saida = fopen(arquivoSaida, "wb");
    if (!indice || !f1 || !f2 || !saida) {
        if (indice)
            closeTree(indice);
        if (f1)
            fclose(f1);
        if (f2)
            fclose(f2);
        if (saida)
            fclose(saida);
        return;
    }

    Registro registro;
    while (fread(&registro, sizeof(Registro), 1, f2) == 1) {
        long offset;
        if (!findKey(indice, registro.chave, &offset))
            fwrite(&registro, sizeof(Registro), 1, saida);
    }

    closeTree(indice);
    fclose(f1);
    fclose(f2);
    fclose(saida);
}
