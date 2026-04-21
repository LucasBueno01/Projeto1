#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int tam;
}panqueca;

typedef struct NoPanqueca{
    panqueca panq;
    struct NoPanqueca * proximo;
}NoPanqueca;

typedef struct NoPanqueca * ptrNoPanqueca;

typedef struct{
    ptrNoPanqueca topo;
    int qtde_panquecas;
}PilhaPanqueca;

void inicializar_prato(PilhaPanqueca * p){
    p->topo = NULL;
    p->qtde_panquecas = 0;
    return;
}

bool estaVazia(PilhaPanqueca * p){
    return(p->topo == NULL);
}

void mostrar_torre(PilhaPanqueca * p){
    ptrNoPanqueca aux;
    printf("\t\tTORRE DE PANQUECAS ATUAL\n\n");
    for(aux = p->topo; aux != NULL ; aux = aux->proximo){
        printf("[ %d ]\n", aux->panq.tam);
    }
    printf("\n");
    return;
}

void adicionar_panqueca(PilhaPanqueca * p, int tam){
    printf("\nAdicionando panqueca de %d cm.\n\n", tam);
    ptrNoPanqueca aux = malloc(sizeof(NoPanqueca));
    aux->panq.tam = tam;
    aux->proximo = p->topo;
    p->topo = aux;
    p->qtde_panquecas++;
    mostrar_torre(p);
    return;
}

int servir_panqueca(PilhaPanqueca * p){
    if(estaVazia(p)){
        printf("\nNao ha panquecas para servir!\n");
    } else{
    printf("\n\nServindo cliente...");
    ptrNoPanqueca aux = p->topo;
    int tam_saiu = aux->panq.tam;
    p->topo = p->topo->proximo;
    free(aux);
    p->qtde_panquecas--;
    return tam_saiu;
    }
}

int ver_topo(PilhaPanqueca * p){
    if(estaVazia(p)){
        printf("\nNao ha panquecas, ou seja, topo vazio!\n");
    }
    return(p->topo->panq.tam);
}

int main(){
    PilhaPanqueca p1;
    inicializar_prato(&p1);

    adicionar_panqueca(&p1, 10);
    adicionar_panqueca(&p1, 15);
    adicionar_panqueca(&p1, 20);
    adicionar_panqueca(&p1, 25);
    adicionar_panqueca(&p1, 30);

    int qual = ver_topo(&p1);
    printf("\n\nA panqueca no topo tem %d cm.", qual);

    int servida = servir_panqueca(&p1);
    printf("\nPanqueca de %d servida!\n", servida);
    servida = servir_panqueca(&p1);
    printf("\nPanqueca de %d servida!\n", servida);

    mostrar_torre(&p1);
    servir_panqueca(&p1);
    servir_panqueca(&p1);
    servir_panqueca(&p1);
    servir_panqueca(&p1);
}