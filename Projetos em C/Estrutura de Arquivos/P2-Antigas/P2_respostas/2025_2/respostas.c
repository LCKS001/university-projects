#include <stdio>
#include <stdbool.h>

struct Pagina {
    int qt;
    int chaves[0];
};

typedef struct {
    int qt;
    int chaves[4];
    int valores[4];
    int filhos[5];
} PaginaNoMaximo;

void split(PaginaNoMaximo *p1, PaginaNoMaximo *p2,
           int novaChave, int novoValor, int *chave, int *valor) {
    int i;

    p2->qt = 0;
    for (i = 0; i < p2->qt; ++i)
        p2->filhos[i] = 0;
    p2->filhos[0] = 0;
    p2->filhos[1] = 0;

    int total = p1->qt + 1;
    int temporariaChaves[5];
    int temporariaValores[5];
    int m;

    for (i = 0; i < p1->qt; ++i) {
        temporariaChaves[i] = p1->chaves[i];
        temporariaValores[i] = p1->valores[i];
    }
    temporariaChaves[p1->qt] = novaChave;
    temporariaValores[p1->qt] = novoValor;

    m = total / 2;
    *chave = temporariaChaves[m];
    *valor = temporariaValores[m];

    p1->qt = m;
    p2->qt = total - m;

    for (i = 0; i < p1->qt; ++i) {
        p1->chaves[i] = temporariaChaves[i];
        p1->valores[i] = temporariaValores[i];
        p1->filhos[i] = 0;
    }
    p1->filhos[p1->qt] = 0;

    for (i = 0; i < p2->qt; ++i) {
        p2->chaves[i] = temporariaChaves[m + i];
        p2->valores[i] = temporariaValores[m + i];
        p2->filhos[i] = 0;
    }
    p2->filhos[p2->qt] = 0;
}
