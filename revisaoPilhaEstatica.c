#include<stdio.h>
#include<stdbool.h>
#define TAM_MAX 10

typedef struct{
    int valor;
} Prato;

typedef struct{
    Prato valores[TAM_MAX];
    int topo;
} Pilha;

void inicializar(Pilha * p){
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
        printf("\nImpossivel empilhar! Pilha cheia!\n");
        return;
    }
    p->valores[p->topo].valor = num;
    p->topo++;
    return;
}
int desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\nNada a desempilhar! Pilha vazia!\n");
        return -1;
    }
    p->topo--;
    int aux = p->valores[p->topo].valor;
    return aux;
}
void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\nNada a imprimir, pilha vazia!\n");
        return;
    }
    printf("\nIMPRIMINDO A PILHA:\n");
    for(int i = p->topo-1; i >= 0; i--){
        printf("[ %d ]\n", p->valores[i].valor);
    }
    return;
}
int qualTopoAtual(Pilha * p){
    return(p->valores[p->topo-1].valor);
}
int main(){
    Pilha p1;
    inicializar(&p1);

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
    int topo = qualTopoAtual(&p1);
    printf("\n\nO topo atual eh: %d", topo);
    return 0;
}