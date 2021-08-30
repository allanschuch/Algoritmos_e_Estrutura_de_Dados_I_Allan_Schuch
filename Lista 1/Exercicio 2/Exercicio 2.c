#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int opcao;

    while (opcao < 1 || opcao > 4)
    {
        printf("\n1- Adicionar nome\n2- Remover nome\n3- Listar\n4- Sair\n\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
    }
    return opcao;
}

char *lerNome(){

    // Esta função lê os nomes que o usuário digita e retorna um ponteiro 
    //para o buffer, ajustando o tamanho do buffer a cada caractere inserido

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

    return inicio;
}

char *gravarNome(char *string){

    // Grava na string principal o nome informado pela função lerNome

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

    // Lista os nomes gravados na string

    char *token, *aux;
    const char caracDelim[2] = "-";

    aux = (char *)malloc(sizeof(char) * strlen(string) + 1);

    strcpy(aux, string);
    token = strtok(aux, caracDelim);

    printf("\nLISTA DE NOMES\n\n");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, caracDelim);
    }

    free(aux);
}

char *excluirNome(char *stringNomes){

    //Exclui da string o nome informado pelo usuario

    char *nome, *ponteiro;
    int i, j, tamNome, tamString, check = 0;

    printf("\nInforme o nome que deseja excluir: ");
    nome = lerNome();
    tamNome = strlen(nome);
    tamString = strlen(stringNomes);

    for (ponteiro = stringNomes, i = 0, j = 0; j < tamString; j++)
    {
        if(*ponteiro + i == *nome + i){
            i++;
        }else{
            i = 0;
            ponteiro++;
        }
        if(i == tamNome){
            strcpy(ponteiro, ponteiro + tamNome + 1);
            check = 1;
            stringNomes = (char *)realloc(stringNomes, sizeof(char) * (tamString - tamNome));
        }
    }

    if(check == 0){
        printf("\nNome nao encontrado.\n");
    }

    return stringNomes;
}

int main(){

    char *stringNomes;
    int opcao = 0;

    stringNomes = (char *)malloc(sizeof(char));
    *stringNomes = '\0';

    for (;;)
    {
        opcao = menu();

        switch (opcao){
        case 1:
            stringNomes = gravarNome(stringNomes);
            break;
        case 2:
            stringNomes = excluirNome(stringNomes);
            break;
        case 3:
            listarNomes(stringNomes);
            break;
        case 4:
            free(stringNomes);
            exit(0);
            break;
        default:
            break;
        }
    }
}