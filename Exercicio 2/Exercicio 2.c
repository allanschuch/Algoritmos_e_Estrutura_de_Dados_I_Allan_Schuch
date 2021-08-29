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
    char *novoNome, *ponteiro;
    int tamNome, i;

    novoNome = lerNome();
    tamNome = strlen(novoNome);

    string = realloc(string, (sizeof(char) * (tamNome + strlen(string) + 2)));

    ponteiro = string + strlen(string);
    
    memcpy(ponteiro, novoNome, sizeof(char) * tamNome);

    ponteiro = ponteiro + tamNome;
    *ponteiro = '-';
    *(ponteiro + 1) = '\0';

    free(novoNome);

    printf("Todos nomes: %s", string);

    return;
}

int main(){

    char *stringNomes;

    stringNomes = (char *)malloc(sizeof(char));
    *stringNomes = '\0';

    for ( ; ; ){
        gravarNome(stringNomes);
    }
    
    free(stringNomes);
}