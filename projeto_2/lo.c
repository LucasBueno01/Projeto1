#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int qual;
}Tarefa;

typedef struct NoLista{
    struct NoLista * prox;
    Tarefa tarefa;
}NoLista;

typedef struct NoLista * ptrNoLista;

typedef struct{
    int qtde;
    ptrNoLista inicio;
}Lista;

void inicializar(Lista * l){
    l->inicio = NULL;
    l->qtde = 0;
}

bool estaVazia(Lista * l){
    return(l->qtde == 0);
}

int qualInicio(Lista * l){
    if(!estaVazia(l)) return(l->inicio->tarefa.qual);
    printf("\n\nLista vazia, nada no inicio!");
    return -1;
}
void imprimirLista(Lista * l){
    if(estaVazia(l)){
        printf("\n\nNada a imprimir, lista vazia!");
        return;
    }
    printf("\n\nIMPRIMINDO LISTA: [");
    for(ptrNoLista aux = l->inicio; aux != NULL; aux = aux->prox){
        printf(" %d ", aux->tarefa.qual);
    }
    printf("]");
}
void inserirLista(Lista * l, int num){
    ptrNoLista aux = malloc(sizeof(NoLista));
    aux->tarefa.qual = num;
    if(estaVazia(l)){
        l->inicio = aux;
        aux->prox = NULL;
    } else if (num < l->inicio->tarefa.qual){
        aux->prox = l->inicio;
        l->inicio = aux;
    } else{
        ptrNoLista achar = l->inicio->prox;
        while(achar->prox != NULL && achar->prox->tarefa.qual < num){
            aux = aux->prox;
        }
        aux->prox = achar->prox;
        achar->prox = aux;
    }
    l->qtde++;
}

void removerLista(Lista * l, int num){
    //buscar OlogN
    //remover
    //se n existe e tals
}

int main(){

}