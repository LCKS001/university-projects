#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char chave[8];
    unsigned long posicaoDados;
    unsigned long proximo;
} RegistroHash;

long contaChavesAreaColisao(FILE *index, unsigned long hashSize,
                           unsigned long recordSize) {
    long quantidade = 0;
    fseek(index, 0, SEEK_END);
    long fim = ftell(index);

    if (fim < 0)
        return 0;

    unsigned long areaColisao = hashSize * recordSize;
    if (areaColisao >= (unsigned long)fim)
        return 0;

    fseek(index, (long)areaColisao, SEEK_SET);
    RegistroHash registro;
    while (ftell(index) + (long)recordSize <= fim &&
           fread(&registro, recordSize, 1, index) == 1) {
        if (registro.chave[0] != 0)
            ++quantidade;
    }
    return quantidade;
}

void diferencaOrdenada(const char *a1Nome, const char *a2Nome,
                       const char *a3Nome) {
    FILE *a1 = fopen(a1Nome, "r");
    FILE *a2 = fopen(a2Nome, "r");
    FILE *a3 = fopen(a3Nome, "w");
    if (!a1 || !a2 || !a3) {
        if (a1)
            fclose(a1);
        if (a2)
            fclose(a2);
        if (a3)
            fclose(a3);
        return;
    }

    char s1[81], s2[81];
    char *r1 = fgets(s1, sizeof(s1), a1);
    char *r2 = fgets(s2, sizeof(s2), a2);

    while (r1 && r2) {
        int cmp = strcmp(s1, s2);
        if (cmp < 0) {
            fputs(s1, a3);
            r1 = fgets(s1, sizeof(s1), a1);
        } else if (cmp > 0) {
            r2 = fgets(s2, sizeof(s2), a2);
        } else {
            r1 = fgets(s1, sizeof(s1), a1);
            r2 = fgets(s2, sizeof(s2), a2);
        }
    }

    while (r1) {
        fputs(s1, a3);
        r1 = fgets(s1, sizeof(s1), a1);
    }

    fclose(a1);
    fclose(a2);
    fclose(a3);
}
