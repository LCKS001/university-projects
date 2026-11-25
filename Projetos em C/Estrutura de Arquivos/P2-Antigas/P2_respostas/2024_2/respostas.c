#include <stdio>

typedef struct {
    int chave;
    long posicaoDados;
    long proximo;
} RegistroHash;

int hashMod11(int chave) {
    return chave % 11;
}

long maiorLista(FILE *arquivo, long hashSize, long recordSize) {
    long maiorIndice = -1;
    long maiorTamanho = 0;

    for (long i = 0; i < hashSize; ++i) {
        RegistroHash registro;
        long tamanho = 0;
        long atual = i;

        for (;;) {
            fseek(arquivo, atual * recordSize, SEEK_SET);
            if (fread(&registro, recordSize, 1, arquivo) != 1)
                break;
            if (registro.chave == 0)
                break;

            ++tamanho;
            if (registro.proximo == 0)
                break;
            atual = registro.proximo;
        }

        if (tamanho > maiorTamanho) {
            maiorTamanho = tamanho;
            maiorIndice = i;
        }
    }

    printf("Maior posicao: %ld, tamanho: %ld\n", maiorIndice, maiorTamanho);
    return maiorIndice;
}
