#include<stdio.h>
#include<stdbool.h>
#define TAM_MAX 10

typedef struct{
    int valores[TAM_MAX];
    int topo;
}Pilha;

void inicializarPilhaE(Pilha * p){
    p->topo = 0;
    return;
}

bool estaCheia(Pilha * p){
    return(p->topo == TAM_MAX);
}

bool estaVazia(Pilha * p){
    return(p->topo == 0);
}

void empilhar(Pilha * p, int num){
    if(estaCheia(p)){
        printf("\nPilha cheia, impossivel empilhar!\n\n");
        return;
    }
    p->valores[p->topo] = num;
    p->topo++;
    return;
}

int desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a desempilhar, pilha vazia!");
        return -1;
    }
    p->topo--;
    int aux = p->valores[p->topo];
    return aux;
}

void printPilhaE(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a imprimir, pilha vazia!\n\n");
        return;
    }
    printf("\nIMPRIMINDO PILHA\n\n");
    for(int i = p->topo-1; i >= 0; i--){
        printf("[ %d ]", p->valores[i]);
    }
    
}

int main(){
    Pilha p1;
    inicializarPilhaE(&p1);
    printPilhaE(&p1);
    empilhar(&p1, 10);
    empilhar(&p1, 20);
    empilhar(&p1, 30);
    empilhar(&p1, 40);
    empilhar(&p1, 50);
    printPilhaE(&p1);
    printf("\ndesempilhando: %d", desempilhar(&p1));
    printPilhaE(&p1);
    printf("\ndesempilhando: %d", desempilhar(&p1));
    printPilhaE(&p1);
    printf("\ndesempilhando: %d", desempilhar(&p1));
    printPilhaE(&p1);
}