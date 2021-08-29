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

    printf("\nNome lido: %s", inicio);

    return inicio;
}

char *gravarNome(char *string){

    char *novoNome, *ponteiro;
    int tamNome, i;

    printf("\nInforme o nome: ");
    novoNome = lerNome();
    tamNome = strlen(novoNome);

    string = realloc(string, (sizeof(char) * (tamNome + strlen(string) + 2)));

    ponteiro = string + strlen(string);
    
    memcpy(ponteiro, novoNome, sizeof(char) * tamNome);

    ponteiro = ponteiro + tamNome;
    *ponteiro = '-';
    *(ponteiro + 1) = '\0';

    free(novoNome);

    return string;
}

void listarNomes(char *string){

    char *token, *aux;
    const char caracDelim[2] = "-";
    

    aux = (char *)malloc(sizeof(char) * strlen(string) + 1);
    strcpy(aux, string);

    printf("String completa: %s", string);

    printf("\nLISTA DE NOMES\n\n");

    token = strtok(aux, caracDelim);

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, caracDelim);
    }

    free(aux);
}

int menu()
{
    int opcao;

    while (opcao < 1 || opcao > 4){
        printf("\n1- Adicionar nome\n2- Remover nome\n3- Listar\n4- Sair\n\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
    }
    return opcao;
}

int main(){

    char *stringNomes;
    int opcao;

    stringNomes = (char *)malloc(sizeof(char));
    *stringNomes = '\0';

    for ( ; ; ){
        opcao = menu();

        switch (opcao){
        case 1:
            stringNomes = gravarNome(stringNomes);
            printf("\nTamanho string: %d\n", strlen(stringNomes));
            break;
        case 2:

            break;
        case 3:
            listarNomes(stringNomes);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}