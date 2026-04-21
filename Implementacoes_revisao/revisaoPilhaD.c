#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
    int valor;
}Prato;

typedef struct NoPilha{
    struct NoPilha * prox;
    Prato prato;
}NoPilha;

typedef struct NoPilha * prtNoPilha;

typedef struct{
    prtNoPilha topo;
    int tam;
}Pilha;

void inicializar(Pilha * p){
    p->topo = NULL;
    p->tam = 0;
    return;
}

bool estaVazia(Pilha * p){
    return(p->topo == NULL);
}

void empilhar(Pilha * p, int num){
    prtNoPilha aux = malloc(sizeof(NoPilha));
    if(aux == NULL){
        printf("\n\nErro ao alocar memoria!");
        return;
    }
    aux->prato.valor = num;
    aux->prox = p->topo;
    p->topo = aux;
    p->tam++;
    return;
}

int desempilhar(Pilha * p){
    prtNoPilha aux = p->topo;
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a desemplilhar!");
        return -1;
    }
    int valor;
    valor = p->topo->prato.valor;
    p->topo = p->topo->prox;
    free(aux);
    p->tam--;
    return valor;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a imprimir!\n\n");
        return;
    }
    printf("\n\nIMPRIMINDO PILHA");
    for(prtNoPilha i = p->topo; i != NULL; i = i->prox){
        printf("[ %d ] ", i->prato.valor);
    }
    return;
}

int qualTopo(Pilha * p){
    return p->topo->prato.valor;
}

int qualTam(Pilha * p){
    return p->tam;
}

void destruirPilha(Pilha * p){
    while(!estaVazia(p)){
        prtNoPilha aux;
        printf("Desempilhando: %d\n", desempilhar(p));
    }
    return;
}

int main(){
    Pilha p1;
    inicializar(&p1);
    printPilha(&p1);
    empilhar(&p1, 10);
    empilhar(&p1, 20);
    empilhar(&p1, 30);
    empilhar(&p1, 40);
    empilhar(&p1, 50);
    printPilha(&p1);
    printf("\ndesempilhando: %d", desempilhar(&p1));
    printPilha(&p1);
    printf("\ndesempilhando: %d", desempilhar(&p1));
    printPilha(&p1);
    printf("\ndesempilhando: %d", desempilhar(&p1));
    printPilha(&p1);

    printf("O tam da pilha eh: %d", qualTam(&p1));
    printf("O topo da pilha eh: %d", qualTopo(&p1));

    destruirPilha(&p1);
}
