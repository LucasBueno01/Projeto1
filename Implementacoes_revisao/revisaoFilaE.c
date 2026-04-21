#include<stdio.h>
#include<stdbool.h>
#define TAM_MAX 10

typedef struct{
    int valores[TAM_MAX];
    int inicio;
    int fim;
    int tam;
}Fila;

void inicializar(Fila * f){
    f->inicio = 0;
    f->fim = -1;
    f->tam = 0;
    return;
}

bool estaVazia(Fila * f){
    return(f->tam == 0);
}

bool estaCheia(Fila * f){
    return(f->tam == TAM_MAX);
}
//função auxiliar para ver se tem espaço e definir o índice;
int definirindice(int indice){
    int retorno;
    if(indice == TAM_MAX-1){
        retorno = 0; 
    } else{
        retorno = indice+1;
    }
    return retorno;
}

void enfileirar(Fila * f, int num){
    if(estaCheia(f)){
        printf("\n\nFila cheia, impossivel empilhar");
        return;
    } else{
        f->fim = definirindice(f->fim);
        f->valores[f->fim] = num;
        f->tam++;
        return;
    }
}

int desenfileirar(Fila * f){
    if(estaVazia(f)){
        printf("\n\nFila Vazia, nada a desempilhar");
        return -1;
    }
    int aux = f->valores[f->inicio];
    f->inicio = definirindice(f->inicio);
    f->tam--;
    return aux;
}

void printFila(Fila * f){
    if(estaVazia(f)){
        printf("\n\nFila Vazia! Nada a imprimir;\n");
        return;
    }
    int i = f->inicio;
    while(i != f->fim){
        printf(" %d ", f->valores[i]);
        i = definirindice(i);
    }
    printf(" %d \n\n", f->valores[f->fim]);
    return;
}

int main(){
    Fila f1;
    inicializar(&f1);
    printFila(&f1);

    enfileirar(&f1, 10);
    printFila(&f1);
    enfileirar(&f1, 20);
    printFila(&f1);
    enfileirar(&f1, 30);
    printFila(&f1);
    enfileirar(&f1, 40);
    printFila(&f1);
    enfileirar(&f1, 50);
    printFila(&f1);
    enfileirar(&f1, 60);
    printFila(&f1);

    int val = desenfileirar(&f1);
    printf("Desenfileirando: %d\n", val);
    val = desenfileirar(&f1);
    printf("Desenfileirando: %d\n", val);
    val = desenfileirar(&f1);
    printf("Desenfileirando: %d\n", val);
    val = desenfileirar(&f1);
    printf("Desenfileirando: %d\n", val);
    val = desenfileirar(&f1);
    printf("Desenfileirando: %d\n", val);


    printFila(&f1);

}