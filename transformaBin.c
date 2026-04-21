#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TAM 15

typedef struct Pilha{
    int vet[TAM];
    int topo;
} pilha;

void inicializa(pilha *p){
    p->topo = 0;
}

bool estaCheia(pilha *p){
    return(p->topo == TAM);
}

bool estaVazia(pilha * p){
    return(p->topo == 0);
}

int empilha(pilha * p, int valor){
    if(estaCheia(p)){
        printf("pilha cheia!");
        return 0;
    } else{
        p->vet[p->topo] = valor;
        p->topo++;
    }
}

int desempilha(pilha *p, int valor){
    if(estaVazia(p)){
        printf("Pilha vazia, nada a retornar!");
        return 0;
    }else{
        p->topo--;
        valor = p->topo;
        return valor;
    }
}

void printa(pilha * p){
    int i;
    printf("\n\nIMPRESSAO DA PILHA\n\n");
    for(i=p->topo-1;i>=0;i--){
        printf("[%d]\n", p->vet[i]);
    }
    return;
}

int main(){
    pilha pil;
    inicializa(&pil);
    int dec, i;
    printf("\nDigite o valor em decimal: ");
    scanf("%d", &dec);
    int div_temp;

    do{
        div_temp = dec % 2;
        empilha(&pil, div_temp);
        dec = dec/2;
    }while(dec > 0);
    
    printa(&pil);
}