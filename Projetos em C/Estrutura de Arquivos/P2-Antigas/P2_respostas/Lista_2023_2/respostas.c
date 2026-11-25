#include <stdio.h>

typedef struct {
    unsigned int codigoMunicipio;
    unsigned int posicao;
} IndiceClustering;

unsigned int getCodMunicipio(void *registro);
void *leRegistro(FILE *arquivo);

void criaIndiceClustering(FILE *dados, FILE *indice) {
    unsigned int codigoAnterior = 0;
    int primeiraLeitura = 1;
    long posicao = 0;

    rewind(dados);
    while (!feof(dados)) {
        void *registro = leRegistro(dados);
        if (!registro)
            break;

        unsigned int codigo = getCodMunicipio(registro);
        if (primeiraLeitura || codigo != codigoAnterior) {
            IndiceClustering item = {
                codigo,
                (unsigned int)posicao
            };
            fwrite(&item, sizeof(item), 1, indice);
            codigoAnterior = codigo;
            primeiraLeitura = 0;
        }
        posicao = ftell(dados);
    }
}
