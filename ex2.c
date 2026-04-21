#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
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

void inicializarPilha(Pilha * p){
    p->qtde = 0;
    p->topo = NULL;
    return;
}

bool estaVazia(Pilha * p){
    return(p->topo == NULL);
}

void empilhar(Pilha * p, int num){
    ptrNoPilha aux = malloc(sizeof(NoPilha));
    if(aux == NULL){
        printf("\nErro na alocacao de memoria!\n\n");
        return;
    }
    aux->prox = p->topo;
    p->topo = aux;
    p->topo->prato.qual = num;
    p->qtde++;
    return;
}

int desempilhar(Pilha * p){
    ptrNoPilha aux = p->topo;
    if(estaVazia(p)){
        printf("N\n\nNada a desempilhar, pilha vazia!\n\n");
        return -1;
    }
    int valor = aux->prato.qual;
    p->topo = aux->prox;
    free(aux);
    p->qtde--;
    return valor;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a imprimir!\n\n");
        return;
    }
    printf("\n\nIMPRIMINDO PILHA");
    for(ptrNoPilha i=p->topo; i != NULL; i = i->prox){
        printf("[ %d ]\n", i->prato.qual);
    }
    return;
}

typedef struct NoFila{
    struct NoFila * prox;
    Prato prato;
}NoFila;

typedef struct NoFila * ptrNoFila;

typedef struct{
    ptrNoFila inicio;
    ptrNoFila fim;
    int tamanho;
}Fila;

void inicializaFila(Fila * f){
    f->fim = NULL;
    f->inicio = NULL;
    f->tamanho = 0;
    return;
}

bool estaVaziaFila(Fila * f){
    return(f->inicio == NULL);
}

int tamFila(Fila * f){
    return f->tamanho;
}

void enfileirar(Fila * f){
    ptrNoFila aux = malloc(sizeof(NoFila));
    if(aux == NULL){
        printf("\n\nErro ao alocar memoria na fila!\n\n");
        return;
    }
    
}





int main(){
    Pilha p;
    inicializarPilha(&p);

    printf("--- Testando Pilha de Pratos ---\n");
    empilhar(&p, 1); // Prato 1 (fundo)
    empilhar(&p, 2);
    empilhar(&p, 3); // Prato 3 (topo)
    
    printPilha(&p);

    printf("\nDesempilhando: %d\n", desempilhar(&p));
    printPilha(&p);

    printf("\nLimpando a pilha...\n");
    desempilhar(&p);
    desempilhar(&p);
    
    printPilha(&p);

    return 0;
}