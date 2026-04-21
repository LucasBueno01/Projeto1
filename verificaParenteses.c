#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>

#define MAX 10

typedef struct Pilha{
    char palavra[MAX];
    int topo;
}pilha;

void inicializar(pilha * p){
    p->topo = 0;
}

bool estaCheia(pilha * p){
    return(p->topo == MAX);
}

bool estaVazia(pilha *p){
    return(p->topo == 0);
}

int tamanhoPilha(pilha *p){
    return(p->topo);
}

void imprimir(pilha * p){
    int i;
    printf("\nIMPRESSAO DA PILHA\n\n");
    for(i=0;i<p->topo;i++)
        printf("[%c]\n",p->palavra[i]);
}

void empilhar(pilha * p, char x){
    if(!estaCheia(p)){
        p->palavra[p->topo] = x;
        p->topo++;
    } else{
        printf("\nPilha cheia!\n");
    }
}

char desempilhar(pilha * p){
    if(!estaVazia(p)){
        p->topo--;
        char valor = p->palavra[p->topo];
        return valor;
    }else{
        printf("\nPilha vazia!\n");
    }
}

char topoPilha(pilha * p){
    char qualTopoReal = p->palavra[p->topo-1];
    return qualTopoReal;
}

bool ehPar(char a, char f){
    return(a == '(' && f == ')') ||
          (a == '[' && f == ']') ||
          (a == '{' && f == '}');
}

bool validarPares(pilha * p, const char* expressao){
    int i, len = strlen(expressao);

    for(i=0;i<len;i++){
        char atual = expressao[i];

        if(atual == '(' || atual == '[' || atual == '{'){
            empilhar(p, atual);
        }else if(atual == ')' || atual == ']' || atual == '}'){
            if(estaVazia(p)){
                return false; //n tem fechamento correspondente
            }
            char abertura = desempilhar(p);
            if(!ehPar(abertura, atual)){
                return false; //pares n sao iguais;
            }
        }
    }
    return estaVazia(p);

}

int main(){
    pilha pil;
    inicializar(&pil);
    char teste1[] = "{[()]}";
    char teste2[] = "([)]";
    char teste3[] = "{[";

    printf("Expressao %s eh: %s\n\n", teste1, validarPares(&pil, teste1) ? "valida" : "invalida");
    inicializar(&pil);
    printf("Expressao %s eh: %s\n\n", teste2, validarPares(&pil, teste2) ? "valida" : "invalida");
    inicializar(&pil);
    printf("Expressao %s eh: %s\n\n", teste3, validarPares(&pil, teste3) ? "valida" : "invalida");
}