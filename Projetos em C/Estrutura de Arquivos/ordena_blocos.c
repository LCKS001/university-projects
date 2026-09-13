#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int compara(const void *a, const void *b)
{
    return strncmp(
        ((Endereco*)a)->cep,
        ((Endereco*)b)->cep,
        8
    );
}

void intercala(char *arq1,
               char *arq2,
               char *saidaNome)
{
    FILE *a;
    FILE *b;
    FILE *saida;

    Endereco ea;
    Endereco eb;

    a = fopen(arq1,"rb");
    b = fopen(arq2,"rb");
    saida = fopen(saidaNome,"wb");

    if(!a || !b || !saida)
    {
        printf("Erro na abertura.\n");
        return;
    }

    int okA =
        fread(&ea,
              sizeof(Endereco),
              1,
              a);

    int okB =
        fread(&eb,
              sizeof(Endereco),
              1,
              b);

    while(okA && okB)
    {
        if(compara(&ea,&eb) < 0)
        {
            fwrite(&ea,
                   sizeof(Endereco),
                   1,
                   saida);

            okA =
                fread(&ea,
                      sizeof(Endereco),
                      1,
                      a);
        }
        else
        {
            fwrite(&eb,
                   sizeof(Endereco),
                   1,
                   saida);

            okB =
                fread(&eb,
                      sizeof(Endereco),
                      1,
                      b);
        }
    }

    while(okA)
    {
        fwrite(&ea,
               sizeof(Endereco),
               1,
               saida);

        okA =
            fread(&ea,
                  sizeof(Endereco),
                  1,
                  a);
    }

    while(okB)
    {
        fwrite(&eb,
               sizeof(Endereco),
               1,
               saida);

        okB =
            fread(&eb,
                  sizeof(Endereco),
                  1,
                  b);
    }

    fclose(a);
    fclose(b);
    fclose(saida);
}

int main()
{
    FILE *cep;

    cep = fopen("cep.dat","rb");

    if(!cep)
    {
        printf("Erro ao abrir cep.dat\n");
        return 1;
    }

    fseek(cep,
          0,
          SEEK_END);

    long total =
        ftell(cep) /
        sizeof(Endereco);

    rewind(cep);

    long bloco = total / 8;

    printf("Registros: %ld\n",
           total);

    for(int i=0;i<8;i++)
    {
        Endereco *vet;

        vet =
            (Endereco*)
            malloc(
                bloco *
                sizeof(Endereco));

        fread(vet,
              sizeof(Endereco),
              bloco,
              cep);

        qsort(vet,
              bloco,
              sizeof(Endereco),
              compara);

        char nome[30];

        sprintf(nome,
                "bloco%d.dat",
                i);

        FILE *saida =
            fopen(nome,
                  "wb");

        fwrite