#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Pessoa{
    int qual;
}Pessoa;

typedef struct NoFila{
    struct NoFila * prox;
    Pessoa pessoa;
}NoFila;

typedef struct NoFila * ptrNoFila;

typedef struct{
    ptrNoFila inicio;
    ptrNoFila fim;
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

void enfileirar(Fila * f, int num){
    ptrNoFila aux = malloc(sizeof(NoFila));
    if(aux == NULL){
        printf("\n\nErro de alocacao de memoria!");
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
        printf("\n\nNao eh possivel desenfileirar, fila vazia!");
        return;
    }
    ptrNoFila aux = f->inicio;
    int valor = f->inicio->pessoa.qual;
    f->inicio = f->inicio->prox;
    free(aux);
    f->qtde--;
    if(f->inicio == NULL) f->fim = NULL;
}

void printFila(Fila * f){
    if(estaVazia(f)){
        
    }
}