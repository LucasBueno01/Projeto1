#include<stdio.h>
#include<stdbool.h>
#define TAM 10

typedef struct{
    int qual;
}Prato;

typedef struct{
    Prato valores[TAM];
    int topo;
}Pilha;

void inicializar(Pilha * p){
    p->topo = 0;
}

bool estaCheia(Pilha * p){
    return(p->topo == TAM);
}

bool estaVazia(Pilha * p){
    return(p->topo == 0);
}

void empilhar(Pilha * p, int valor){
    if(estaCheia(p)){
    printf("\n\nPilha cheia! Impossivel empilhar!\n\n");
    return;
    }
    p->valores[p->topo].qual = valor;
    p->topo++;
    printf("\nEmpilhando valor %d ao topo da pilha!", valor);
    return;
}

void desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia! Nada a desempilhar!");
        return;
    }
    int aux;
    p->topo--;
    aux = p->valores[p->topo].qual;
    printf("\nDesempilhando o valor %d.", aux);
    return;
}

void imprimirPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, impossivel imprimir!\n\n");
        return;
    }
    printf("\nIMPRESSAO DA PILHA!");
    for(int i = p->topo-1; i >= 0; i--){
        printf("\n[ %d ]", p->valores[i].qual);
    }
    return;
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


}