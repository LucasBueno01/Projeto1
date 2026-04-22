#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
    int qual;
}Prato;

typedef struct NoPilha{
    Prato prato;
    struct NoPilha * prox;
}NoPilha;

typedef struct NoPilha * ptrNoPilha;

typedef struct{
    ptrNoPilha topo;
    int qtde;
}Pilha;

void inicializar(Pilha * p){
    p->topo = NULL;
    p->qtde = 0;
    return;
}

bool estaVazia(Pilha * p){
    return(p->qtde == 0);
}

void empilhar(Pilha * p, int num){
    ptrNoPilha aux = malloc(sizeof(NoPilha));
    if(aux == NULL){
        printf("\nErro ao alocar memória!\n");
        return;
    }
    aux->prato.qual = num;
    aux->prox = p->topo;
    p->topo = aux;
    p->qtde++;
    printf("\nEmpilhando o valor %d.", num);
    return;
}

void desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a desempilhar!");
        return;
    }
    ptrNoPilha aux = p->topo;
    int valor = p->topo->prato.qual;
    p->topo = p->topo->prox;
    p->qtde--;
    free(aux);
    printf("\n\nDesempilhando o valor %d.", valor);
    return;
}

void imprimirPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a imprimir, pilha vazia!");
        return;
    }
    printf("\n\nIMPRESSAO DA PILHA");
    for(ptrNoPilha aux = p->topo; aux != NULL; aux = aux->prox){
        printf("\n[ %d ]", aux->prato.qual);
    }
    return;
}

void destruir(Pilha * p){
    while(!estaVazia(p)){
        desempilhar(p);
    }
}

int main(){
    Pilha p1;
    inicializar(&p1);

    empilhar(&p1, 10);
    imprimirPilha(&p1);
    empilhar(&p1, 20);
    imprimirPilha(&p1);
    empilhar(&p1, 30);
    imprimirPilha(&p1);
    empilhar(&p1, 40);
    imprimirPilha(&p1);
    empilhar(&p1, 50);
    imprimirPilha(&p1);
    desempilhar(&p1);
    imprimirPilha(&p1);
    desempilhar(&p1);
    imprimirPilha(&p1);
    empilhar(&p1, 60);
    imprimirPilha(&p1);
    destruir(&p1);
}