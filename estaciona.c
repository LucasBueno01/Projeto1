#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TAM 10

typedef struct Carro{
    int num_carro;
}carro;

typedef struct Pilha{
    carro vetor[TAM];
    int topo;
}pilha;

void inicializap1(pilha * p){
    p->topo = 0;
}
void inicializap2(pilha * p){
    p->topo = 0;
}

bool estaCheiap1(pilha *p){
    return(p->topo == TAM);
}
bool estaCheiap2(pilha *p){
    return(p->topo == TAM);
}
bool estaVaziap1(pilha * p){
    return(p->topo == 0);
}
bool estaVaziap2(pilha * p){
    return(p->topo == 0);
}
void imprime(pilha * p){
    int i;
    printf("\n\nESTACIONAMENTO\n\n");
    for(i=p->topo-1;i>=0;i--) printf("[%d]\n", p->vetor[i].num_carro);
    return;
}

void empilhar(int numero, pilha * p){
    if(estaCheiap1(p)){
        printf("Sem estacionamento!");
        return;
    }else{
        carro c;
        c.num_carro = numero;
        p->vetor[p->topo] = c;
        p->topo++;
    }
}
void empilhar2(pilha * p, pilha *p2){
    if(estaCheiap2(p2)){
        printf("Sem vaga na rua!");
        return;
    }
    if(estaVaziap1(p)){
        printf("Nao ha mais nada para tirar");
        return;
    }
        p->topo--;
        p2->vetor[p2->topo] = p->vetor[p->topo];
        p2->topo++;
    
}
void reempilha(pilha * p, pilha *p2){
    if(estaCheiap1(p)){
        printf("Sem vaga no estacionamento!");
        return;
    }
    if(estaVaziap2(p2)){
        printf("Nao tem mais carros para voltar!");
        return;
    }
        p2->topo--;
        p->vetor[p->topo] = p2->vetor[p2->topo];
        p->topo++;
    
}

int sair(pilha * p, pilha * p2, int num){
    int manobras = 0;
    while((!estaVaziap1(p)) && (p->vetor[p->topo-1].num_carro != num)){
        if(estaCheiap2(p2)) return -1;
        empilhar2(p, p2);
        manobras++;
    }
    
    if(estaVaziap1(p)){
        printf("Carro n ta aqui meo");
        return -1;
    }
    p->topo--;
    manobras++;
    printf("O carro %d SAIU!", p->vetor[p->topo].num_carro);
    while(!estaVaziap2(p2)){
        reempilha(p, p2);
        manobras++;
    }
    return manobras;
}
int main(){
    int qtde;
    pilha pil1;
    pilha pil2;

    inicializap1(&pil1);
    inicializap2(&pil2);
    
    //ative o teste 1 ou 2 comentando o inverso
    //ambos eliminam carro 2 (passível de alteração)

    //teste 1
    /*empilhar(1, &pil1);
    empilhar(2, &pil1);
    empilhar(3, &pil1);
    empilhar(4, &pil1);*/


    //teste2
    printf("\t\tSIMULADOR DE ESTACIONAMENTO\n\n");
    printf("Digite a qtde de carros: ");
    scanf("%d", &qtde);
    for(int i = 1; i<= qtde; i++){
        empilhar(i, &pil1);
    }
    printf("\n\nPilha agora: \n\n");
    imprime(&pil1);



    int qual = sair(&pil1, &pil2, 2);
    printf("\n\n\nO numero de manobras foi: %d\n\n\n", qual);
    imprime(&pil1);
}