#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerNome(){

    char ch, *inicio, *ponteiro;
    int i = 0;

    inicio = (char *)malloc(sizeof(char) * 2);
    ponteiro = inicio;

    *inicio = getchar();

    while ((ch = getchar()) != '\n'){
        inicio = realloc(inicio, sizeof(char) * (i + 3));
        ponteiro = inicio + (i + 1);                                                                                     
        *ponteiro = ch;
        i++;                                                             
    }

    ponteiro = inicio + (i + 1);
    *ponteiro = '\0';

    printf("Nome lido: %s\n", inicio);

    return inicio;
}

void gravarNome(char *string)
{
    char *novo_nome, *ponteiro = string;
    
    novo_nome = lerNome();
    int tam_nome = strlen(novo_nome) + 1;

    printf("Nome: %s\n", novo_nome);
    printf("Strlen string: %d\n", strlen(string));

    string = realloc(string, (sizeof(char) * (tam_nome + strlen(string))));

    memcpy(ponteiro, novo_nome, tam_nome);
    printf("Strlen string: %d\n", strlen(string));
    
    ponteiro = ponteiro + tam_nome;
    *ponteiro = '@';
    *(ponteiro + 1) = '\0';
    printf("Strlen string: %d\n", strlen(string));
    free(novo_nome);
    printf("Nome: %s\n", string);

    return;
}

int main(){

    char *stringNomes;

    stringNomes = (char *)malloc(sizeof(char));
    *stringNomes = '\0';
    
    // gravarNome(stringNomes);

    // printf("Todos nomes: %s", stringNomes);

    free(stringNomes);
}