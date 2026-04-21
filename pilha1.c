#include<stdio.h>

#define TAM 10

typedef struct Pilha{
    int vet[TAM];
    int topo;
} pilha;

void inicializaPilha(pilha * p){
    p->topo = 0;
    return;
}

int estaCheia(pilha * p){
    if(p->topo == TAM) return 1;
    return 0;
}

int estaVazia(pilha * p){
    if(p->topo == 0) return 1;
    return 0;
}

void empilha(int valor, pilha * p){
    if(estaCheia(p)){
        printf("Pilha cheia!\n");
        return;
    }
    p->vet[p->topo] = valor;
    p->topo++;
}

int desempilhar(pilha * p){
    int aux;
    if(estaVazia(p)){
        printf("Nada a desempilhar, pilha vazia!\n");
        return 0;
    }
    p->topo--;
    aux = p->vet[p->topo];
    return(aux);
}

void printaPilha(pilha * p){
    int i;
    printf("\nIMPRESSAO DA PILHA\n\n");
    for(i=p->topo-1; i>=0; i--){
        printf("%d\n", p->vet[i]);
    }
    return;
}

int main(){
    pilha pil1;
    inicializaPilha(&pil1);
    empilha(5, &pil1);
    empilha(1, &pil1);
    empilha(3, &pil1);
    int a = desempilhar(&pil1);
    empilha(5, &pil1);
    empilha(7, &pil1);
    empilha(9, &pil1);

    printaPilha(&pil1);
    
    printf("\n\n A= %d\n\n", a);
}