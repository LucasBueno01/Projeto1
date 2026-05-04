#include<stdio.h>
#include<stdbool.h>
#define TAM_MAX 10

typedef struct{
    int topo;
    int valores[TAM_MAX];
    int qtde; //dada a forma que eu implemento a pilha, p->topo == p->qtde, porém deixarei
} Pilha;

void inicializar(Pilha * p){
    p->topo = 0;
    p->qtde = 0;
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
    p->qtde++;
}

void desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a desempilhar! Pilha vazia!\n\n");
        return;
    }
    p->topo--;
    int resgatar = p->valores[p->topo];
    p->qtde--;
    printf("\nValor %d desempilhado!", resgatar);
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
    desempilhar(&p1);
    printPilha(&p1);
    desempilhar(&p1);
    desempilhar(&p1);
    printPilha(&p1);

}