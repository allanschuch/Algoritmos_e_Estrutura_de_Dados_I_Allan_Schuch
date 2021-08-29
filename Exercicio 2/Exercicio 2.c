#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pointer, *string;

char *Ler_nome()
{
    char ch, *init, *p;
    int i = 0;

    init = (char *)malloc(sizeof(char) * 2);
    p = init;
    *init = getchar();

    while ((ch = getchar()) != '\n')
    {
        init = realloc(init, sizeof(char) * (i + 3));
        p = init + (i + 1);                                                                                     
        *p = ch;
        i++;                                                             
    }

    p = init + (i + 1);
    *p = '\0';

    return init;
}

void Grava_nome()
{
    char *novo_nome, *p = string;
    
    novo_nome = Ler_nome();
    int tam_nome = strlen(novo_nome) + 1;

    printf("Nome: %s\n", novo_nome);
    printf("Strlen string: %d\n", strlen(string));

    string = realloc(string, (sizeof(char) * (tam_nome + strlen(string))));

    memcpy(p, novo_nome, tam_nome);
    printf("Strlen string: %d\n", strlen(string));
    
    p = p + tam_nome;
    *p = '@';
    *(p + 1) = '\0';
    printf("Strlen string: %d\n", strlen(string));
    free(novo_nome);
    printf("Nome: %s\n", string);

    return;
}

int main()
{
    string = (char *)malloc(sizeof(char));
    *string = '\0';

    Grava_nome();
    Grava_nome();
    Grava_nome();

    printf("Todos nomes: %s", string);

    free(string);
}