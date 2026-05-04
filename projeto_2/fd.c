#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
    int qual;
}Pessoa;

typedef struct NoFila{
    Pessoa pessoa;
    struct NoFila * prox;
}NoFila;

typedef struct NoFila * prtNoFila;

typedef struct{
    prtNoFila inicio;
    prtNoFila fim;
    int qtde;
}Fila;

void inicializar(Fila * f){
    f->fim = NULL;
    f->inicio = NULL;
    f->qtde = 0;
}

bool estaVazia(Fila * f){
    return(f->qtde == 0);
}

int qualTam(Fila * f){
    return(f->qtde);
}

int qualInicio(Fila * f){
    if(estaVazia(f)){
        printf("Fila vazia");
        return -1;
    }
    return(f->inicio->pessoa.qual);
}

int qualFim(Fila * f){
    if(estaVazia(f)){
        printf("Fila vazia");
        return -1;
    }
    return(f->fim->pessoa.qual);
}

void enfileirar(Fila * f, int num){
    prtNoFila aux = malloc(sizeof(NoFila));
    if(aux == NULL){
        printf("\n\nErro ao alocar memória!\n\n");
        exit(1);
    }
    aux->pessoa.qual = num;
    aux->prox = NULL;
    if(estaVazia(f)){
        f->inicio = aux;
    } else{
        f->fim->prox = aux;
    }
    f->fim = aux;
    f->qtde++;
}

void desenfileirar(Fila * f){
    if(estaVazia(f)){
        printf("\n\nFila vazia, nada a desenfileirar!");
        return;
    }
    prtNoFila aux = f->inicio;
    int valor = aux->pessoa.qual;
    f->inicio = f->inicio->prox;
    free(aux);
    printf("\nDesenfileirado o elemento %d!", valor);
    f->qtde--;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
}

void printFila(Fila * f){
    if(estaVazia(f)){
        printf("\n\nNada a imprimir, fila vazia!");
        return;
    }
    printf("\n\nImpressao da fila: [");
    prtNoFila aux = f->inicio;
    while(aux != NULL){
        printf(" %d ", aux->pessoa.qual);
        aux = aux->prox;
    }
    printf("]");
}

int main(){
    Fila f1;
    inicializar(&f1);

    // Teste fila vazia
    printFila(&f1);
    printf("\nQuantidade: %d", qualTam(&f1));

    // Inserções
    enfileirar(&f1, 10);
    enfileirar(&f1, 20);
    enfileirar(&f1, 30);
    enfileirar(&f1, 40);
    enfileirar(&f1, 50);

    printFila(&f1);

    printf("\nQuantidade: %d", qualTam(&f1));
    printf("\nInicio da fila: %d", qualInicio(&f1));
    printf("\nFim da fila: %d", qualFim(&f1));

    // Remoções
    desenfileirar(&f1);
    printFila(&f1);

    desenfileirar(&f1);
    desenfileirar(&f1);

    printFila(&f1);

    printf("\nQuantidade: %d", qualTam(&f1));
    printf("\nInicio da fila: %d", qualInicio(&f1));
    printf("\nFim da fila: %d", qualFim(&f1));

    // Esvaziando tudo
    desenfileirar(&f1);
    desenfileirar(&f1);

    printFila(&f1);

    // Tentando remover vazia
    desenfileirar(&f1);

    return 0;
}