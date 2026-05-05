#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define tam 10

typedef struct{
    int valores[tam];
    int topo;
}Pilha;

void inicializar(Pilha * p){
    p->topo = 0;
}

bool estaVazia(Pilha * p){
    return (p->topo == 0);
}

bool estaCheia(Pilha * p){
    return(p->topo == tam);
}

void empilhar(Pilha * p, int num){
    if(estaCheia(p)){
        printf("\n\nImpossivel empilhar, pilha cheia");
        return;
    }
    p->valores[p->topo] = num;
    p->topo++;
}

void desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("Impossivel desempilhar, pilha vazia!");
        return;
    }
    int valor = p->valores[p->topo-1];
    p->topo--;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        return;
    }
    for(int i = p->topo-1; i >= 0; i--){
        printf("[ %d ]", p->valores[i]);
    }
}

int main(){
    Pilha p1;
    inicializar(&p1);

    empilhar(&p1, 10);
    empilhar(&p1, 20);
    empilhar(&p1, 30);
    empilhar(&p1, 40);
    empilhar(&p1, 50);

    printPilha(&p1);
    desempilhar(&p1);
    desempilhar(&p1);

    printPilha(&p1);

}