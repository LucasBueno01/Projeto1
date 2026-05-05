#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int valor;
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

void qualTopo(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNao ha topo, pilha vazia!");
        return;
    }
    printf("\nO topo eh: %d",p->topo->prato.valor);
}

void numElementos(Pilha * p){
    printf("\nA pilha possui %d elementos!",p->qtde); 
}

void empilhar(Pilha * p, int num){
    ptrNoPilha aux = malloc(sizeof(NoPilha));
    if(aux == NULL){
        printf("\n\nErro de alocacao de memoria!");
        exit(1);
    }
    aux->prato.valor = num;
    aux->prox = p->topo;
    p->topo = aux;
    p->qtde++;
    printf("\nValor %d empilhado!", num);
}

void desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nImpossivel desempilhar, pilha vazia!");
        return;
    }
    ptrNoPilha aux = p->topo;
    p->topo = p->topo->prox;
    printf("\nValor %d, desempilhado", aux->prato.valor);
    free(aux);
    p->qtde--;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a imprimir!");
        return;
    }
    printf("\n\nIMPRIMINDO PILHA\n");
    for(ptrNoPilha aux = p->topo; aux != NULL; aux = aux->prox){
        printf("\n[ %d ]", aux->prato.valor);
    }
}

void destruir(Pilha * p){
    while(!estaVazia(p)){
        desempilhar(p);
    }
}

int main(){
    Pilha p1;
    inicializar(&p1);

    qualTopo(&p1);
    numElementos(&p1);

    printPilha(&p1);
    empilhar(&p1, 10);
    empilhar(&p1, 20);
    empilhar(&p1, 30);
    empilhar(&p1, 40);
    empilhar(&p1, 50);
    printPilha(&p1);

    desempilhar(&p1);
    printPilha(&p1);
    desempilhar(&p1);
    desempilhar(&p1);
    printPilha(&p1);

    qualTopo(&p1);
    numElementos(&p1);

}