#include<stdio.h>
#include<stdlib.h> //mem dinamica
#include<stdbool.h>

typedef struct item{
    int key;
}item;

typedef struct NoPilha{
    item elemento;
    struct NoPilha* proximo;
}NoPilha;

typedef struct NoPilha* ptrNoPilha; //alias para ptr de struct do tipo tipo NoPilha

typedef struct{
    ptrNoPilha topo;
    int tamanho;
}pilha;

void inicializa(pilha * p){
    p->tamanho = 0;
    p->topo = NULL;
}

int tamanho_pilha(pilha * p){
    return(p->tamanho);
}

bool estaVazia(pilha * p){
    return(p->topo == NULL);
}

void empilhar(pilha * p, int num){
    ptrNoPilha aux = malloc(sizeof(NoPilha));

    if(aux == NULL){
    printf("Erro de memória!\n");
    return;
    //exit(1) -> encerra o programa se quiser;
    }
    aux->elemento.key = num;
    aux->proximo = p->topo;
    p->topo = aux;
    p->tamanho++;
}

int desempilhar(pilha * p){
    if(estaVazia(p)){
        printf("Esta vazia, nada a desempilhar Kirido!");
        return -1;
    } else{
        ptrNoPilha aux = p->topo;
        int valorsaiu = aux->elemento.key;
        p->topo = p->topo->proximo;
        free(aux);
        p->tamanho--;
        return valorsaiu;
    }
}

void imprimirPilha(pilha * p){
    printf("\n\nPilha = [");
    ptrNoPilha aux;
    for(aux =p->topo; aux != NULL; aux = aux->proximo){
        printf("%d ", aux->elemento.key);
    }
    printf("]\n");
}

int topoPilha(pilha * p){
    if(estaVazia(p)){
        printf("Pilha vazia");
        return -1;
    }
    return(p->topo->elemento.key);
}

void destruir(pilha * p){
    ptrNoPilha aux;

    while(p->topo != NULL){
        aux = p->topo;
        p->topo = p->topo->proximo;
        free(aux);
    }
    p->tamanho = 0;
}
int main(){
    pilha p;
    inicializa(&p);

    if(estaVazia(&p)) printf("\nPilha Vazia");

    int tam = tamanho_pilha(&p);
    printf("\nO tamanho da pilha eh: %d", tam);

    empilhar(&p, 6);
    imprimirPilha(&p);
    empilhar(&p, 10);
    imprimirPilha(&p);
    empilhar(&p, 2);
    imprimirPilha(&p);
    empilhar(&p, 7);
    imprimirPilha(&p);
    tam = tamanho_pilha(&p);
    printf("\n\nO novo tamanho eh: %d", tam);

    desempilhar(&p);
    imprimirPilha(&p);
    tam = tamanho_pilha(&p);
    printf("\n\nO novo tamanho eh: %d", tam);
    
    destruir(&p);

}