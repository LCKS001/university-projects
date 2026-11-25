#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int chave;
    long posicaoDados;
    long proximo;
} RegistroHash;

void contaColisoesNoArquivo(FILE *index, long hashSize, long indexRecordSize) {
    long posicoesComColisao = 0;

    for (long i = 0; i < hashSize; ++i) {
        RegistroHash r;
        fseek(index, i * indexRecordSize, SEEK_SET);
        if (fread(&r, indexRecordSize, 1, index) == 1) {
            if (r.proximo != 0)
                ++posicoesComColisao;
        }
    }
    printf("Posicoes primarias com colisao: %ld\n", posicoesComColisao);
}

void compactaHash(FILE *index, FILE *dados, long hashSize,
                  long indexRecordSize, int (*hashFunc)(int)) {
    RegistroHash registro;
    long proximaLivre = hashSize;
    fseek(index, 0, SEEK_END);

    for (;;) {
        long pos = ftell(index);
        if (fread(&registro, indexRecordSize, 1, index) != 1)
            break;
        if (registro.chave == 0)
            continue;

        int bucket = hashFunc(registro.chave);
        RegistroHash cabeca;
        fseek(index, bucket * indexRecordSize, SEEK_SET);
        fread(&cabeca, indexRecordSize, 1, index);

        if (cabeca.chave == registro.chave)
            continue;

        fseek(index, bucket * indexRecordSize, SEEK_SET);
        RegistroHash atual;
        fread(&atual, indexRecordSize, 1, index);

        while (atual.proximo != 0) {
            long seguinte = atual.proximo;
            fseek(index, seguinte * indexRecordSize, SEEK_SET);
            fread(&atual, indexRecordSize, 1, index);
        }

        registro.proximo = 0;
        fseek(index, proximaLivre * indexRecordSize, SEEK_SET);
        fwrite(&registro, indexRecordSize, 1, index);

        atual.proximo = proximaLivre;
        fseek(index, (atual.proximo == 0 ? bucket : pos) * indexRecordSize, SEEK_SET);
        fwrite(&atual, indexRecordSize, 1, index);
        ++proximaLivre;
    }
}
