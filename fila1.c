#include<stdio.h>
#include<stdbool.h>
#define TAM_MAX 10

typedef struct{
    int valores[TAM_MAX];
    int inicio, fim, tamanho;
}Fila;

void inicializaFila(Fila * f){
    f->fim = -1;
    f->inicio = 0;
    f->tamanho = 0;
}

bool estaCheia(Fila * f){
    return(f->fim == TAM_MAX-1);
}

bool estaVazia(Fila * f){
    return(f->tamanho == 0);
}

void enfileirar(Fila * f, int num){
    if(estaCheia(f)){
        printf("\n\nFila cheia, impossivel enfileirar!\n");
        return;
    }
    f->fim++;
    f->valores[f->fim] = num;
    f->tamanho++;
}

int desenfileirar(Fila * f){
    if(estaVazia(f)){
        printf("\n\nNada a desenfileirar, fila vazia!\n");
        return -1;
    }
    int aux = f->valores[f->inicio];
    f->inicio++;
    f->tamanho--;
    return aux;
}

void imprimirFila(Fila * f){
    printf("FILA: [ ");
    for(int i = f->inicio; i<=f->fim; i++){
        printf("%d ", f->valores[i]);
    }
    printf(" ]\n");
    return;
}

int main(){
    Fila f;

    // Inicializa a fila
    inicializaFila(&f);

    printf("Fila inicial:\n");
    imprimirFila(&f);

    // Testando enfileirar
    printf("\nEnfileirando 4, 1, 3...\n");
    enfileirar(&f, 4);
    enfileirar(&f, 1);
    enfileirar(&f, 3);
    imprimirFila(&f);

    // Testando desenfileirar
    printf("\nDesenfileirando...\n");
    int removido = desenfileirar(&f);
    printf("Removido: %d\n", removido);
    imprimirFila(&f);

    // Mais inserções
    printf("\nEnfileirando 8 e 10...\n");
    enfileirar(&f, 8);
    enfileirar(&f, 10);
    imprimirFila(&f);

    // Mais remoções
    printf("\nDesenfileirando dois elementos...\n");
    printf("Removido: %d\n", desenfileirar(&f));
    printf("Removido: %d\n", desenfileirar(&f));
    imprimirFila(&f);

    // Teste de fila vazia
    printf("\nEsvaziando a fila...\n");
    while(!estaVazia(&f)){
        printf("Removido: %d\n", desenfileirar(&f));
    }
    imprimirFila(&f);

    // Teste de erro (fila vazia)
    printf("\nTentando desenfileirar com fila vazia:\n");
    desenfileirar(&f);

    // Teste de fila cheia
    printf("\nEnchendo a fila...\n");
    for(int i = 0; i < TAM_MAX; i++){
        enfileirar(&f, i+1);
    }
    imprimirFila(&f);

    printf("\nTentando enfileirar com fila cheia:\n");
    enfileirar(&f, 99);

    return 0;
}