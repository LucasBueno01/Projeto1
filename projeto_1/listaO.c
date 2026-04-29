#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NoLista{
    int qual;
    struct NoLista * prox;
}NoLista;

typedef struct NoLista * ptrNoLista;

typedef struct{
    int qtdeItens;
    ptrNoLista inicio;
}Lista;

void inicializarLista(Lista * l){
    l->inicio = NULL;
    l->qtdeItens = 0;
}

bool estaVazia(Lista * l){
    return(l->qtdeItens == 0);
}

int tamanhoLista(Lista * l){
    return l->qtdeItens;
}

void imprimirLista(Lista * l){
    if(estaVazia(l)){
        printf("\n\nLista vazia! Nada a imprimir!");
        return;
    }
    printf("\n\nImprimindo lista:\n\n");
    printf("[");
    for(ptrNoLista aux = l->inicio; aux != NULL; aux = aux->prox){
        printf(" %d ", aux->qual);
    }
    printf("]");
}

void inserirNaLista(Lista * l, int valor){
    ptrNoLista aux = malloc(sizeof(NoLista));
    if(aux == NULL){
        printf("\n\nErro ao alocar memoria!");
        return;
    }
    aux->qual = valor;
    if(estaVazia(l)){
        l->inicio = aux;
        aux->prox = NULL;
    } else if(valor < l->inicio->qual){
        aux->prox = l->inicio;
        l->inicio = aux;
    } else{
        ptrNoLista aux2 = l->inicio;
        while(aux2->prox != NULL && valor > aux2->prox->qual){
            aux2 = aux2->prox;
        }
        aux->prox = aux2->prox;
        aux2->prox = aux;
    }
    l->qtdeItens++;
}

void removerLista(Lista * l, int valor){
    ptrNoLista auxiliar;
    if(estaVazia(l) || valor < l->inicio->qual){
        printf("\n\nLista vazia ou o valor é menor que o menor valor da lista! Impossível remover!");
        return;
    }
    if(valor == l->inicio->qual){
        printf("\n\nRemovendo valor %d!", l->inicio->qual);
        auxiliar = l->inicio;
        l->inicio = l->inicio->prox;
        free(auxiliar);
        l->qtdeItens--;
        return;
    }
    ptrNoLista aux = l->inicio;
    while(aux->prox != NULL && valor > aux->prox->qual){
        aux = aux->prox;
    }
    if(aux->prox == NULL || valor < aux->prox->qual){
        printf("\n\nValor não encontrado!");
        return;
    }
    auxiliar = aux->prox;
    aux->prox = aux->prox->prox;
    free(auxiliar);
    l->qtdeItens--;
}

void destruirLista(Lista* l){
    while(!estaVazia(l)){
        removerLista(l, l->inicio->qual);
    }
}

void destruirLista2(Lista * l){
    ptrNoLista aux;
    while(l->inicio != NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
    l->qtdeItens = 0;
}

int main(){
     Lista l;

    inicializarLista(&l);

    printf("\n===== TESTE LISTA ORDENADA =====\n");

    // Lista vazia
    imprimirLista(&l);

    // Inserções
    printf("\n\nInserindo 30...");
    inserirNaLista(&l, 30);

    printf("\nInserindo 10...");
    inserirNaLista(&l, 10);

    printf("\nInserindo 50...");
    inserirNaLista(&l, 50);

    printf("\nInserindo 20...");
    inserirNaLista(&l, 20);

    printf("\nInserindo 40...");
    inserirNaLista(&l, 40);

    imprimirLista(&l);

    // Tamanho
    printf("\n\nQuantidade de itens: %d", tamanhoLista(&l));

    // Remover início
    printf("\n\nRemovendo 10...");
    removerLista(&l, 10);
    imprimirLista(&l);

    // Remover meio
    printf("\n\nRemovendo 30...");
    removerLista(&l, 30);
    imprimirLista(&l);

    // Remover final
    printf("\n\nRemovendo 50...");
    removerLista(&l, 50);
    imprimirLista(&l);

    // Valor inexistente
    printf("\n\nTentando remover 99...");
    removerLista(&l, 99);
    imprimirLista(&l);

    // Inserir novos valores
    printf("\n\nInserindo 15...");
    inserirNaLista(&l, 15);

    printf("\nInserindo 35...");
    inserirNaLista(&l, 35);

    imprimirLista(&l);

    // Destruir lista
    printf("\n\nDestruindo lista...");
    destruirLista2(&l);

    imprimirLista(&l);

    printf("\n\nFim do programa.\n");

    return 0;
}