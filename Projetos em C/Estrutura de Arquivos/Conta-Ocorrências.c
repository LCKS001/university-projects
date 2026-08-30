#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *entrada;
    int c;
    int cont[256] = {0};
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "Erro na chamada do comando.\n");
        fprintf(stderr, "Uso: %s [ARQUIVO]\n", argv[0]);
        return 1;
    }

    entrada = fopen(argv[1], "rb");
    if (!entrada)
    {
        fprintf(stderr, "Arquivo %s não pode ser aberto para leitura\n", argv[1]);
        return 1;
    }

    c = fgetc(entrada);

    while (c != EOF)
    {
        cont[(unsigned char)c]++;
        c = fgetc(entrada);
    }

    fclose(entrada);

    printf("Ocorrencias das letras:\n\n");

    for (i = 'A'; i <= 'Z'; i++)
    {
        if (cont[i] > 0)
            printf("%c : %d\n", i, cont[i]);
    }

    for (i = 'a'; i <= 'z'; i++)
    {
        if (cont[i] > 0)
            printf("%c : %d\n", i, cont[i]);
    }

    return 0;
}
