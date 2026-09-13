#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Indice
{
    char cep[8];
    long pos;
} Indice;

typedef struct _Endereco Endereco;
struct _Endereco
{
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char uf[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
};

typedef struct _Indice Indice;
struct _Indice
{
    char cep[8];
    long pos;
};

int main()
{
    FILE *cep;
    FILE *indice;

    Endereco e;
    Indice idx;

    long pos = 0;

    cep = fopen("cep.dat","rb");

    if(!cep)
    {
        printf("Erro ao abrir cep.dat\n");
        return 1;
    }

    indice = fopen("indice.dat","wb");

    if(!indice)
    {
        printf("Erro ao criar indice.dat\n");
        fclose(cep);
        return 1;
    }

    while(fread(&e,sizeof(Endereco),1,cep))
    {
        memcpy(idx.cep,e.cep,8);

        idx.pos = pos;

        fwrite(&idx,sizeof(Indice),1,indice);

        pos++;
    }

    fclose(cep);
    fclose(indice);

    printf("Indice criado.\n");

    return 0;
}