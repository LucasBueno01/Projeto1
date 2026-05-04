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

void comparar(Lista * l1, Lista * l2){
    ptrNoLista aux = l1->inicio;
    int cont1 = 0, cont2 = 0;
    while(aux != NULL){
        aux = aux->prox;
        cont1++;
    }
    aux = l2->inicio;
    while(aux != NULL){
        aux = aux->prox;
        cont2++;
    }
    if(cont1 == cont2){
        printf("Listas tem o mesmo tamanho");
    } else if(cont1 > cont2){
        printf("\n\nA lista 1 eh maior que a lista 2!");
    } else{
        printf("\n\nLista 2 eh maior que a lista 1");
    }
    return;
}

bool compararListas(Lista * l1, Lista * l2){
    ptrNoLista aux1 = l1->inicio;
    ptrNoLista aux2 = l2->inicio;

    while(aux1 != NULL && aux2 != NULL){
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return(aux1 != NULL && aux2 == NULL);
}

int main(){
   Lista l1, l2;

    inicializarLista(&l1);
    inicializarLista(&l2);

    printf("\n======================================");
    printf("\n      TESTE COMPLETO DAS LISTAS");
    printf("\n======================================\n");

    /* Estado inicial */
    printf("\n[1] Estado inicial das listas:");
    imprimirLista(&l1);
    imprimirLista(&l2);

    printf("\n\nComparando listas vazias:");
    comparar(&l1, &l2);

    /* Inserções Lista 1 */
    printf("\n\n[2] Inserindo elementos na Lista 1:");
    printf("\nInserindo: 30, 10, 50, 20, 40");

    inserirNaLista(&l1, 30);
    inserirNaLista(&l1, 10);
    inserirNaLista(&l1, 50);
    inserirNaLista(&l1, 20);
    inserirNaLista(&l1, 40);

    imprimirLista(&l1);
    printf("\nQuantidade Lista 1: %d", tamanhoLista(&l1));

    /* Inserções Lista 2 */
    printf("\n\n[3] Inserindo elementos na Lista 2:");
    printf("\nInserindo: 15, 5, 35");

    inserirNaLista(&l2, 15);
    inserirNaLista(&l2, 5);
    inserirNaLista(&l2, 35);

    imprimirLista(&l2);
    printf("\nQuantidade Lista 2: %d", tamanhoLista(&l2));

    /* Primeira comparação */
    printf("\n\n[4] Comparando listas:");
    comparar(&l1, &l2);

    /* Remoções Lista 1 */
    printf("\n\n[5] Removendo elementos da Lista 1:");
    printf("\nRemover inicio (10)");
    removerLista(&l1, 10);
    imprimirLista(&l1);

    printf("\n\nRemover meio (30)");
    removerLista(&l1, 30);
    imprimirLista(&l1);

    printf("\n\nRemover final (50)");
    removerLista(&l1, 50);
    imprimirLista(&l1);

    printf("\nQuantidade Lista 1: %d", tamanhoLista(&l1));

    /* Inserções extras Lista 2 */
    printf("\n\n[6] Inserindo mais elementos na Lista 2:");
    printf("\nInserindo: 25, 45, 55");

    inserirNaLista(&l2, 25);
    inserirNaLista(&l2, 45);
    inserirNaLista(&l2, 55);

    imprimirLista(&l2);
    printf("\nQuantidade Lista 2: %d", tamanhoLista(&l2));

    /* Segunda comparação */
    printf("\n\n[7] Comparando novamente:");
    comparar(&l1, &l2);

    /* Teste valor inexistente */
    printf("\n\n[8] Tentando remover valor inexistente (999) da Lista 1:");
    removerLista(&l1, 999);

    /* Estado final */
    printf("\n\n[9] Estado final das listas:");
    printf("\nLista 1:");
    imprimirLista(&l1);

    printf("\nLista 2:");
    imprimirLista(&l2);

    /* Destruição */
    printf("\n\n[10] Destruindo listas...");
    destruirLista2(&l1);
    destruirLista2(&l2);

    printf("\n\nListas apos destruir:");
    imprimirLista(&l1);
    imprimirLista(&l2);

    printf("\n\n======================================");
    printf("\n         FIM DOS TESTES");
    printf("\n======================================\n");

    return 0;
}