#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Prato{
    int qual;
}Prato;

typedef struct NoPilha{
    struct NoPilha * prox;
    Prato prato;
}NoPilha;

typedef struct NoPilha * ptrNoPilha;

typedef struct{
    ptrNoPilha topo;
    int qtde;
}Pilha;

void inicializar(Pilha * p){
    p->qtde = 0;
    p->topo = NULL;
}

bool estaVazia(Pilha * p){
    return(p->topo == NULL);
}

void empilhar(Pilha * p, int num){
    ptrNoPilha aux = malloc(sizeof(NoPilha));
    if(aux == NULL){
        printf("\n\nErro ao alocar memoria!");
        exit(1);
    }
    aux->prato.qual = num;
    aux->prox = p->topo;
    p->topo = aux;
    p->qtde++;
}

void desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a desempilhar, pilha vazia!");
        return;
    }
    ptrNoPilha aux = p->topo;
    p->topo = p->topo->prox;
    int valor = aux->prato.qual;
    free(aux);
    p->qtde--;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a imprimir!");
        return;
    }
    printf("\n\nIMPRIMINDO A PILHA");
    for(ptrNoPilha aux = p->topo; aux != NULL; aux = aux->prox){
        printf("\n[ %d ]", aux->prato.qual);
    }
}

int main(){
    Pilha p;
    inicializar(&p);

    printf("\n--- Empilhando valores ---\n");
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    empilhar(&p, 40);
    empilhar(&p, 50);

    printPilha(&p);

    printf("\n\n--- Desempilhando dois elementos ---\n");
    desempilhar(&p);
    desempilhar(&p);

    printPilha(&p);

    printf("\n\n--- Empilhando mais valores ---\n");
    empilhar(&p, 60);
    empilhar(&p, 70);

    printPilha(&p);

    printf("\n\n--- Esvaziando a pilha ---\n");
    while(!estaVazia(&p)){
        desempilhar(&p);
    }

    printPilha(&p);

    return 0;
}