#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define TAM_MAX 10



typedef struct{
    int topo;
    int valores[TAM_MAX];
    int qtde_manobras; 
} Pilha;

void inicializar(Pilha * p){
    p->topo = 0;
    p->qtde_manobras = 0;
}

bool estaVazia(Pilha * p){
    return(p->topo == 0);
}

bool estaCheia(Pilha * p){
    return(p->topo == TAM_MAX);
}

void empilhar(Pilha * p, int num){
    if(estaCheia(p)){
        printf("\n\nImpossivel empilhar! Pilha cheia!\n\n");
        return;
    }
    printf("\nEmpilhando valor: %d", num);
    p->valores[p->topo] = num;
    p->topo++;
}

int desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a desempilhar! Pilha vazia!\n\n");
        exit(1);
    }
    p->topo--;
    int resgatar = p->valores[p->topo];
    return resgatar;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada a imprimir!\n\n");
        return;
    }
    printf("\n\nIMPRESSAO DA PILHA\n");
    for(int i = p->topo-1; i >= 0; i--){
        printf("\n[ %d ]", p->valores[i]);
    }
}

void removerValor(Pilha * p, Pilha * aux, int placa){
    while(!estaVazia(p) && p->valores[p->topo-1] != placa){
        empilhar(aux, desempilhar(p));
        p->qtde_manobras++;
    }
    if(!estaVazia(p)) desempilhar(p);
    while(!estaVazia(aux)){
        empilhar(p, desempilhar(aux));
        p->qtde_manobras++;
    }
    p->qtde_manobras++;
}

int main(){
    Pilha p1;
    Pilha aux;
    inicializar(&p1);
    inicializar(&aux);

    empilhar(&p1, 10);
    empilhar(&p1, 20);
    empilhar(&p1, 30);
    empilhar(&p1, 40);
    empilhar(&p1, 50);
    printPilha(&p1);
    removerValor(&p1, &aux, 20);
    printPilha(&aux);
    printPilha(&p1);

}