#include<stdio.h>
#include<stdbool.h>
#define TAM_MAX 10

typedef struct{
    int valores[TAM_MAX];
    int inicio;
    int fim;
    int qtde; //pode não existir aqui tbm
}Fila;

void inicializar(Fila * f){
    f->fim = -1;
    f->inicio = 0;
    f->qtde = 0;
}

bool estaVazia(Fila * f){
    return(f->qtde == 0);
}

bool estaCheia(Fila * f){
    return(f->qtde == TAM_MAX);
}

int incrementaIndice(int indice){
    int retorno;
    if(indice == TAM_MAX-1) retorno = 0;
    else retorno = indice +1;
    return(retorno);
}

void enfileirar(Fila * f, int num){
    if(estaCheia(f)){
        printf("\n\nImpossivel enfileirar, fila cheia!");
        return;
    }
    f->fim = incrementaIndice(f->fim);
    f->valores[f->fim] = num;
    f->qtde++;
    printf("\nValor %d enfileirado!", num);
}

void desenfileirar(Fila * f){
    if(estaVazia(f)){
        printf("\n\nNada a desenfileirar! Fila vazia!");
        return;
    }
    int valorSair = f->valores[f->inicio];
    f->inicio = incrementaIndice(f->inicio);
    f->qtde--;
    printf("\n\nElemento %d desenfileirado!", valorSair);
}

void qualInicio(Fila * f){
    if(estaVazia(f)){
        printf("\n\nNao ha valores no inicio!\n\n");
        return;
    }
    printf("\nINICIO: %d", f->valores[f->inicio]);
}

void qualFim(Fila * f){
    if(estaVazia(f)){
        printf("\n\nNao ha valores no fim!\n\n");
        return;
    }
    printf("\nFIM: %d", f->valores[f->fim]);
}

void qualTam(Fila * f){
    printf("\nTAM: %d", f->qtde);
}

void printFila(Fila * f){
    if(estaVazia(f)){
        printf("\n\nFila vazia! Nada a imprimir!");
        return;
    }
    printf("\n\nFila impressa: [");
    int aux = f->inicio;
    while(aux != f->fim){
        printf("%d ", f->valores[aux]);
        aux = incrementaIndice(aux);
    }
    printf("%d]", f->valores[aux]);
}

int main(){
    Fila f1;
    inicializar(&f1);
    printFila(&f1);
    qualFim(&f1);
    qualInicio(&f1);
    qualTam(&f1);

    enfileirar(&f1, 10);
    enfileirar(&f1, 20);
    enfileirar(&f1, 30);
    enfileirar(&f1, 40);
    enfileirar(&f1, 50);
    enfileirar(&f1, 60);
    printFila(&f1);

    qualFim(&f1);
    qualInicio(&f1);
    qualTam(&f1);

    desenfileirar(&f1);
    desenfileirar(&f1);
    desenfileirar(&f1);
    desenfileirar(&f1);

    printFila(&f1);

    qualFim(&f1);
    qualInicio(&f1);
    qualTam(&f1);

    return 0;
}