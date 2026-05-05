#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NoPilha{
    char valor;
    struct NoPilha *prox;
}NoPilha;

typedef NoPilha* ptrNoPilha;

typedef struct{
    ptrNoPilha topo;
}Pilha;

// ================= BASICO =================

void inicializar(Pilha *p){
    p->topo = NULL;
}

bool estaVazia(Pilha *p){
    return p->topo == NULL;
}

void empilhar(Pilha *p, char c){
    ptrNoPilha novo = (ptrNoPilha) malloc(sizeof(NoPilha));

    if(novo == NULL){
        printf("\nErro de memoria!\n");
        exit(1);
    }

    novo->valor = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilhar(Pilha *p){
    if(estaVazia(p)){
        printf("\nPilha vazia!\n");
        exit(1);
    }

    ptrNoPilha aux = p->topo;
    char valor = aux->valor;

    p->topo = aux->prox;
    free(aux);

    return valor;
}

char topo(Pilha *p){
    if(estaVazia(p)){
        printf("\nPilha vazia!\n");
        exit(1);
    }

    return p->topo->valor;
}

void printPilha(Pilha *p){
    if(estaVazia(p)){
        printf("\nPilha vazia!\n");
        return;
    }

    printf("\nPilha:\n");
    for(ptrNoPilha aux = p->topo; aux != NULL; aux = aux->prox){
        printf("[ %c ]\n", aux->valor);
    }
}

// ================= VOCE IMPLEMENTA =================

bool verificaPadrao(char str[]){
    Pilha p;
    inicializar(&p);
    int i; 
    for(i = 0; str[i] != 'C' && str[i] != '\0'; i++){
        if(str[i] != 'A' && str[i] != 'B') return false;  
        empilhar(&p, str[i]);
    }

    if(str[i] != 'C') return false;

    i++;

    while(str[i] != '\0'){
        if(estaVazia(&p)) return false;
        if(p.topo->valor != str[i]) return false;
        desempilhar(&p);
        i++;
    }
    return estaVazia(&p);
}

// ================= MAIN =================

int main(){
    char s1[] = "ABABBACABBABA";   // verdadeiro
    char s2[] = "ABABAACABBABA";   // falso
    char s3[] = "ABCBA";           // falso
    char s4[] = "ABCCBA";          // falso

    printf("\n'%s' -> %s", s1, verificaPadrao(s1) ? "Verdadeiro" : "Falso");
    printf("\n'%s' -> %s", s2, verificaPadrao(s2) ? "Verdadeiro" : "Falso");
    printf("\n'%s' -> %s", s3, verificaPadrao(s3) ? "Verdadeiro" : "Falso");
    printf("\n'%s' -> %s", s4, verificaPadrao(s4) ? "Verdadeiro" : "Falso");

    return 0;
}