#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

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

// ================= PALINDROMO =================

bool ehPalindromo(char str[]){
   Pilha normal, inversa;
   inicializar(&normal); inicializar(&inversa);

   for(int i = 0; str[i] != '\0'; i++){
    if(str[i] != ' ') empilhar(&normal, str[i]);
   }
   ptrNoPilha aux = normal.topo;
   while(aux != NULL){
    empilhar(&inversa, aux->valor);
    aux = aux->prox;
   }

   while(!estaVazia(&normal) && !estaVazia(&inversa)){
        if(normal.topo->valor != inversa.topo->valor) return false;
        desempilhar(&inversa);
        desempilhar(&normal);
   }
   return true;
}

// ================= MAIN =================

int main(){
    char str1[] = "radar";
    char str2[] = "a grama e amarga";
    char str3[] = "teste";

    printf("\n'%s' -> %s", str1, ehPalindromo(str1) ? "Palindromo" : "Nao eh");
    printf("\n'%s' -> %s", str2, ehPalindromo(str2) ? "Palindromo" : "Nao eh");
    printf("\n'%s' -> %s", str3, ehPalindromo(str3) ? "Palindromo" : "Nao eh");

    return 0;
}