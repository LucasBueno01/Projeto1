#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define TAM_MAX 20

typedef struct{
    char valores[TAM_MAX];
    int topo;
}Pilha;

void inicializar(Pilha * p){
    p->topo = 0;
}

bool estaVazia(Pilha * p){
    return(p->topo == 0);
}

bool estaCheia(Pilha * p){
    return p->topo == TAM_MAX;
}

void empilhar(Pilha * p, char num){
    if(estaCheia(p)){
        printf("\n\nImpossivel empilhar, pilha cheia!");
        return;
    }
    p->valores[p->topo] = num;
    p->topo++;
}

char desempilhar(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a desempilhar, pilha vazia!");
        exit(1);
    }
    p->topo--;
    char aux = p->valores[p->topo];
    printf("Desempilhando %c!", aux);
    return aux;
}

void printPilha(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nNada a imprimir, pilha vazia");
        return;
    }
    printf("\n\nIMPRIMINDO PILHA:");
    for(int i = p->topo-1; i >= 0; i--){
        printf("\n[ %c ]", p->valores[i]);
    }
}

void qualTopo(Pilha * p){
    if(estaVazia(p)){
        printf("\n\nPilha vazia, nada no topo!");
        return;
    }
    printf("\n\nO topo eh: %c", p->valores[p->topo-1]);
}

void qualTam(Pilha * p){
    printf("\n\nO tamanho eh: %c", p->topo);
}

void verificaString(char texto[20], Pilha * p){
    char i = 0;
    while(texto[i] != '\0'){
        char aux = texto[i];
        if(aux == '{' || aux == '[' || aux == '('){
            empilhar(p, aux);
        }else if(aux == '}' || aux == ']' || aux == ')'){
            if(estaVazia(p)){
                printf("\n\nEntrada inválida, iniciando com fechamento!");
                return;
            }
            char verPar = desempilhar(p);
            if(verPar == '(' && aux == ')'){
                printf("\n\nElementos corretos!");
            } else if(verPar == '[' && aux == ']'){
                printf("\n\nElementos corretos!");
            } else if(verPar == '{' && aux == '}'){
                printf("\n\nElementos corretos!");
            } else{
                printf("\n\n ENTRADA INVALIDA! %c nao fexha par com %c!", verPar, aux);
                return;
            }
        }
        i++;
    }
    if(estaVazia(p)){
        printf("\n\nENTRADA VALIDA");
    } else{
        printf("\n\nENTRADA INVALIDA!");
    }
    return;
}

int main(){
    Pilha p1;
    inicializar(&p1);

    char frase[20] = "{{{[]()}}}";
    verificaString(frase, &p1);
}
