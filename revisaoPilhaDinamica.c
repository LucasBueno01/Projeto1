#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int valor;
}Prato;

typedef struct NoPilha{
    struct NoPilha * prox;
    Prato qual;
}NoPilha;

typedef struct NoPilha * prtNoPilha;

typedef struct{
    prtNoPilha topo;
    int qtde;
} Pilha;

void inicializaPilha(Pilha * p){
    p->topo = NULL;
    p->qtde = 0;
    return;
}
bool estaVazia(Pilha * p){
    return(p->topo == NULL);
}
void empilhar(Pilha * p, int num){
    prtNoPilha aux = malloc(sizeof(NoPilha));
    if(aux == NULL){
        printf("\n\nErro de alocacao!");
        return;
    }
    aux->qual.valor = num;
    aux->prox = p->topo;
    p->topo = aux;
    p->qtde++;
    return;
}
int desempilhar(Pilha * p){
    prtNoPilha aux = p->topo;
    if(estaVazia(p)){
        printf("\nPilha vazia! Nada a desempilhar!");
        return -1;
    } else{
    int valor = aux->qual.valor;
    p->topo = p->topo->prox;
    free(aux);
    p->qtde--;
    return valor;
    }
}
void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("Pilha Vazia, nada a imprimir!");
        return;
    }
    printf("\n\nIMPRESSAO DA PILHA\n");
    for(prtNoPilha i = p->topo; i != NULL; i = i->prox){
        printf("[ %d ]\n", i->qual.valor);
    }
    return;
}
int tamPilha(Pilha * p){
    return p->qtde;
}
int qualTopo(Pilha * p){
    if(estaVazia(p)){
        printf("\nPilha vazia! Nao ha topo!\n");
        return -1;
    }
    return p->topo->qual.valor;
}
void destruirPilha(Pilha * p){
    while(!estaVazia(p)){
        desempilhar(p);
    }
    printf("\n\nMemoria liberada com sucesso!\n");
    return;
}
int main(){
     Pilha p1;
    inicializaPilha(&p1);

    printPilha(&p1);
    empilhar(&p1, 1);
    printPilha(&p1);
    empilhar(&p1, 23);
    printPilha(&p1);
    empilhar(&p1, 7);
    printPilha(&p1);
    printf("\n\ndesempilhando o valor: %d", desempilhar(&p1));
    printPilha(&p1);
    empilhar(&p1, 15);
    printPilha(&p1);
    int topo = qualTopo(&p1);
    printf("\n\nO topo atual eh: %d", topo);
    destruirPilha(&p1);
    return 0;
}
