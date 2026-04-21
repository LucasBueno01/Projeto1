#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define TAM_MAX 10

typedef struct pilha{
    int valores[TAM_MAX];
    int topo;
} Pilha;

void inicializar_pilha(Pilha * p){
    p->topo = 0;
    return;
}

bool estaCheia(Pilha * p){
    return(p->topo == TAM_MAX);
}

bool estaVazia(Pilha * p){
    return(p->topo == 0);
}

void empilhar(Pilha * p, int valor){
    if(estaCheia(p)){
        printf("Nao eh possivel inserir dados\nPilha Cheia\n\n");
        return;
    }
    p->valores[p->topo] = valor;
    p->topo++;
    return;
}

int desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("Nao ha nada para desempilhar\nPilhaVazia\n\n");
        return -1;
    }
    int aux;
    p->topo--;
    aux = p->valores[p->topo];
    return aux;
}

int qualTopo(Pilha * p){
    if(estaVazia(p)){
        printf("Nao ha nd no topo\n");
        return -1;
    }
    return p->valores[p->topo-1];
}

void imprimePilha(Pilha * p){
    if(estaVazia(p)){
        printf("Nao ha nd para imprimir");
        return;
    }
    printf("\nPILHA ATUAL\n\n");
    for(int i=p->topo-1;i>=0;i--){
        printf("[ %d ]\n", p->valores[i]);
    }
    return;
}
void transferirValores(Pilha * p1, Pilha * p2){
    Pilha aux;
    inicializar_pilha(&aux);

    while(!estaVazia(p1)){
        empilhar(&aux, desempilhar(p1));
    }

    while(!estaVazia(&aux)){
        empilhar(p2, desempilhar(&aux));
    }

}

void copiarSemExcluir(Pilha * p1, Pilha * p2){
    Pilha aux;
    inicializar_pilha(&aux);
    while(!estaVazia(p1)){
        empilhar(&aux, desempilhar(p1));
    }
    while(!estaVazia(&aux)){
        int valor = desempilhar(&aux);
        empilhar(p1, valor);
        empilhar(p2, valor);
    }
    return;
}

int main(){
    Pilha p1;
    inicializar_pilha(&p1);
    imprimePilha(&p1);
    int x = qualTopo(&p1);
    printf("\n\nTOPO: %d", x);
    empilhar(&p1, 5);
    imprimePilha(&p1);
    empilhar(&p1, 10);
    imprimePilha(&p1);
    empilhar(&p1, 15);
    imprimePilha(&p1);
    empilhar(&p1, 20);
    imprimePilha(&p1);
    empilhar(&p1, 25);
    imprimePilha(&p1);
    empilhar(&p1, 30);
    imprimePilha(&p1);

    int y = desempilhar(&p1);
    printf("\n\n%d desempilhado com sucesso\n", y);
    imprimePilha(&p1);
    empilhar(&p1, 35);
    imprimePilha(&p1);
    
    Pilha p2;
    inicializar_pilha(&p2);

    imprimePilha(&p2);
    transferirValores(&p1, &p2);
    printf("\nPILHA 2\n");
    imprimePilha(&p2);
    printf("\nPilha UM\n");
    imprimePilha(&p1);

    Pilha p3;
    inicializar_pilha(&p3);
    inicializar_pilha(&p1);
    printf("\n\nCOPIANDO SEM EXCLUIR\n\n");
    transferirValores(&p2, &p1);
    copiarSemExcluir(&p1, &p3);
    imprimePilha(&p1);
    imprimePilha(&p3);
}