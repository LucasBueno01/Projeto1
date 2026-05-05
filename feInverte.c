#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define tam 10

typedef struct{
    int qual;
}Pessoa;

typedef struct{
    int qtde;
    int inicio;
    int fim;
    Pessoa pessoas[tam];
}Fila;

void inicializar(Fila * f){
    f->fim = -1;
    f->inicio = 0;
    f->qtde = 0;
}

bool estaVazia(Fila * f){
    return f->qtde == 0;
}

bool estaCheia(Fila * f){
    return f->qtde == tam;
}

/*int incrementaIndice(int num){
    int retorno;
    if(num == tam-1){
        retorno = 0;
    } else{
        retorno = num + 1;
    }
    return retorno;
}*/
int incrementaIndice(int num){
    return (num + 1) % tam;
}

void enfileirar(Fila * f, int num){
    if(estaCheia(f)){
        printf("\n\nImpossivel enfileirar, fila cheia!");
        return;
    }
    f->fim = incrementaIndice(f->fim);
    f->pessoas[f->fim].qual = num;
    f->qtde++;
}

void desenfileirar(Fila * f){
    if(estaVazia(f)){
        printf("\n\nFila vazia, nada a desenfileirar!");
        return;
    }
    int valor = f->pessoas[f->inicio].qual;
    f->inicio = incrementaIndice(f->inicio);
    f->qtde--;
}

void printFila(Fila * f){
    if(estaVazia(f)){
        printf("\n\nFila vazia, nada a imprimir!");
        return;
    }
    int aux = f->inicio;
    while(aux != f->fim){
        printf(" %d ", f->pessoas[aux].qual);
        aux = incrementaIndice(aux);
    }
    printf(" %d ", f->pessoas[aux].qual);
}

int main(){
    Fila f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    printFila(&f);

    printf("\nRemovendo...\n");
    desenfileirar(&f);

    printFila(&f);

    printf("\nInserindo mais...\n");
    enfileirar(&f, 40);
    enfileirar(&f, 50);

    printFila(&f);
}