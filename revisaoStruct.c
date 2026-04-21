#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
    char nome[40];
    int idade;
    float nota;

} Aluno;

void preencherAluno(Aluno * alunx){
    printf("\nDigite o nome do aluno: ");
    scanf("%[^\n]s", alunx->nome);

    printf("\nDigite a idade do aluno: ");
    scanf("%d", &alunx->idade);

    printf("\nDigite a nota aluno: ");
    scanf("%f", &alunx->nota);
}


void exibirAluno(Aluno aluno1){
    printf("\n\nA idade do aluno eh: %d", aluno1.idade);
    printf("\nA nota do aluno eh: %.2f", aluno1.nota);
    printf("\nO nome do aluno eh: %s", aluno1.nome);
}

int main(){
    Aluno aluno1;
    preencherAluno(&aluno1);
    exibirAluno(aluno1);
    return 0;
}